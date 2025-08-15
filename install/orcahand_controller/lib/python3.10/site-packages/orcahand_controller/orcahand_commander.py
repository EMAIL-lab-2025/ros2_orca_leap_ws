#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import importlib.resources
from sensor_msgs.msg import JointState
from std_msgs.msg import Bool
from std_msgs.msg import Header
import os
import yaml 

# 用于读取YAML文件的工具函数，类似于 orca_core.utils 中的功能
def read_yaml(file_path):
    with open(file_path, 'r') as file:
        return yaml.safe_load(file)

class KeyboardCommanderNode(Node):
    def __init__(self):
        super().__init__('orcahand_commander_node')
        # 正确地定位模型路径并加载配置文件
        try:
            model_path_obj = importlib.resources.files('orca_core') / 'models' / 'orcahand_v1_right'
            self.model_path = str(model_path_obj)
            self.config_path = os.path.join(self.model_path, "config.yaml")
            self.config = read_yaml(self.config_path) # 加载配置
            self.get_logger().info(f"成功定位模型路径于: {self.model_path}")
        except (ModuleNotFoundError, FileNotFoundError) as e:
            self.get_logger().fatal(f"无法找到或加载配置文件: {e}")
            raise

        self.command_publisher_ = self.create_publisher(JointState, 'keyboard_command', 10)
        self.torque_command_publisher = self.create_publisher(Bool, 'torque_command', 10)
        self.get_logger().info("请输入 'fist'、'neutral' 或类似 'index_mcp=30' 的指令。")
        self.get_logger().info("使用 'on'/'off' 控制扭矩。") 

    def process_keyboard_input(self):
        """主循环，读取并处理键盘输入"""
        while rclpy.ok():
            try:
                command_str = input("请输入指令 > ")
                if not command_str:
                    continue
                
                js_msg = JointState()
                js_msg.header.stamp = self.get_clock().now().to_msg()
                torque_msg = Bool()
                parts = command_str.split('=')

                if len(parts) == 1:
                    command = parts[0].strip().lower()

                    if command == 'on':
                        torque_msg.data = True
                        self.torque_command_publisher.publish(torque_msg)
                        self.get_logger().info("发送 'on' 指令...")

                    elif command == 'off':
                        torque_msg.data = False
                        self.torque_command_publisher.publish(torque_msg)
                        self.get_logger().info("发送 'off' 指令...")

                    elif command == 'fist':
                        js_msg.name = ['thumb_mcp', 'thumb_pip', 'index_mcp', 'index_pip', 'middle_mcp', 'middle_pip', 'ring_mcp', 'ring_pip', 'pinky_mcp', 'pinky_pip']
                        js_msg.position = [25.0, 30.0, 20.0, 30.0, 20.0, 30.0, 20.0, 30.0, 20.0, 30.0]
                        self.get_logger().info("发送 'fist' 指令。")
                        self.command_publisher_.publish(js_msg)
                    elif command == 'neutral':
                        neutral_pos_dict = self.config.get('neutral_position', {})
                        js_msg.name = list(neutral_pos_dict.keys())
                        js_msg.position = [float(pos) for pos in neutral_pos_dict.values()]
                        self.get_logger().info("发送 'neutral' 指令。")
                        self.command_publisher_.publish(js_msg)
                    else:
                        self.get_logger().warn(f"未知单指令: '{command}'")

                elif len(parts) == 2:
                    joint_name = parts[0].strip()
                    position_str = parts[1].strip()
                    try:
                        position = float(position_str)
                        js_msg.name = [joint_name]
                        js_msg.position = [position]
                        self.get_logger().info(f"发送指令: {joint_name} -> {position}")
                        self.command_publisher_.publish(js_msg)
                    except ValueError:
                        self.get_logger().warn(f"位置 '{position_str}' 不是一个有效的数字。")
                
                else:
                    self.get_logger().warn("命令格式错误。")
            
            except (KeyboardInterrupt, EOFError):
                break

def main(args=None):
    rclpy.init(args=args)
    node = KeyboardCommanderNode()
    try:
        node.process_keyboard_input()
    except (KeyboardInterrupt, EOFError):
        pass
    finally:
        node.get_logger().info('正在关闭键盘指令节点...')
        rclpy.shutdown()

if __name__ == "__main__":
    main()