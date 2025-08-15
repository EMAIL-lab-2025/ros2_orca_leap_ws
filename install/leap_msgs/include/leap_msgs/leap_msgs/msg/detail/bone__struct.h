// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from leap_msgs:msg/Bone.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_H_
#define LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'prev_joint'
// Member 'next_joint'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Bone in the package leap_msgs.
typedef struct leap_msgs__msg__Bone
{
  /// 骨の種類 (0: Metacarpal, 1: Proximal, 2: Intermediate, 3: Distal)
  uint8_t type;
  /// 骨の基部の位置 (x, y, z)
  geometry_msgs__msg__Point prev_joint;
  /// 骨の先端の位置 (x, y, z)
  geometry_msgs__msg__Point next_joint;
  /// 骨の方向ベクトル (x, y, z)
  geometry_msgs__msg__Vector3 direction;
  /// 骨の長さ (mm)
  float length;
  /// 骨の幅 (mm)
  float width;
} leap_msgs__msg__Bone;

// Struct for a sequence of leap_msgs__msg__Bone.
typedef struct leap_msgs__msg__Bone__Sequence
{
  leap_msgs__msg__Bone * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} leap_msgs__msg__Bone__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_H_
