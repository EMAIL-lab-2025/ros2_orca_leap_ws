import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/xingyi/ros2_orca_leap/ros2_orca_leap_ws/install/orca_core'
