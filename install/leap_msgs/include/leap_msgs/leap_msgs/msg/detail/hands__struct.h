// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from leap_msgs:msg/Hands.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HANDS__STRUCT_H_
#define LEAP_MSGS__MSG__DETAIL__HANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'hands'
#include "leap_msgs/msg/detail/hand__struct.h"

/// Struct defined in msg/Hands in the package leap_msgs.
typedef struct leap_msgs__msg__Hands
{
  std_msgs__msg__Header header;
  leap_msgs__msg__Hand__Sequence hands;
} leap_msgs__msg__Hands;

// Struct for a sequence of leap_msgs__msg__Hands.
typedef struct leap_msgs__msg__Hands__Sequence
{
  leap_msgs__msg__Hands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} leap_msgs__msg__Hands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__HANDS__STRUCT_H_
