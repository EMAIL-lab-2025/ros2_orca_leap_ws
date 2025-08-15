// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_H_
#define LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'velocity'
// Member 'normal'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'fingers'
#include "leap_msgs/msg/detail/finger__struct.h"
// Member 'arm'
#include "leap_msgs/msg/detail/arm__struct.h"

/// Struct defined in msg/Hand in the package leap_msgs.
typedef struct leap_msgs__msg__Hand
{
  rosidl_runtime_c__String type;
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Vector3 velocity;
  geometry_msgs__msg__Vector3 normal;
  geometry_msgs__msg__Quaternion orientation;
  float grab_strength;
  float pinch_strength;
  leap_msgs__msg__Finger__Sequence fingers;
  leap_msgs__msg__Arm arm;
} leap_msgs__msg__Hand;

// Struct for a sequence of leap_msgs__msg__Hand.
typedef struct leap_msgs__msg__Hand__Sequence
{
  leap_msgs__msg__Hand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} leap_msgs__msg__Hand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_H_
