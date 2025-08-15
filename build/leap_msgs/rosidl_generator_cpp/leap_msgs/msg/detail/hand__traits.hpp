// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HAND__TRAITS_HPP_
#define LEAP_MSGS__MSG__DETAIL__HAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "leap_msgs/msg/detail/hand__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'velocity'
// Member 'normal'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"
// Member 'fingers'
#include "leap_msgs/msg/detail/finger__traits.hpp"
// Member 'arm'
#include "leap_msgs/msg/detail/arm__traits.hpp"

namespace leap_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Hand & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: normal
  {
    out << "normal: ";
    to_flow_style_yaml(msg.normal, out);
    out << ", ";
  }

  // member: orientation
  {
    out << "orientation: ";
    to_flow_style_yaml(msg.orientation, out);
    out << ", ";
  }

  // member: grab_strength
  {
    out << "grab_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.grab_strength, out);
    out << ", ";
  }

  // member: pinch_strength
  {
    out << "pinch_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.pinch_strength, out);
    out << ", ";
  }

  // member: fingers
  {
    if (msg.fingers.size() == 0) {
      out << "fingers: []";
    } else {
      out << "fingers: [";
      size_t pending_items = msg.fingers.size();
      for (auto item : msg.fingers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: arm
  {
    out << "arm: ";
    to_flow_style_yaml(msg.arm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Hand & msg,
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

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "normal:\n";
    to_block_style_yaml(msg.normal, out, indentation + 2);
  }

  // member: orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation:\n";
    to_block_style_yaml(msg.orientation, out, indentation + 2);
  }

  // member: grab_strength
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grab_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.grab_strength, out);
    out << "\n";
  }

  // member: pinch_strength
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pinch_strength: ";
    rosidl_generator_traits::value_to_yaml(msg.pinch_strength, out);
    out << "\n";
  }

  // member: fingers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.fingers.size() == 0) {
      out << "fingers: []\n";
    } else {
      out << "fingers:\n";
      for (auto item : msg.fingers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: arm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm:\n";
    to_block_style_yaml(msg.arm, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Hand & msg, bool use_flow_style = false)
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
  const leap_msgs::msg::Hand & msg,
  std::ostream & out, size_t indentation = 0)
{
  leap_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use leap_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const leap_msgs::msg::Hand & msg)
{
  return leap_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<leap_msgs::msg::Hand>()
{
  return "leap_msgs::msg::Hand";
}

template<>
inline const char * name<leap_msgs::msg::Hand>()
{
  return "leap_msgs/msg/Hand";
}

template<>
struct has_fixed_size<leap_msgs::msg::Hand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<leap_msgs::msg::Hand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<leap_msgs::msg::Hand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LEAP_MSGS__MSG__DETAIL__HAND__TRAITS_HPP_
