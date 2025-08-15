// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__FINGER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define LEAP_MSGS__MSG__DETAIL__FINGER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "leap_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "leap_msgs/msg/detail/finger__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace leap_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leap_msgs
cdr_serialize(
  const leap_msgs::msg::Finger & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leap_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  leap_msgs::msg::Finger & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leap_msgs
get_serialized_size(
  const leap_msgs::msg::Finger & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leap_msgs
max_serialized_size_Finger(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace leap_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_leap_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, leap_msgs, msg, Finger)();

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__FINGER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
