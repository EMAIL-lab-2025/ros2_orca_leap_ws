// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from leap_msgs:msg/Arm.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__ARM__TRAITS_HPP_
#define LEAP_MSGS__MSG__DETAIL__ARM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "leap_msgs/msg/detail/arm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'elbow_position'
// Member 'wrist_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace leap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Arm & msg,
  std::ostream & out)
{
  out << "{";
  // member: elbow_position
  {
    out << "elbow_position: ";
    to_flow_style_yaml(msg.elbow_position, out);
    out << ", ";
  }

  // member: wrist_position
  {
    out << "wrist_position: ";
    to_flow_style_yaml(msg.wrist_position, out);
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
  const Arm & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: elbow_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elbow_position:\n";
    to_block_style_yaml(msg.elbow_position, out, indentation + 2);
  }

  // member: wrist_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wrist_position:\n";
    to_block_style_yaml(msg.wrist_position, out, indentation + 2);
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

inline std::string to_yaml(const Arm & msg, bool use_flow_style = false)
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
  const leap_msgs::msg::Arm & msg,
  std::ostream & out, size_t indentation = 0)
{
  leap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use leap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const leap_msgs::msg::Arm & msg)
{
  return leap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<leap_msgs::msg::Arm>()
{
  return "leap_msgs::msg::Arm";
}

template<>
inline const char * name<leap_msgs::msg::Arm>()
{
  return "leap_msgs/msg/Arm";
}

template<>
struct has_fixed_size<leap_msgs::msg::Arm>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<leap_msgs::msg::Arm>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<leap_msgs::msg::Arm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEAP_MSGS__MSG__DETAIL__ARM__TRAITS_HPP_
