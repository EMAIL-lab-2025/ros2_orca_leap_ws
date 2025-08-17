#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import numpy as np
import math
from leap_msgs.msg import Hands, Hand, Finger, Bone
from sensor_msgs.msg import JointState

# ================== 全局配置 ==================

# 定义了每个关节的活动范围（Range of Motion），单位为度。
# 用于后续将计算出的角度限制在机械臂的安全活动范围内。
JOINT_ROMS = {
    "thumb_mcp": [-50, 50],
    "thumb_abd": [-22, 42],
    "thumb_pip": [-12, 110],
    "thumb_dip": [-20, 112],
    "index_abd": [-37, 40],
    "middle_abd": [-37, 37],
    "ring_abd": [-37, 45],
    "pinky_abd": [-52, 37],
}

# Leap Motion内部的手指类型ID到具名字符串的映射。
FINGER_TYPE_MAP = {0: "Thumb", 1: "Index", 2: "Middle", 3: "Ring", 4: "Pinky"}

# 将手指名称和关节类型映射到OrcaHand驱动中对应的关节名称。
JOINT_MAPPING = {
    "Thumb": {"mcp": "thumb_mcp", "pip": "thumb_pip", "dip": "thumb_dip", "abd": "thumb_abd"},
    "Index": {"mcp": "index_mcp", "pip": "index_pip", "abd": "index_abd"},
    "Middle": {"mcp": "middle_mcp", "pip": "middle_pip", "abd": "middle_abd"},
    "Ring": {"mcp": "ring_mcp", "pip": "ring_pip", "abd": "ring_abd"},
    "Pinky": {"mcp": "pinky_mcp", "pip": "pinky_pip", "abd": "pinky_abd"},
}

# 定义了激活控制的抓握强度阈值。左手抓握强度超过此值时，右手开始映射控制。
GRAB_STRENGTH_THRESHOLD = 0.8

# 按手指配置ABD（手指开合）方向的符号。
# 有时传感器数据或坐标系定义可能导致开合方向相反，可在此处通过乘以-1.0来快速校正。
FINGER_ABD_SIGN = {
    "Thumb": 1.0,
    "Index": 1.0,
    "Middle": 1.0,
    "Ring": 1.0,
    "Pinky": 1.0,
}

# 新增：四根手指MCP和PIP关节的映射关系
FINGER_JOINT_MAPPINGS = {
    "Index": {
        "mcp": {"input_range": [-27.3, 74], "output_range": [-20, 95]},
        "pip": {"input_range": [-5, 27], "output_range": [-20, 105]}
    },
    "Middle": {
        "mcp": {"input_range": [-27.3, 74], "output_range": [-20, 90]},
        "pip": {"input_range": [5, 27], "output_range": [-20, 107]}
    },
    "Ring": {
        "mcp": {"input_range": [-27.3, 74], "output_range": [-19, 90]},
        "pip": {"input_range": [7, 27], "output_range": [-19, 107]}
    },
    "Pinky": {
        "mcp": {"input_range": [-27.3, 74], "output_range": [-20, 95]},
        "pip": {"input_range": [23, 27], "output_range": [-20, 90]}
    }
}

# 新增：大拇指PIP和DIP关节的映射关系
THUMB_JOINT_MAPPINGS = {
    "pip": {"input_range": [3, 31], "output_range": [-10, 110]},
    "dip": {"input_range": [9, 38], "output_range": [-10, 110]}
}

# 新增：手腕关节的映射关系
WRIST_MAPPING = {
    "flex": {"input_range": [58, 128], "output_range": [40, -30]}
}

# 定义右手抓握时的预设关节位置
GRIP_JOINT_POSITIONS = {
    "index_abd": 4.7,
    "index_mcp": 95,
    "index_pip": 105,
    "middle_abd": -2,
    "middle_mcp": 90,
    "middle_pip": 107,
    "ring_abd": -3,
    "ring_mcp": 90,
    "ring_pip": 107,
    "pinky_abd": -20,
    "pinky_mcp": 95,
    "pinky_pip": 90
}

# ================== 辅助数学函数 ==================

def _np(v):
    """
    一个便捷的转换函数。它接收一个ROS消息中的三维向量对象
    （如geometry_msgs/Point或Vector3，它们有.x, .y, .z属性），并将其转换成一个NumPy数组，
    以便进行后续的向量数学运算。
    """
    return np.array([v.x, v.y, v.z], dtype=float)

def _safe_normalize(v, eps=1e-8):
    """
    "安全"的向量归一化函数，用于将任意向量转换为单位向量（长度为1）。
    
    n = np.linalg.norm(v): 计算向量v的长度（范数）。
    if n < eps:: 检查向量长度是否非常接近于零（小于一个极小值eps）。这可以防止除以零的错误。
    return np.array([0, 0, 1.0]): 如果向量是零向量，无法归一化，就返回一个默认的单位向量（这里是Z轴正方向），避免程序崩溃。
    return v / n: 如果向量长度正常，就用向量的每个分量除以它的长度，得到一个长度为1的单位向量。
    """
    n = np.linalg.norm(v)
    if n < eps:
        return np.array([0, 0, 1.0])
    return v / n

def _clamp(x, lo, hi):
    """
    限制函数，将输入值x"夹"在最小值lo和最大值hi之间。
    确保最终发送给机械手的关节角度始终在其安全的活动范围内。
    """
    return lo if x < lo else hi if x > hi else x

def angle_between(v1, v2):
    """
    计算两个向量之间夹角的函数（返回弧度）。

    a = _safe_normalize(v1), b = _safe_normalize(v2): 首先将两个输入向量归一化，确保它们是单位向量。
    np.dot(a, b): 计算两个单位向量的点积。根据线性代数，单位向量的点积等于它们之间夹角的余弦值 (cos theta)。
    np.clip(..., -1.0, 1.0): 由于浮点数计算可能存在微小的精度误差，点积结果可能会略微超出[-1.0, 1.0]的范围（例如1.0000001），这会导致acos函数数学错误。clip函数将结果强制"夹"回这个范围。
    return math.acos(dot): 计算点积结果的反余弦值，从而得到两个向量之间的夹角（以弧度为单位）。
    """
    a = _safe_normalize(v1)
    b = _safe_normalize(v2)
    dot = float(np.clip(np.dot(a, b), -1.0, 1.0))
    return math.acos(dot)

def _project_on_plane(v, normal):
    """
    将向量v投影到一个由法向量normal定义的平面上的函数。

    n = _safe_normalize(normal): 确保法向量是单位向量。
    np.dot(v, n): 计算v在n方向上的投影的长度。
    np.dot(v, n) * n: 得到v在n方向上的投影向量（即v垂直于平面的分量）。
    v - ...: 从原始向量v中减去它垂直于平面的分量，剩下的就是v平行于平面的分量，即v在该平面上的投影。
    """
    n = _safe_normalize(normal)
    return v - np.dot(v, n) * n

def signed_angle_on_plane(v, ref, normal):
    """
    计算有符号平面夹角的核心函数，用于计算手指开合（ABD）角度。

    v_p = ..., r_p = ...: 将输入向量v和参考向量ref都投影到由normal定义的平面上，并归一化。
    unsigned = angle_between(v_p, r_p): 计算两个投影向量之间的"无符号"夹角（总是正值）。
    sign = np.sign(np.dot(np.cross(r_p, v_p), n)): 这是确定符号的关键。
    np.cross(r_p, v_p): 计算两个投影向量的叉积。根据右手定则，叉积结果向量的方向垂直于这两个向量构成的平面，其方向（向上或向下）取决于v_p相对于r_p是顺时针还是逆时针。
    np.dot(..., n): 将叉积结果与平面的法向量n进行点积。如果叉积方向与n相同，点积为正；如果相反，点积为负。
    np.sign(...): 提取点积结果的符号（+1, -1 或 0）。
    return math.degrees(unsigned) * float(sign): 将无符号角度（弧度）转换为度，再乘以刚刚得到的符号，最终得到有方向的角度值。
    """
    n = _safe_normalize(normal)
    v_p = _safe_normalize(_project_on_plane(v, n))
    r_p = _safe_normalize(_project_on_plane(ref, n))
    unsigned = angle_between(v_p, r_p)
    sign = np.sign(np.dot(np.cross(r_p, v_p), n))
    return math.degrees(unsigned) * float(sign)

def get_valid_bone_direction(bone):
    """
    获取有效的骨骼方向向量。
    优先使用骨骼的两个关节点（prev_joint, next_joint）来计算方向。
    如果两个关节点位置重合（距离过近），则尝试使用骨骼消息中自带的direction字段作为备选。
    """
    prev = _np(bone.prev_joint)
    next_joint = _np(bone.next_joint)
    
    if np.linalg.norm(next_joint - prev) < 1e-6:
        dir_vec = _np(bone.direction)
        if np.linalg.norm(dir_vec) > 1e-6:
            return _safe_normalize(dir_vec)
        else:
            return None
    
    return _safe_normalize(next_joint - prev)

def calculate_proximal_plane_normal(hand):
    """
    计算四根手指Proximal骨骼共面的平面法向量
    """
    try:
        # 获取四根手指（除大拇指外）的Proximal骨骼方向
        proximal_directions = []
        for finger in hand.fingers:
            if finger.type in [1, 2, 3, 4] and len(finger.bones) >= 2:  # Index, Middle, Ring, Pinky
                proximal_dir = get_valid_bone_direction(finger.bones[1])  # Proximal bone
                if proximal_dir is not None:
                    proximal_directions.append(proximal_dir)
        
        if len(proximal_directions) >= 2:
            # 使用前两个方向向量计算叉积得到法向量
            v1 = proximal_directions[0]
            v2 = proximal_directions[1]
            normal = _safe_normalize(np.cross(v1, v2))
            return normal
        else:
            return None
    except:
        return None

def calculate_wrist_angle(hand, palm_forward, palm_normal):
    """
    计算手腕角度
    """
    if hand.arm and hand.arm.direction:
        # 1. 获取参考向量
        arm_direction = _np(hand.arm.direction)
        # side_vector 用于定义旋转平面 (手掌向前向量与手掌法向量的叉积)
        side_vector = _safe_normalize(np.cross(palm_forward, palm_normal))
        
        # 2. 计算有符号角度 (v=被测向量, ref=参考0度向量, normal=旋转平面法向量)
        wrist_angle = signed_angle_on_plane(palm_forward, arm_direction, side_vector)
        
        # 3. 应用映射关系
        mapping = WRIST_MAPPING["flex"]
        mapped_wrist_angle = np.interp(wrist_angle, mapping["input_range"], mapping["output_range"])
        
        return mapped_wrist_angle
    
    return None

# ================== 核心计算函数 ==================

def calculate_finger_angles(finger, hand, palm_forward, palm_normal, abd_zero_offsets=None, grip_mode=False):
    """
    计算单根手指的所有关节角度。
    此函数是所有映射逻辑的核心，它处理所有手指的常规关节，并包含大拇指MCP关节的特殊处理逻辑。
    
    参数:
        finger: 当前要计算的单根手指的ROS消息对象。
        hand: 包含所有手指的完整手的ROS消息对象（为计算大拇指MCP提供必要上下文）。
        palm_forward: 代表手掌向前方向的参考向量。
        palm_normal: 代表手掌法线方向的参考向量。
        abd_zero_offsets: 手指开合角度的零点偏移量，用于校准。
        grip_mode: 是否处于抓握模式
        
    返回:
        一个字典，键是关节名称，值是计算出的角度（单位：度）。
    """
    if len(finger.bones) < 2:
        return {}

    fname = FINGER_TYPE_MAP.get(finger.type, "Unknown")
    if fname not in JOINT_MAPPING:
        return {}

    angles = {}
    
    # 如果是抓握模式，直接返回预设位置
    if grip_mode and fname != "Thumb":
        j_abd = JOINT_MAPPING[fname].get("abd")
        j_mcp = JOINT_MAPPING[fname].get("mcp")
        j_pip = JOINT_MAPPING[fname].get("pip")
        
        if j_abd and j_abd in GRIP_JOINT_POSITIONS:
            angles[j_abd] = GRIP_JOINT_POSITIONS[j_abd]
        if j_mcp and j_mcp in GRIP_JOINT_POSITIONS:
            angles[j_mcp] = GRIP_JOINT_POSITIONS[j_mcp]
        if j_pip and j_pip in GRIP_JOINT_POSITIONS:
            angles[j_pip] = GRIP_JOINT_POSITIONS[j_pip]
        
        return angles
    
    # --- 1. 获取所有骨骼的有效方向向量 ---
    valid_dirs = [get_valid_bone_direction(bone) for bone in finger.bones]
    non_none_dirs = [d for d in valid_dirs if d is not None]
    if len(non_none_dirs) < 1:
        return {}
    
    # --- 计算侧面向量，用于手指弯曲角度的有符号计算 ---
    side_vector = _safe_normalize(np.cross(palm_forward, palm_normal))
    
    # --- 计算Proximal共面平面法向量，用于PIP角度计算 ---
    proximal_plane_normal = calculate_proximal_plane_normal(hand)
    if proximal_plane_normal is None:
        proximal_plane_normal = side_vector  # 备选方案
    
    # --- 2. 计算ABD（手指开合）角度 ---
    if fname != "Thumb":
        abd_vec = None
        if len(valid_dirs) >= 2 and valid_dirs[1] is not None:
            abd_vec = valid_dirs[1]  # 优先使用近节指骨（Proximal Phalanx）
        elif len(valid_dirs) >= 3 and valid_dirs[2] is not None:
            abd_vec = valid_dirs[2]  # 备选使用中节指骨（Intermediate Phalanx）

        if abd_vec is not None:
            abd_angle = signed_angle_on_plane(abd_vec, palm_forward, palm_normal)
            abd_angle *= FINGER_ABD_SIGN.get(fname, 1.0)
            # abd_angle *= 1.1

            if abd_zero_offsets is not None:
                offset = abd_zero_offsets.get(fname, 0.0)
                abd_angle += offset

            j_abd = JOINT_MAPPING[fname].get("abd")
            if j_abd in JOINT_ROMS:
                lo, hi = JOINT_ROMS[j_abd]
                angles[j_abd] = _clamp(abd_angle, lo, hi)
    else:
        mcp_vec = None
        if len(valid_dirs) >= 1 and valid_dirs[0] is not None:
            mcp_vec = valid_dirs[0]  # 优先使用近节指骨（Proximal Phalanx）
        elif len(valid_dirs) >= 2 and valid_dirs[1] is not None:
            mcp_vec = valid_dirs[1]  # 备选使用中节指骨（Intermediate Phalanx）

        if mcp_vec is not None:
            mcp_angle = signed_angle_on_plane(mcp_vec, palm_forward, palm_normal)
            mcp_angle = np.interp(mcp_angle, [-40,0 ], [-50, 50])

            j_mcp = JOINT_MAPPING[fname].get("mcp")
            if j_mcp in JOINT_ROMS:
                lo, hi = JOINT_ROMS[j_mcp]
                angles[j_mcp] = _clamp(mcp_angle, lo, hi)

    # --- 3. 计算常规弯曲角度 (MCP/PIP/DIP) ---
    # 通过计算相邻骨骼之间的夹角来得到关节弯曲度
    valid_pairs = []
    for i in range(len(valid_dirs) - 1):
        if valid_dirs[i] is not None and valid_dirs[i + 1] is not None:
            valid_pairs.append((valid_dirs[i], valid_dirs[i + 1]))
    
    if fname != "Thumb":
        # 对于非大拇指的手指，使用新的映射逻辑
        if len(valid_pairs) >= 1:
            # 使用有符号角度计算MCP弯曲
            mcp_angle = signed_angle_on_plane(valid_pairs[0][1], valid_pairs[0][0], side_vector)
            
            if fname in FINGER_JOINT_MAPPINGS:
                mapping = FINGER_JOINT_MAPPINGS[fname]["mcp"]
                mcp_angle = np.interp(mcp_angle, mapping["input_range"], mapping["output_range"])
            
            j_mcp = JOINT_MAPPING[fname].get("mcp")
            if j_mcp:
                angles[j_mcp] = mcp_angle

        if len(valid_pairs) >= 2:
            # 使用Proximal共面平面法向量计算PIP弯曲
            pip_angle = signed_angle_on_plane(valid_pairs[1][1], valid_pairs[1][0], proximal_plane_normal)
            
            if fname in FINGER_JOINT_MAPPINGS:
                mapping = FINGER_JOINT_MAPPINGS[fname]["pip"]
                pip_angle = np.interp(pip_angle, mapping["input_range"], mapping["output_range"])
            
            j_pip = JOINT_MAPPING[fname].get("pip")
            if j_pip:
                angles[j_pip] = pip_angle

    else:
        
        # 计算大拇指的PIP和DIP关节
        j_abd = JOINT_MAPPING[fname].get("abd")
        angles[j_abd] = 33
        if len(valid_pairs) >= 1:
            pip_angle = math.degrees(angle_between(valid_pairs[0][0], valid_pairs[0][1]))
            # 使用新的映射逻辑
            mapping = THUMB_JOINT_MAPPINGS["pip"]
            mapped_pip_angle = np.interp(pip_angle, mapping["input_range"], mapping["output_range"])
            
            j_pip = JOINT_MAPPING[fname].get("pip")
            if j_pip:
                angles[j_pip] = mapped_pip_angle

        if len(valid_pairs) >= 2:
            dip_angle = math.degrees(angle_between(valid_pairs[1][0], valid_pairs[1][1]))
            # 使用新的映射逻辑
            mapping = THUMB_JOINT_MAPPINGS["dip"]
            mapped_dip_angle = np.interp(dip_angle, mapping["input_range"], mapping["output_range"])
            
            j_dip = JOINT_MAPPING[fname].get("dip")
            if j_dip:
                angles[j_dip] = mapped_dip_angle
        
    return angles

# ================== ROS 2 节点定义 ==================

class LeapToOrcahandNode(Node):
    """
    ROS 2节点，负责订阅Leap Motion数据，进行坐标和角度转换，
    并最终发布为OrcaHand可以接收的JointState指令。
    """
    def __init__(self):
        """节点初始化"""
        super().__init__('leap_to_orcahand_node')
        
        # 订阅来自Leap Motion发布器的话题 /leap_hands
        self.leap_sub = self.create_subscription(Hands, 'leap_hands', self.leap_cb, 10)
        
        # 创建发布器，用于发布控制OrcaHand的指令到 /keyboard_command 话题
        self.pub = self.create_publisher(JointState, 'keyboard_command', 10)
        
        # 控制使能标志位，默认为关闭
        self.control_enabled = False
        self.get_logger().info("Leap→OrcaHand 映射节点启动")
        
        # 用于低通滤波的变量，alpha值越小，平滑效果越明显
        self.prev_angles = {}
        self.alpha = 0.35
        
        # 用于存储手指开合角度的零点偏移
        self.abd_zero_offsets = {"Thumb": 0.0, "Index": 7.0, "Middle": -13.0, "Ring": -21.8, "Pinky": -47.6}

    def leap_cb(self, msg: Hands):
        """
        接收到Leap Motion手部数据的回调函数，包含主要的控制逻辑。
        """
        left, right = None, None
        for h in msg.hands:
            if getattr(h, 'type', '') == "Left":
                left = h
            elif getattr(h, 'type', '') == "Right":
                right = h

        # --- 控制激活/暂停逻辑 ---
        # 使用左手的抓握强度来控制是否激活对右手的映射
        if left:
            if left.grab_strength > GRAB_STRENGTH_THRESHOLD and not self.control_enabled:
                self.control_enabled = True
                self.get_logger().info("控制激活")
            elif left.grab_strength < GRAB_STRENGTH_THRESHOLD and self.control_enabled:
                self.control_enabled = False
                self.get_logger().info("控制暂停")

        # 如果未激活或未检测到右手，则不执行后续操作
        if not self.control_enabled or right is None:
            return

        # 检查右手抓握强度，判断是否进入抓握模式
        grip_mode = right.grab_strength > 0.9

        # --- 计算与发布逻辑 ---
        # 1. 建立用于计算常规角度的参考坐标系
        palm_normal = _np(right.normal)
        palm_forward = np.array([0.0, 0.0, 1.0], dtype=float)
        for finger in right.fingers:
            if finger.type == 2 and len(finger.bones) >= 1:
                direction = get_valid_bone_direction(finger.bones[0])
                if direction is not None:
                    palm_forward = _safe_normalize(_project_on_plane(direction, palm_normal))
                    break

        # 2. 遍历所有手指，调用核心函数计算关节角度
        js = JointState()
        js.header.stamp = self.get_clock().now().to_msg()
        names, positions = [], []
        current_frame_angles = {}

        # 计算手腕角度
        wrist_angle = calculate_wrist_angle(right, palm_forward, palm_normal)
        if wrist_angle is not None:
            current_frame_angles["wrist"] = wrist_angle

        for finger in right.fingers:
            # 将右手对象'right'传入，为计算大拇指提供上下文
            angles = calculate_finger_angles(finger, right, palm_forward, palm_normal, self.abd_zero_offsets , grip_mode)
            for joint_name, angle in angles.items():
                current_frame_angles[joint_name] = float(angle)

        # 3. 对计算出的所有角度进行低通滤波，使运动更平滑（抓握模式下不进行滤波）
        for jn, val in current_frame_angles.items():
            if grip_mode:
                # 抓握模式下直接使用预设值，不进行滤波
                filtered = val
            else:
                if jn in self.prev_angles:
                    filtered = self.alpha * val + (1.0 - self.alpha) * self.prev_angles[jn]
                else:
                    filtered = val
            self.prev_angles[jn] = filtered
            names.append(jn)
            positions.append(filtered)

        # 4. 发布最终的JointState消息
        if names:
            js.name = names
            js.position = positions
            self.pub.publish(js)
            
            # 调试输出，方便观察发布的指令
            pos_int = [int(p) for p in positions]
            joint_dict = dict(zip(names, pos_int))
            # self.get_logger().info(f"发布关节命令: {joint_dict}", throttle_duration_sec=0.2)

def main(args=None):
    """主函数，ROS 2节点的标准入口点。"""
    rclpy.init(args=args)
    node = LeapToOrcahandNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()