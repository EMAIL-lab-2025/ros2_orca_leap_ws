#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import os
import importlib.resources
from orca_core import OrcaHand
from sensor_msgs.msg import JointState
from std_msgs.msg import Bool
from std_msgs.msg import Header
import time
import math

class OrcahandDriverNode(Node):
    def __init__(self):
        # 初始化orcahand_driver_node
        super().__init__('orcahand_driver_node')
        self.joint_satate_publisher_ = self.create_publisher(JointState,'joint_states',10)
        self.command_subscription = self.create_subscription(
            JointState,
            'keyboard_command',
            self.command_callback,
            10)
        self.torque_command_subscription = self.create_subscription(
            Bool,
            'torque_command',
            self.torque_callback,
            10)
        self.get_logger().info("Listening for commands on /orcahand_command topic.")
        self.get_logger().info('orcahand_driver_node is ready!')

        # 加载orcahand
        try:
            model_path_obj = importlib.resources.files('orca_core') / 'models' / 'orcahand_v1_right'
            model_path = str(model_path_obj)
            self.get_logger().info(f"Successfully located model path at: {model_path}")
        except ModuleNotFoundError:
            self.get_logger().fatal("Could not find the 'orca_core' package. Is it installed correctly?")
            raise
        self.hand = OrcaHand(model_path)

        try:
            success, message = self.hand.connect()
            if not success:
                self.get_logger().info(f"Failed to connect: {message}")
                return 1
            self.get_logger().info("Connected to hand successfully")

            self.hand.init_joints()
            self.torque_state = True
            time.sleep(0.3)
            self.internal_names = self.hand.joint_ids

        except Exception as e:
            self.get_logger().info(f"Error: {str(e)}")
            return 1

        self.read_publish_timer = self.create_timer(0.02, self.read_and_publish_callback)

    def command_callback(self, msg: JointState):
        """接收到指令后的回调函数"""
        if self.torque_state:
            target_positions_deg = {}
            for i, name in enumerate(msg.name):
                target_positions_deg[name] = msg.position[i]
            
            if not target_positions_deg:
                return

            self.get_logger().info(f"Executing command: {target_positions_deg}")
            try:
                # 使用平滑移动
                self.hand.set_joint_pos(target_positions_deg, num_steps=10, step_size=0.025)
            except Exception as e:
                self.get_logger().error(f"Failed to execute command: {e}")
        else:
            self.get_logger().warn("请先输入on开启扭矩控制")

    def torque_callback(self, msg: Bool):
        """接收到指令后的回调函数"""
        if msg.data and not self.torque_state:
            self.hand.enable_torque()
            self.get_logger().info("扭矩控制开启")
            self.torque_state = True
        elif not msg.data and self.torque_state:
            self.hand.disable_torque()
            self.get_logger().info("扭矩控制关闭")
            self.torque_state = False
        elif not msg.data and not self.torque_state:
            self.get_logger().warn("扭矩已经处于关闭状态。")
        else:
            self.get_logger().warn("扭矩已经处于开启状态。")
    def read_and_publish_callback(self,):
        try:
            current_positions_deg = self.hand.get_joint_pos(as_list=True)
            self.get_logger().info(f"DEBUG: {self.internal_names} {current_positions_deg}")
            current_positions_rad = [float(pos * (math.pi / 180.0)) for pos in current_positions_deg]
            js_msg = JointState()
            js_msg.header = Header()
            js_msg.header.stamp = self.get_clock().now().to_msg()
            # 发布时添加前缀
            js_msg.name = ["right_" + name for name in self.internal_names]
            js_msg.position = current_positions_rad
            js_msg.velocity = []
            js_msg.effort = []

            self.joint_satate_publisher_.publish(js_msg)

        except Exception as e:
            self.get_logger().error(f"读取或发布关节信息失败: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = OrcahandDriverNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.hand.disable_torque()
        node.hand.disconnect() 
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
