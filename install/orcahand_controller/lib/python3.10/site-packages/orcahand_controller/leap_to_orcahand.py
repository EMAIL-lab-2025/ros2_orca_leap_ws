#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import numpy as np
import math
from leap_msgs.msg import Hands, Hand, Finger, Bone
from sensor_msgs.msg import JointState


# ================== 配置 ==================
JOINT_ROMS = {
    "thumb_mcp": [-50, 50],
    "thumb_abd": [-22, 42],
    "thumb_pip": [-12, 110],
    "thumb_dip": [-20, 112],
    "index_abd": [-37, 40],
    "index_mcp": [-20, 95],
    "index_pip": [-20, 108],
    "middle_abd": [-37, 37],
    "middle_mcp": [-20, 91],
    "middle_pip": [-20, 107],
    "ring_abd": [-37, 45],
    "ring_mcp": [-20, 91],
    "ring_pip": [-20, 107],
    "pinky_abd": [-52, 37],
    "pinky_mcp": [-20, 98],
    "pinky_pip": [-20, 108],
}

FINGER_TYPE_MAP = {0: "Thumb", 1: "Index", 2: "Middle", 3: "Ring", 4: "Pinky"}

JOINT_MAPPING = {
    "Thumb": {"mcp": "thumb_mcp", "pip": "thumb_pip", "dip": "thumb_dip", "abd": "thumb_abd"},
    "Index": {"mcp": "index_mcp", "pip": "index_pip", "abd": "index_abd"},
    "Middle": {"mcp": "middle_mcp", "pip": "middle_pip", "abd": "middle_abd"},
    "Ring": {"mcp": "ring_mcp", "pip": "ring_pip", "abd": "ring_abd"},
    "Pinky": {"mcp": "pinky_mcp", "pip": "pinky_pip", "abd": "pinky_abd"},
}

# 定义了激活控制的抓握强度
GRAB_STRENGTH_THRESHOLD = 0.8

# 按手指配置ABD方向的符号（必要时可在此调优）
FINGER_ABD_SIGN = {
    "Thumb": 1.0,
    "Index": 1.0,
    "Middle": 1.0,
    "Ring": 1.0,
    "Pinky": 1.0,
}


def _np(v):
    """
    一个便捷的转换函数。它接收一个ROS消息中的三维向量对象
    （如geometry_msgs/Point或Vector3，它们有.x, .y, .z属性），并将其转换成一个NumPy数组，
    以便进行后续的数学运算。
    """
    return np.array([v.x, v.y, v.z], dtype=float)

def _safe_normalize(v, eps=1e-8):
    """
    “安全”的向量归一化函数。

    n = np.linalg.norm(v): 计算向量v的长度（范数）。
    if n < eps:: 检查向量长度是否非常接近于零（小于一个极小值eps）。这可以防止除以零的错误。
    return np.array([0, 0, 1.0]): 如果向量是零向量，无法归一化，就返回一个默认的单位向量（这里是Z轴正方向），避免程序崩溃。
    return v / n: 如果向量长度正常，就用向量的每个分量除以它的长度，得到一个长度为1的单位向量。
    """
    n = np.linalg.norm(v)
    if n < eps:
        return np.array([0, 0, 1.0])  # 返回默认方向
    return v / n

def _clamp(x, lo, hi):
    """
    限制函数，确保发送的角度值始终在范围内
    """
    return lo if x < lo else hi if x > hi else x

def angle_between(v1, v2):
    """
    计算两个向量之间夹角的函数（返回弧度）。

    a = _safe_normalize(v1), b = _safe_normalize(v2): 首先将两个输入向量归一化，确保它们是单位向量。
    np.dot(a, b): 计算两个单位向量的点积。根据线性代数，单位向量的点积等于它们之间夹角的余弦值 (cos theta)。
    np.clip(..., -1.0, 1.0): 由于浮点数计算可能存在微小的精度误差，点积结果可能会略微超出[-1.0, 1.0]的范围（例如1.0000001），这会导致acos函数数学错误。clip函数将结果强制“夹”回这个范围。
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
    计算有符号平面夹角的核心函数，用于计算手指开合角度。

    v_p = ..., r_p = ...: 将输入向量v和参考向量ref都投影到由normal定义的平面上，并归一化。
    unsigned = angle_between(v_p, r_p): 计算两个投影向量之间的“无符号”夹角（总是正值）。
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
    """获取有效的骨骼方向"""
    prev = _np(bone.prev_joint)
    next_joint = _np(bone.next_joint)
    
    # 检查关节点是否相同
    if np.linalg.norm(next_joint - prev) < 1e-6:
        # 如果关节点相同，尝试使用direction字段
        dir_vec = _np(bone.direction)
        if np.linalg.norm(dir_vec) > 1e-6:
            return _safe_normalize(dir_vec)
        else:
            return None
    
    # 使用关节点计算方向
    return _safe_normalize(next_joint - prev)

def calculate_finger_angles(finger, palm_forward, palm_normal, abd_zero_offsets=None):
    """计算单个手指的角度（带平面投影的ABD、有符号角与零点校准）。"""
    if len(finger.bones) < 2:
        return {}

    fname = FINGER_TYPE_MAP.get(finger.type, "Unknown")
    if fname not in JOINT_MAPPING:
        return {}

    angles = {}
    valid_dirs = []

    for bone in finger.bones:
        direction = get_valid_bone_direction(bone)
        if direction is not None:
            valid_dirs.append(direction)
        else:
            valid_dirs.append(None)

    non_none_dirs = [d for d in valid_dirs if d is not None]
    if len(non_none_dirs) < 1:
        return {}

    # 选择用于ABD的方向：优先近节
    abd_vec = None
    
    if len(valid_dirs) >= 2 and valid_dirs[1] is not None:
        abd_vec = valid_dirs[1]
    elif len(valid_dirs) >= 3 and valid_dirs[2] is not None:
        abd_vec = valid_dirs[2]

    if abd_vec is not None:
        abd_angle = signed_angle_on_plane(abd_vec, palm_forward, palm_normal)
        abd_angle *= FINGER_ABD_SIGN.get(fname, 1.0)
        # 拇指缩放略小，避免过冲
        if fname == "Thumb":
            abd_angle *= 1.0
        # 其他手指轻微缩放，增强可用行程
        else:
            abd_angle *= 1.0

        # 零点校准
        if abd_zero_offsets is not None:
            offset = abd_zero_offsets.get(fname, 0.0)
            abd_angle += offset

        j_abd = JOINT_MAPPING[fname].get("abd")
        if j_abd in JOINT_ROMS:
            lo, hi = JOINT_ROMS[j_abd]
            angles[j_abd] = _clamp(abd_angle, lo, hi)

    # MCP/PIP 或拇指的 MCP/DIP（用相邻骨骼的夹角）
    valid_pairs = []
    for i in range(len(valid_dirs) - 1):
        if valid_dirs[i] is not None and valid_dirs[i + 1] is not None:
            valid_pairs.append((valid_dirs[i], valid_dirs[i + 1]))

    if len(valid_pairs) >= 1:
        mcp_angle = math.degrees(angle_between(valid_pairs[0][0], valid_pairs[0][1]))
        j_mcp = JOINT_MAPPING[fname].get("mcp")
        if j_mcp in JOINT_ROMS:
            lo, hi = JOINT_ROMS[j_mcp]
            angles[j_mcp] = _clamp(mcp_angle, lo, hi)

    if len(valid_pairs) >= 2:
        pip_angle = math.degrees(angle_between(valid_pairs[1][0], valid_pairs[1][1]))
        j_pip = JOINT_MAPPING[fname].get("pip")
        if j_pip in JOINT_ROMS:
            lo, hi = JOINT_ROMS[j_pip]
            angles[j_pip] = _clamp(pip_angle, lo, hi)

    # 拇指优化：使用拇指整体方向估计MCP的有符号弯曲
    if fname == "Thumb" and len(non_none_dirs) >= 1:
        thumb_dir = non_none_dirs[0]
        mcp_signed = math.degrees(math.atan2(thumb_dir[1], thumb_dir[0])) * 0.9
        j_mcp = JOINT_MAPPING[fname].get("mcp")
        if j_mcp in JOINT_ROMS:
            lo, hi = JOINT_ROMS[j_mcp]
            angles[j_mcp] = _clamp(mcp_signed, lo, hi)

    # 拇指的DIP（若存在第三对）
    if fname == "Thumb" and len(valid_pairs) >= 3:
        dip_angle = math.degrees(angle_between(valid_pairs[2][0], valid_pairs[2][1]))
        j_dip = JOINT_MAPPING[fname].get("dip")
        if j_dip in JOINT_ROMS:
            lo, hi = JOINT_ROMS[j_dip]
            angles[j_dip] = _clamp(dip_angle, lo, hi)

    return angles

class LeapToOrcahandNode(Node):
    def __init__(self):
        super().__init__('leap_to_orcahand_node')
        self.leap_sub = self.create_subscription(Hands, 'leap_hands', self.leap_cb, 10)
        self.pub = self.create_publisher(JointState, 'keyboard_command', 10)
        self.control_enabled = False
        self.get_logger().info("Leap→OrcaHand 映射节点启动")
        # 低通滤波与零点
        self.prev_angles = {}
        self.alpha = 0.35
        self.abd_zero_offsets = {"Thumb": 0.0, "Index": 0.0, "Middle": 0.0, "Ring": 0.0, "Pinky": 0.0}

    

    def calculate_new_thumb_mcp(self, hand):
        # ===============================================================
        # START: NEW THUMB MCP CALCULATION LOGIC (V2)
        # ===============================================================
        try:
            # 1. Get all fingers and their metacarpal bones
            fingers = {f.type: f for f in hand.fingers}
            mc_bones = {}
            for i in range(5): # 0 to 4 for thumb to pinky
                if i in fingers and len(fingers[i].bones) > 0:
                    mc_bones[i] = fingers[i].bones[0]
                else:
                    self.get_logger().warn(f"Finger {i} metacarpal not available.", throttle_duration_sec=2.0)
                    return None
            
            # 2. Define the new coordinate system
            # Origin is the thumb metacarpal base
            # Y-axis is the normal of the palm plane defined by other 4 metacarpals
            p_index = _np(mc_bones[1].prev_joint)
            p_middle = _np(mc_bones[2].prev_joint)
            p_pinky = _np(mc_bones[4].prev_joint)
            
            v1 = p_middle - p_index
            v2 = p_pinky - p_index
            palm_y_axis = _safe_normalize(np.cross(v2, v1))

            # X-axis points to the "right" of the palm, from pinky towards index
            palm_x_axis = _safe_normalize(p_index - p_pinky)
            
            # 3. Get the thumb metacarpal direction vector
            thumb_mc_dir = get_valid_bone_direction(mc_bones[0])
            if thumb_mc_dir is None: return None

            # 4. Project thumb vector onto the new XY plane
            # This is done by getting the vector's coordinates in the new basis
            x_coord = np.dot(thumb_mc_dir, palm_x_axis)
            y_coord = np.dot(thumb_mc_dir, palm_y_axis)

            # 5. Calculate the angle in the XY plane
            angle_rad = math.atan2(y_coord, x_coord)
            angle_deg = math.degrees(angle_rad) # Range [-180, 180]

            # 6. Map the angle to the joint limits [-50, 50]
            # As requested, map [0, 180] degrees to [50, -50] degrees.
            # We clamp the calculated angle to the [0, 180] range for stable mapping.
            clamped_angle_deg = _clamp(angle_deg, 0, 180)
            
            # Linear interpolation:
            # Angle 0 -> 50 degrees
            # Angle 180 -> -50 degrees
            mapped_value = np.interp(clamped_angle_deg, [50, 130], [50, -50])
            
            j_mcp = JOINT_MAPPING["Thumb"].get("mcp")
            if j_mcp in JOINT_ROMS:
                lo, hi = JOINT_ROMS[j_mcp]
                final_angle = _clamp(mapped_value, lo, hi)
                # self.get_logger().info(f"Thumb Angle: raw={angle_deg:.1f}, clamped={clamped_angle_deg:.1f}, mapped={final_angle:.1f}", throttle_duration_sec=1.0)
                return final_angle

        except Exception as e:
            self.get_logger().error(f"Error in new thumb calculation: {e}", throttle_duration_sec=2.0)
        
        return None
        # ===============================================================
        # END: NEW THUMB MCP CALCULATION LOGIC
        # ===============================================================

    def leap_cb(self, msg: Hands):
        left, right = None, None
        for h in msg.hands:
            if getattr(h, 'type', '') == "Left":
                left = h
            elif getattr(h, 'type', '') == "Right":
                right = h

        # 控制逻辑
        if left:
            if left.grab_strength > GRAB_STRENGTH_THRESHOLD and not self.control_enabled:
                self.control_enabled = True
                self.get_logger().info("控制激活")
                # 激活瞬间记录ABD零点（以当前姿态为0）
                try:
                    if right is not None:
                        palm_normal = np.array([right.normal.x, right.normal.y, right.normal.z], dtype=float)
                        # palm_forward：中指掌骨投影作为参考轴
                        palm_forward = np.array([0.0, 0.0, 1.0], dtype=float)
                        for finger in right.fingers:
                            if finger.type == 2 and len(finger.bones) >= 1:
                                dir0 = get_valid_bone_direction(finger.bones[0])
                                if dir0 is not None:
                                    palm_forward = _safe_normalize(_project_on_plane(dir0, palm_normal))
                                    break
                        for finger in right.fingers:
                            fname = FINGER_TYPE_MAP.get(finger.type, "Unknown")
                            if fname in self.abd_zero_offsets:
                                abd_vec = None
                                if len(finger.bones) >= 2:
                                    abd_vec = get_valid_bone_direction(finger.bones[1])
                                if abd_vec is None and len(finger.bones) >= 3:
                                    abd_vec = get_valid_bone_direction(finger.bones[2])
                                if abd_vec is not None:
                                    raw = signed_angle_on_plane(abd_vec, palm_forward, palm_normal)
                                    scale = 0.8 if fname == "Thumb" else 1.0
                                    self.abd_zero_offsets[fname] = -raw * scale
                    self.get_logger().info(f"ABD零点: {self.abd_zero_offsets}")
                except Exception as e:
                    self.get_logger().warn(f"设置ABD零点失败: {e}")
            elif left.grab_strength < GRAB_STRENGTH_THRESHOLD and self.control_enabled:
                self.control_enabled = False
                self.get_logger().info("控制暂停")

        if not self.control_enabled or right is None:
            return

        # 参考坐标：手掌法向+中指掌骨投影作为前向 (for other fingers)
        palm_normal = np.array([right.normal.x, right.normal.y, right.normal.z], dtype=float)
        palm_forward = np.array([0.0, 0.0, 1.0], dtype=float)
        for finger in right.fingers:
            if finger.type == 2 and len(finger.bones) >= 1:
                direction = get_valid_bone_direction(finger.bones[0])
                if direction is not None:
                    palm_forward = _safe_normalize(_project_on_plane(direction, palm_normal))
                    break

        # 计算所有手指角度
        js = JointState()
        js.header.stamp = self.get_clock().now().to_msg()
        names, positions = [], []

        current_frame_angles = {}
        for finger in right.fingers:
            # The old thumb mcp logic in calculate_finger_angles is now removed
            angles = calculate_finger_angles(finger, palm_forward, palm_normal, self.abd_zero_offsets)
            for joint_name, angle in angles.items():
                current_frame_angles[joint_name] = float(angle)

        # <<<<<<<<<<<<<<<< NEW THUMB MCP OVERRIDE >>>>>>>>>>>>>>>>
        new_thumb_mcp_angle = self.calculate_new_thumb_mcp(right)
        if new_thumb_mcp_angle is not None:
            current_frame_angles["thumb_mcp"] = float(new_thumb_mcp_angle)
        # <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>

        # 低通滤波
        for jn, val in current_frame_angles.items():
            if jn in self.prev_angles:
                filtered = self.alpha * val + (1.0 - self.alpha) * self.prev_angles[jn]
            else:
                filtered = val
            self.prev_angles[jn] = filtered
            names.append(jn)
            positions.append(filtered)

        if names:
            js.name = names
            js.position = positions
            self.pub.publish(js)
            
            # 调试输出
            pos_int = [int(p) for p in positions]
            joint_dict = dict(zip(names, pos_int))
            self.get_logger().info(f"发布关节命令: {joint_dict}", throttle_duration_sec=0.2)
def main(args=None):
    rclpy.init(args=args)
    node = LeapToOrcahandNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
