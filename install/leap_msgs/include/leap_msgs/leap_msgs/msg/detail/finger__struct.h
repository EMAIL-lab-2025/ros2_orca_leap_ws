// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_H_
#define LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tip_position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'direction'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'bones'
#include "leap_msgs/msg/detail/bone__struct.h"

/// Struct defined in msg/Finger in the package leap_msgs.
typedef struct leap_msgs__msg__Finger
{
  /// 指を一意に識別するID
  int32_t id;
  /// 指の種類 (0: Thumb, 1: Index, 2: Middle, 3: Ring, 4: Pinky)
  uint8_t type;
  /// 指先の位置 (x, y, z)
  geometry_msgs__msg__Point tip_position;
  /// 指の方向ベクトル (x, y, z)
  geometry_msgs__msg__Vector3 direction;
  /// 指の速度ベクトル (x, y, z)
  geometry_msgs__msg__Vector3 velocity;
  /// 指の長さ (mm)
  float length;
  /// 指の幅 (mm)
  float width;
  /// 指を構成する骨の情報
  /// 指の骨のリスト (Metacarpal, Proximal, Intermediate, Distal)
  leap_msgs__msg__Bone__Sequence bones;
} leap_msgs__msg__Finger;

// Struct for a sequence of leap_msgs__msg__Finger.
typedef struct leap_msgs__msg__Finger__Sequence
{
  leap_msgs__msg__Finger * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} leap_msgs__msg__Finger__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_H_
