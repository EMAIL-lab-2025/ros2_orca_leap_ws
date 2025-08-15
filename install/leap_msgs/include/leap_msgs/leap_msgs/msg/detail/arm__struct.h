// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from leap_msgs:msg/Arm.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__ARM__STRUCT_H_
#define LEAP_MSGS__MSG__DETAIL__ARM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'elbow_position'
// Member 'wrist_position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Arm in the package leap_msgs.
typedef struct leap_msgs__msg__Arm
{
  /// 肘の位置 (x, y, z)
  geometry_msgs__msg__Point elbow_position;
  /// 手首の位置 (x, y, z)
  geometry_msgs__msg__Point wrist_position;
  /// 腕の方向ベクトル (x, y, z)
  geometry_msgs__msg__Vector3 direction;
  /// 腕の長さ (mm)
  float length;
  /// 腕の幅 (mm)
  float width;
} leap_msgs__msg__Arm;

// Struct for a sequence of leap_msgs__msg__Arm.
typedef struct leap_msgs__msg__Arm__Sequence
{
  leap_msgs__msg__Arm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} leap_msgs__msg__Arm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__ARM__STRUCT_H_
