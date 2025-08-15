// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__FINGER__BUILDER_HPP_
#define LEAP_MSGS__MSG__DETAIL__FINGER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "leap_msgs/msg/detail/finger__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace leap_msgs
{

namespace msg
{

namespace builder
{

class Init_Finger_bones
{
public:
  explicit Init_Finger_bones(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  ::leap_msgs::msg::Finger bones(::leap_msgs::msg::Finger::_bones_type arg)
  {
    msg_.bones = std::move(arg);
    return std::move(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_width
{
public:
  explicit Init_Finger_width(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_bones width(::leap_msgs::msg::Finger::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_Finger_bones(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_length
{
public:
  explicit Init_Finger_length(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_width length(::leap_msgs::msg::Finger::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Finger_width(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_velocity
{
public:
  explicit Init_Finger_velocity(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_length velocity(::leap_msgs::msg::Finger::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_Finger_length(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_direction
{
public:
  explicit Init_Finger_direction(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_velocity direction(::leap_msgs::msg::Finger::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Finger_velocity(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_tip_position
{
public:
  explicit Init_Finger_tip_position(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_direction tip_position(::leap_msgs::msg::Finger::_tip_position_type arg)
  {
    msg_.tip_position = std::move(arg);
    return Init_Finger_direction(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_type
{
public:
  explicit Init_Finger_type(::leap_msgs::msg::Finger & msg)
  : msg_(msg)
  {}
  Init_Finger_tip_position type(::leap_msgs::msg::Finger::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Finger_tip_position(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

class Init_Finger_id
{
public:
  Init_Finger_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Finger_type id(::leap_msgs::msg::Finger::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Finger_type(msg_);
  }

private:
  ::leap_msgs::msg::Finger msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::leap_msgs::msg::Finger>()
{
  return leap_msgs::msg::builder::Init_Finger_id();
}

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__FINGER__BUILDER_HPP_
