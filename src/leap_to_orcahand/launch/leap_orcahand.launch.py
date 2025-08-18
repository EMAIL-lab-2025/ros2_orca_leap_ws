from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    orcahand_display_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            get_package_share_directory('orcahand_description'), 
            '/launch/display_orcahand.launch.py' # 您的显示启动文件路径
        ])
    )

    leap_publisher_node = Node(
        package='leap_node',          
        executable='hands_publisher',
        name='hands_publisher_node',
        output='screen'
    )
    
    leap_to_orcahand_node = Node(
        package='orcahand_controller', 
        executable='leap_to_orcahand',
        name='leap_to_orcahand_node',
        output='screen'
    )

    return LaunchDescription([
        orcahand_display_launch,
        leap_publisher_node,
        leap_to_orcahand_node
    ])