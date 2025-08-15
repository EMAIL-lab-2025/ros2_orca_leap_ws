// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from leap_msgs:msg/Bone.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__BONE__TRAITS_HPP_
#define LEAP_MSGS__MSG__DETAIL__BONE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "leap_msgs/msg/detail/bone__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'prev_joint'
// Member 'next_joint'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace leap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Bone & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: prev_joint
  {
    out << "prev_joint: ";
    to_flow_style_yaml(msg.prev_joint, out);
    out << ", ";
  }

  // member: next_joint
  {
    out << "next_joint: ";
    to_flow_style_yaml(msg.next_joint, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    to_flow_style_yaml(msg.direction, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Bone & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: prev_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prev_joint:\n";
    to_block_style_yaml(msg.prev_joint, out, indentation + 2);
  }

  // member: next_joint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "next_joint:\n";
    to_block_style_yaml(msg.next_joint, out, indentation + 2);
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction:\n";
    to_block_style_yaml(msg.direction, out, indentation + 2);
  }

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Bone & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace leap_msgs

namespace rosidl_generator_traits
{

[[deprecated("use leap_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const leap_msgs::msg::Bone & msg,
  std::ostream & out, size_t indentation = 0)
{
  leap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use leap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const leap_msgs::msg::Bone & msg)
{
  return leap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<leap_msgs::msg::Bone>()
{
  return "leap_msgs::msg::Bone";
}

template<>
inline const char * name<leap_msgs::msg::Bone>()
{
  return "leap_msgs/msg/Bone";
}

template<>
struct has_fixed_size<leap_msgs::msg::Bone>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<leap_msgs::msg::Bone>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<leap_msgs::msg::Bone>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEAP_MSGS__MSG__DETAIL__BONE__TRAITS_HPP_
