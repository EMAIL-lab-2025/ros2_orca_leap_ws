// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from leap_msgs:msg/Bone.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__BONE__BUILDER_HPP_
#define LEAP_MSGS__MSG__DETAIL__BONE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "leap_msgs/msg/detail/bone__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace leap_msgs
{

namespace msg
{

namespace builder
{

class Init_Bone_width
{
public:
  explicit Init_Bone_width(::leap_msgs::msg::Bone & msg)
  : msg_(msg)
  {}
  ::leap_msgs::msg::Bone width(::leap_msgs::msg::Bone::_width_type arg)
  {
    msg_.width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

class Init_Bone_length
{
public:
  explicit Init_Bone_length(::leap_msgs::msg::Bone & msg)
  : msg_(msg)
  {}
  Init_Bone_width length(::leap_msgs::msg::Bone::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Bone_width(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

class Init_Bone_direction
{
public:
  explicit Init_Bone_direction(::leap_msgs::msg::Bone & msg)
  : msg_(msg)
  {}
  Init_Bone_length direction(::leap_msgs::msg::Bone::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Bone_length(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

class Init_Bone_next_joint
{
public:
  explicit Init_Bone_next_joint(::leap_msgs::msg::Bone & msg)
  : msg_(msg)
  {}
  Init_Bone_direction next_joint(::leap_msgs::msg::Bone::_next_joint_type arg)
  {
    msg_.next_joint = std::move(arg);
    return Init_Bone_direction(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

class Init_Bone_prev_joint
{
public:
  explicit Init_Bone_prev_joint(::leap_msgs::msg::Bone & msg)
  : msg_(msg)
  {}
  Init_Bone_next_joint prev_joint(::leap_msgs::msg::Bone::_prev_joint_type arg)
  {
    msg_.prev_joint = std::move(arg);
    return Init_Bone_next_joint(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

class Init_Bone_type
{
public:
  Init_Bone_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bone_prev_joint type(::leap_msgs::msg::Bone::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Bone_prev_joint(msg_);
  }

private:
  ::leap_msgs::msg::Bone msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::leap_msgs::msg::Bone>()
{
  return leap_msgs::msg::builder::Init_Bone_type();
}

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__BONE__BUILDER_HPP_
