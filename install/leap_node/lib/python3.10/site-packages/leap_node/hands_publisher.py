#!/home/xingyi/.venvs/leapc/bin/python
import rclpy
from rclpy.node import Node
from leap_msgs.msg import Hands, Hand, Finger, Bone
import leap
import numpy as np


class LeapMotionListener(leap.Listener):
    """
    作为一个专门的事件处理器，当leap库从leap motion服务接收到新的手部追踪数据帧时，
    这个类的实例就会被调用
    """
    def __init__(self, callback):
        super().__init__()
        self.callback = callback

    def on_tracking_event(self, event):
        # 根据 leap 库的设计，当有追踪事件 (TrackingEvent) 发生时，这个方法会被自动调用
        self.callback(event.hands)
        # 执行了在构造函数中传入的 callback 函数，
        # 并将 event 对象中的 hands 属性（一个包含所有被检测到的 Hand 对象的列表）作为参数传递给它。

        # event：这个参数是一个 TrackingEvent 对象实例，
        # 它包含了该追踪帧的所有信息，如时间戳、帧率以及最重要的手部数据列表。


class HandsPublisher(Node):

    def __init__(self):
        super().__init__('hands_publisher_node')
        self.hands_publsiher = self.create_publisher(Hands, 'leap_hands', 10)
        self.connection = leap.Connection()
        self.connection.add_listener(LeapMotionListener(self.handle_hand_data))
        # 把self.handle_hand_data作为回调函数传给LeapMotionListener()

        # self.connection.add_listener(...): 
        # 将这个配置好的监听器实例添加到 connection 对象中。
        # 这样，每当 connection 从设备轮询到追踪事件时，LeapMotionListener 的 on_tracking_event 就会被触发，
        # 接着就会调用 self.handle_hand_data 方法来处理数据。

    def handle_hand_data(self, hands):
        """
        处理从 LeapMotionListener 传来的原始手部数据的核心逻辑。
        它负责数据转换、填充 ROS 消息并最终发布。
        """
        try:
            hands_msg = Hands()
            hands_msg.header.stamp = self.get_clock().now().to_msg()
            hands_msg.header.frame_id = "leap_link"

            for hand in hands:
                #  遍历检测到的每一只手，并开始填充单个 Hand ROS 消息。
                msg = Hand()
                
                # 手的类型判断
                msg.type = "Left" if str(hand.type) == "HandType.Left" else "Right"
                # 判断手的类型。hand.type 是一个 HandType 枚举。
                # 代码将其转换为字符串（例如 "HandType.Left"）进行比较，
                # 然后将 ROS 消息中的 type 字段设置为 "Left" 或 "Right"。

                # 手掌数据
                if hasattr(hand, 'palm') and hand.palm:
                    """
                    Leap Motion 使用的是右手坐标系：
                    Y 轴向上，X 轴向右，Z 轴朝向用户。
                    而 ROS 通常使用 X 轴向前，Y 轴向左，Z 轴向上的坐标系。
                    此处的代码执行了从 Leap 到 ROS 的坐标转换：
                    ROS x = -Leap z
                    ROS y = -Leap x
                    ROS z = Leap y

                    Leap Motion 的位置和速度单位是毫米和毫米/秒，
                    而 ROS 的标准单位是米和米/秒。
                    因此代码中 * 1.0e-3 的部分就是用来将毫米转换为米。
                    """
                    msg.position.x = -hand.palm.position.z * 1.0e-3
                    msg.position.y = -hand.palm.position.x * 1.0e-3
                    msg.position.z = hand.palm.position.y * 1.0e-3
                    msg.velocity.x = -hand.palm.velocity.z * 1.0e-3
                    msg.velocity.y = -hand.palm.velocity.x * 1.0e-3
                    msg.velocity.z = hand.palm.velocity.y * 1.0e-3
                    msg.normal.x = -hand.palm.normal.z
                    msg.normal.y = -hand.palm.normal.x
                    msg.normal.z = hand.palm.normal.y
                    msg.orientation.x = -hand.palm.orientation.z
                    msg.orientation.y = -hand.palm.orientation.x
                    msg.orientation.z = hand.palm.orientation.y
                    msg.orientation.w = hand.palm.orientation.w

                # 抓握和捏取强度
                """
                直接从 hand 对象读取 grab_strength 和 pinch_strength 属性，
                并将其转换为浮点数后存入 ROS 消息中。
                """
                if hasattr(hand, 'grab_strength'):
                    msg.grab_strength = float(hand.grab_strength)
                if hasattr(hand, 'pinch_strength'):
                    msg.pinch_strength = float(hand.pinch_strength)

                # 处理手指数据
                finger_names = ['thumb', 'index', 'middle', 'ring', 'pinky']
                finger_types = [0, 1, 2, 3, 4]  # Thumb, Index, Middle, Ring, Pinky
                
                for finger_name, finger_type in zip(finger_names, finger_types):
                # 使用 zip 同时遍历手指名称和预设的类型 ID。
                
                    if hasattr(hand, finger_name):
                        leap_finger = getattr(hand, finger_name)
                        if leap_finger:
                            finger_msg = Finger()
                            finger_msg.type = finger_type
                            
                            # 指尖位置 - 使用最后一个骨骼的 next_joint 作为指尖
                            if hasattr(leap_finger, 'bones') and leap_finger.bones and len(leap_finger.bones) > 0:
                                tip_bone = leap_finger.bones[-1]  # 最后一个骨骼
                                if hasattr(tip_bone, 'next_joint'):
                                    finger_msg.tip_position.x = -tip_bone.next_joint.z * 1.0e-3
                                    finger_msg.tip_position.y = -tip_bone.next_joint.x * 1.0e-3
                                    finger_msg.tip_position.z = tip_bone.next_joint.y * 1.0e-3
                            
                            # 手指方向 - 从第一个骨骼的 prev_joint 到最后一个骨骼的 next_joint
                            if hasattr(leap_finger, 'bones') and leap_finger.bones and len(leap_finger.bones) > 0:
                                first_bone = leap_finger.bones[0]
                                last_bone = leap_finger.bones[-1]
                                if (hasattr(first_bone, 'prev_joint') and hasattr(last_bone, 'next_joint')):
                                    # 计算方向向量
                                    start = np.array([first_bone.prev_joint.x, first_bone.prev_joint.y, first_bone.prev_joint.z])
                                    end = np.array([last_bone.next_joint.x, last_bone.next_joint.y, last_bone.next_joint.z])
                                    direction = end - start
                                    # 归一化
                                    if np.linalg.norm(direction) > 0:
                                        direction = direction / np.linalg.norm(direction)
                                        finger_msg.direction.x = -direction[2]
                                        finger_msg.direction.y = -direction[0]
                                        finger_msg.direction.z = direction[1]

                            # 骨骼数据
                            if hasattr(leap_finger, 'bones') and leap_finger.bones:
                                for bone_index, bone in enumerate(leap_finger.bones):
                                    bone_msg = Bone()
                                    
                                    # 使用骨骼在数组中的索引作为类型
                                    bone_msg.type = bone_index
                                    
                                    # 骨骼关节点
                                    if hasattr(bone, 'prev_joint'):
                                        bone_msg.prev_joint.x = -bone.prev_joint.z * 1.0e-3
                                        bone_msg.prev_joint.y = -bone.prev_joint.x * 1.0e-3
                                        bone_msg.prev_joint.z = bone.prev_joint.y * 1.0e-3
                                    
                                    if hasattr(bone, 'next_joint'):
                                        bone_msg.next_joint.x = -bone.next_joint.z * 1.0e-3
                                        bone_msg.next_joint.y = -bone.next_joint.x * 1.0e-3
                                        bone_msg.next_joint.z = bone.next_joint.y * 1.0e-3
                                    
                                    # 计算骨骼方向 (从 prev_joint 到 next_joint)
                                    if hasattr(bone, 'prev_joint') and hasattr(bone, 'next_joint'):
                                        start = np.array([bone.prev_joint.x, bone.prev_joint.y, bone.prev_joint.z])
                                        end = np.array([bone.next_joint.x, bone.next_joint.y, bone.next_joint.z])
                                        direction = end - start
                                        if np.linalg.norm(direction) > 0:
                                            direction = direction / np.linalg.norm(direction)
                                            bone_msg.direction.x = -direction[2]
                                            bone_msg.direction.y = -direction[0]
                                            bone_msg.direction.z = direction[1]
                                    
                                    finger_msg.bones.append(bone_msg)
                            
                            msg.fingers.append(finger_msg)
                
                hands_msg.hands.append(msg)

            # 发布消息
            if hands_msg.hands:
                self.hands_publsiher.publish(hands_msg)
                self.get_logger().info(f"发布了 {len(hands_msg.hands)} 只手的数据", throttle_duration_sec=2.0)

        except Exception as e:
            self.get_logger().error(f"处理手部数据时发生错误: {e}")
            import traceback
            traceback.print_exc()

    def run(self):
        with self.connection.open():
            self.connection.set_tracking_mode(leap.TrackingMode.Desktop)
            rclpy.spin(self)

def main(args=None):
    rclpy.init()
    hands_publisher = HandsPublisher()
    hands_publisher.run()
    hands_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
