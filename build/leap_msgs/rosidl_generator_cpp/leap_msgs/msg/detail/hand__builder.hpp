// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_
#define LEAP_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "leap_msgs/msg/detail/hand__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace leap_msgs
{

namespace msg
{

namespace builder
{

class Init_Hand_arm
{
public:
  explicit Init_Hand_arm(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  ::leap_msgs::msg::Hand arm(::leap_msgs::msg::Hand::_arm_type arg)
  {
    msg_.arm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_fingers
{
public:
  explicit Init_Hand_fingers(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_arm fingers(::leap_msgs::msg::Hand::_fingers_type arg)
  {
    msg_.fingers = std::move(arg);
    return Init_Hand_arm(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_pinch_strength
{
public:
  explicit Init_Hand_pinch_strength(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_fingers pinch_strength(::leap_msgs::msg::Hand::_pinch_strength_type arg)
  {
    msg_.pinch_strength = std::move(arg);
    return Init_Hand_fingers(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_grab_strength
{
public:
  explicit Init_Hand_grab_strength(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_pinch_strength grab_strength(::leap_msgs::msg::Hand::_grab_strength_type arg)
  {
    msg_.grab_strength = std::move(arg);
    return Init_Hand_pinch_strength(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_orientation
{
public:
  explicit Init_Hand_orientation(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_grab_strength orientation(::leap_msgs::msg::Hand::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_Hand_grab_strength(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_normal
{
public:
  explicit Init_Hand_normal(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_orientation normal(::leap_msgs::msg::Hand::_normal_type arg)
  {
    msg_.normal = std::move(arg);
    return Init_Hand_orientation(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_velocity
{
public:
  explicit Init_Hand_velocity(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_normal velocity(::leap_msgs::msg::Hand::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_Hand_normal(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_position
{
public:
  explicit Init_Hand_position(::leap_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_velocity position(::leap_msgs::msg::Hand::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Hand_velocity(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

class Init_Hand_type
{
public:
  Init_Hand_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hand_position type(::leap_msgs::msg::Hand::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Hand_position(msg_);
  }

private:
  ::leap_msgs::msg::Hand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::leap_msgs::msg::Hand>()
{
  return leap_msgs::msg::builder::Init_Hand_type();
}

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_
