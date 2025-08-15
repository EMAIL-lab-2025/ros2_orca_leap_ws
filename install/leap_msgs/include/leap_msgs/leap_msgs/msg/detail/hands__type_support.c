// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from leap_msgs:msg/Hands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "leap_msgs/msg/detail/hands__rosidl_typesupport_introspection_c.h"
#include "leap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "leap_msgs/msg/detail/hands__functions.h"
#include "leap_msgs/msg/detail/hands__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `hands`
#include "leap_msgs/msg/hand.h"
// Member `hands`
#include "leap_msgs/msg/detail/hand__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  leap_msgs__msg__Hands__init(message_memory);
}

void leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_fini_function(void * message_memory)
{
  leap_msgs__msg__Hands__fini(message_memory);
}

size_t leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__size_function__Hands__hands(
  const void * untyped_member)
{
  const leap_msgs__msg__Hand__Sequence * member =
    (const leap_msgs__msg__Hand__Sequence *)(untyped_member);
  return member->size;
}

const void * leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_const_function__Hands__hands(
  const void * untyped_member, size_t index)
{
  const leap_msgs__msg__Hand__Sequence * member =
    (const leap_msgs__msg__Hand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_function__Hands__hands(
  void * untyped_member, size_t index)
{
  leap_msgs__msg__Hand__Sequence * member =
    (leap_msgs__msg__Hand__Sequence *)(untyped_member);
  return &member->data[index];
}

void leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__fetch_function__Hands__hands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const leap_msgs__msg__Hand * item =
    ((const leap_msgs__msg__Hand *)
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_const_function__Hands__hands(untyped_member, index));
  leap_msgs__msg__Hand * value =
    (leap_msgs__msg__Hand *)(untyped_value);
  *value = *item;
}

void leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__assign_function__Hands__hands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  leap_msgs__msg__Hand * item =
    ((leap_msgs__msg__Hand *)
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_function__Hands__hands(untyped_member, index));
  const leap_msgs__msg__Hand * value =
    (const leap_msgs__msg__Hand *)(untyped_value);
  *item = *value;
}

bool leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__resize_function__Hands__hands(
  void * untyped_member, size_t size)
{
  leap_msgs__msg__Hand__Sequence * member =
    (leap_msgs__msg__Hand__Sequence *)(untyped_member);
  leap_msgs__msg__Hand__Sequence__fini(member);
  return leap_msgs__msg__Hand__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hands, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hands, hands),  // bytes offset in struct
    NULL,  // default value
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__size_function__Hands__hands,  // size() function pointer
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_const_function__Hands__hands,  // get_const(index) function pointer
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__get_function__Hands__hands,  // get(index) function pointer
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__fetch_function__Hands__hands,  // fetch(index, &value) function pointer
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__assign_function__Hands__hands,  // assign(index, value) function pointer
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__resize_function__Hands__hands  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_members = {
  "leap_msgs__msg",  // message namespace
  "Hands",  // message name
  2,  // number of fields
  sizeof(leap_msgs__msg__Hands),
  leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_member_array,  // message members
  leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_init_function,  // function to initialize message memory (memory has to be allocated)
  leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_type_support_handle = {
  0,
  &leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_leap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Hands)() {
  leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Hand)();
  if (!leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_type_support_handle.typesupport_identifier) {
    leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &leap_msgs__msg__Hands__rosidl_typesupport_introspection_c__Hands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
