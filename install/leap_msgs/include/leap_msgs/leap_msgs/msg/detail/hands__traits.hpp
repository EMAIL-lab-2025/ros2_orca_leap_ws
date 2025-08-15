// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from leap_msgs:msg/Hands.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HANDS__TRAITS_HPP_
#define LEAP_MSGS__MSG__DETAIL__HANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "leap_msgs/msg/detail/hands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'hands'
#include "leap_msgs/msg/detail/hand__traits.hpp"

namespace leap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Hands & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: hands
  {
    if (msg.hands.size() == 0) {
      out << "hands: []";
    } else {
      out << "hands: [";
      size_t pending_items = msg.hands.size();
      for (auto item : msg.hands) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: hands
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hands.size() == 0) {
      out << "hands: []\n";
    } else {
      out << "hands:\n";
      for (auto item : msg.hands) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hands & msg, bool use_flow_style = false)
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
  const leap_msgs::msg::Hands & msg,
  std::ostream & out, size_t indentation = 0)
{
  leap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use leap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const leap_msgs::msg::Hands & msg)
{
  return leap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<leap_msgs::msg::Hands>()
{
  return "leap_msgs::msg::Hands";
}

template<>
inline const char * name<leap_msgs::msg::Hands>()
{
  return "leap_msgs/msg/Hands";
}

template<>
struct has_fixed_size<leap_msgs::msg::Hands>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<leap_msgs::msg::Hands>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<leap_msgs::msg::Hands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEAP_MSGS__MSG__DETAIL__HANDS__TRAITS_HPP_
