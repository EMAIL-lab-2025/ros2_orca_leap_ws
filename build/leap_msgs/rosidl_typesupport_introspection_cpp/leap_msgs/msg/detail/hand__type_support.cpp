// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "leap_msgs/msg/detail/hand__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace leap_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Hand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) leap_msgs::msg::Hand(_init);
}

void Hand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<leap_msgs::msg::Hand *>(message_memory);
  typed_message->~Hand();
}

size_t size_function__Hand__fingers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<leap_msgs::msg::Finger> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Hand__fingers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<leap_msgs::msg::Finger> *>(untyped_member);
  return &member[index];
}

void * get_function__Hand__fingers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<leap_msgs::msg::Finger> *>(untyped_member);
  return &member[index];
}

void fetch_function__Hand__fingers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const leap_msgs::msg::Finger *>(
    get_const_function__Hand__fingers(untyped_member, index));
  auto & value = *reinterpret_cast<leap_msgs::msg::Finger *>(untyped_value);
  value = item;
}

void assign_function__Hand__fingers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<leap_msgs::msg::Finger *>(
    get_function__Hand__fingers(untyped_member, index));
  const auto & value = *reinterpret_cast<const leap_msgs::msg::Finger *>(untyped_value);
  item = value;
}

void resize_function__Hand__fingers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<leap_msgs::msg::Finger> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Hand_message_member_array[9] = {
  {
    "type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "normal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, normal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "orientation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Quaternion>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, orientation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "grab_strength",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, grab_strength),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pinch_strength",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, pinch_strength),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "fingers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<leap_msgs::msg::Finger>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, fingers),  // bytes offset in struct
    nullptr,  // default value
    size_function__Hand__fingers,  // size() function pointer
    get_const_function__Hand__fingers,  // get_const(index) function pointer
    get_function__Hand__fingers,  // get(index) function pointer
    fetch_function__Hand__fingers,  // fetch(index, &value) function pointer
    assign_function__Hand__fingers,  // assign(index, value) function pointer
    resize_function__Hand__fingers  // resize(index) function pointer
  },
  {
    "arm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<leap_msgs::msg::Arm>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs::msg::Hand, arm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Hand_message_members = {
  "leap_msgs::msg",  // message namespace
  "Hand",  // message name
  9,  // number of fields
  sizeof(leap_msgs::msg::Hand),
  Hand_message_member_array,  // message members
  Hand_init_function,  // function to initialize message memory (memory has to be allocated)
  Hand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Hand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Hand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace leap_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<leap_msgs::msg::Hand>()
{
  return &::leap_msgs::msg::rosidl_typesupport_introspection_cpp::Hand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, leap_msgs, msg, Hand)() {
  return &::leap_msgs::msg::rosidl_typesupport_introspection_cpp::Hand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
