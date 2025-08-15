// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__FINGER__TRAITS_HPP_
#define LEAP_MSGS__MSG__DETAIL__FINGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "leap_msgs/msg/detail/finger__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'tip_position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'direction'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'bones'
#include "leap_msgs/msg/detail/bone__traits.hpp"

namespace leap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Finger & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: tip_position
  {
    out << "tip_position: ";
    to_flow_style_yaml(msg.tip_position, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    to_flow_style_yaml(msg.direction, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
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
    out << ", ";
  }

  // member: bones
  {
    if (msg.bones.size() == 0) {
      out << "bones: []";
    } else {
      out << "bones: [";
      size_t pending_items = msg.bones.size();
      for (auto item : msg.bones) {
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
  const Finger & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: tip_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tip_position:\n";
    to_block_style_yaml(msg.tip_position, out, indentation + 2);
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction:\n";
    to_block_style_yaml(msg.direction, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
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

  // member: bones
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bones.size() == 0) {
      out << "bones: []\n";
    } else {
      out << "bones:\n";
      for (auto item : msg.bones) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Finger & msg, bool use_flow_style = false)
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
  const leap_msgs::msg::Finger & msg,
  std::ostream & out, size_t indentation = 0)
{
  leap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use leap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const leap_msgs::msg::Finger & msg)
{
  return leap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<leap_msgs::msg::Finger>()
{
  return "leap_msgs::msg::Finger";
}

template<>
inline const char * name<leap_msgs::msg::Finger>()
{
  return "leap_msgs/msg/Finger";
}

template<>
struct has_fixed_size<leap_msgs::msg::Finger>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<leap_msgs::msg::Finger>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<leap_msgs::msg::Finger>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEAP_MSGS__MSG__DETAIL__FINGER__TRAITS_HPP_
