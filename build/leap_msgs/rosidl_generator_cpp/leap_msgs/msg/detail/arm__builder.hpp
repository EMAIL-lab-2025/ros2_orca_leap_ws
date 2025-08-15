// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from leap_msgs:msg/Arm.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__ARM__BUILDER_HPP_
#define LEAP_MSGS__MSG__DETAIL__ARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "leap_msgs/msg/detail/arm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace leap_msgs
{

namespace msg
{

namespace builder
{

class Init_Arm_width
{
public:
  explicit Init_Arm_width(::leap_msgs::msg::Arm & msg)
  : msg_(msg)
  {}
  ::leap_msgs::msg::Arm width(::leap_msgs::msg::Arm::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::leap_msgs::msg::Arm msg_;
};

class Init_Arm_length
{
public:
  explicit Init_Arm_length(::leap_msgs::msg::Arm & msg)
  : msg_(msg)
  {}
  Init_Arm_width length(::leap_msgs::msg::Arm::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Arm_width(msg_);
  }

private:
  ::leap_msgs::msg::Arm msg_;
};

class Init_Arm_direction
{
public:
  explicit Init_Arm_direction(::leap_msgs::msg::Arm & msg)
  : msg_(msg)
  {}
  Init_Arm_length direction(::leap_msgs::msg::Arm::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Arm_length(msg_);
  }

private:
  ::leap_msgs::msg::Arm msg_;
};

class Init_Arm_wrist_position
{
public:
  explicit Init_Arm_wrist_position(::leap_msgs::msg::Arm & msg)
  : msg_(msg)
  {}
  Init_Arm_direction wrist_position(::leap_msgs::msg::Arm::_wrist_position_type arg)
  {
    msg_.wrist_position = std::move(arg);
    return Init_Arm_direction(msg_);
  }

private:
  ::leap_msgs::msg::Arm msg_;
};

class Init_Arm_elbow_position
{
public:
  Init_Arm_elbow_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Arm_wrist_position elbow_position(::leap_msgs::msg::Arm::_elbow_position_type arg)
  {
    msg_.elbow_position = std::move(arg);
    return Init_Arm_wrist_position(msg_);
  }

private:
  ::leap_msgs::msg::Arm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::leap_msgs::msg::Arm>()
{
  return leap_msgs::msg::builder::Init_Arm_elbow_position();
}

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__ARM__BUILDER_HPP_
