// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from leap_msgs:msg/Hands.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HANDS__BUILDER_HPP_
#define LEAP_MSGS__MSG__DETAIL__HANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "leap_msgs/msg/detail/hands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace leap_msgs
{

namespace msg
{

namespace builder
{

class Init_Hands_hands
{
public:
  explicit Init_Hands_hands(::leap_msgs::msg::Hands & msg)
  : msg_(msg)
  {}
  ::leap_msgs::msg::Hands hands(::leap_msgs::msg::Hands::_hands_type arg)
  {
    msg_.hands = std::move(arg);
    return std::move(msg_);
  }

private:
  ::leap_msgs::msg::Hands msg_;
};

class Init_Hands_header
{
public:
  Init_Hands_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hands_hands header(::leap_msgs::msg::Hands::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Hands_hands(msg_);
  }

private:
  ::leap_msgs::msg::Hands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::leap_msgs::msg::Hands>()
{
  return leap_msgs::msg::builder::Init_Hands_header();
}

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__HANDS__BUILDER_HPP_
