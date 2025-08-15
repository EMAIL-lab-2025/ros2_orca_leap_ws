// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "leap_msgs/msg/detail/hand__rosidl_typesupport_introspection_c.h"
#include "leap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "leap_msgs/msg/detail/hand__functions.h"
#include "leap_msgs/msg/detail/hand__struct.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `velocity`
// Member `normal`
#include "geometry_msgs/msg/vector3.h"
// Member `velocity`
// Member `normal`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `orientation`
#include "geometry_msgs/msg/quaternion.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"
// Member `fingers`
#include "leap_msgs/msg/finger.h"
// Member `fingers`
#include "leap_msgs/msg/detail/finger__rosidl_typesupport_introspection_c.h"
// Member `arm`
#include "leap_msgs/msg/arm.h"
// Member `arm`
#include "leap_msgs/msg/detail/arm__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  leap_msgs__msg__Hand__init(message_memory);
}

void leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_fini_function(void * message_memory)
{
  leap_msgs__msg__Hand__fini(message_memory);
}

size_t leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__fingers(
  const void * untyped_member)
{
  const leap_msgs__msg__Finger__Sequence * member =
    (const leap_msgs__msg__Finger__Sequence *)(untyped_member);
  return member->size;
}

const void * leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__fingers(
  const void * untyped_member, size_t index)
{
  const leap_msgs__msg__Finger__Sequence * member =
    (const leap_msgs__msg__Finger__Sequence *)(untyped_member);
  return &member->data[index];
}

void * leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__fingers(
  void * untyped_member, size_t index)
{
  leap_msgs__msg__Finger__Sequence * member =
    (leap_msgs__msg__Finger__Sequence *)(untyped_member);
  return &member->data[index];
}

void leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__fingers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const leap_msgs__msg__Finger * item =
    ((const leap_msgs__msg__Finger *)
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__fingers(untyped_member, index));
  leap_msgs__msg__Finger * value =
    (leap_msgs__msg__Finger *)(untyped_value);
  *value = *item;
}

void leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__fingers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  leap_msgs__msg__Finger * item =
    ((leap_msgs__msg__Finger *)
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__fingers(untyped_member, index));
  const leap_msgs__msg__Finger * value =
    (const leap_msgs__msg__Finger *)(untyped_value);
  *item = *value;
}

bool leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__resize_function__Hand__fingers(
  void * untyped_member, size_t size)
{
  leap_msgs__msg__Finger__Sequence * member =
    (leap_msgs__msg__Finger__Sequence *)(untyped_member);
  leap_msgs__msg__Finger__Sequence__fini(member);
  return leap_msgs__msg__Finger__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[9] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "normal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, normal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, orientation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "grab_strength",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, grab_strength),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pinch_strength",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, pinch_strength),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fingers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, fingers),  // bytes offset in struct
    NULL,  // default value
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__fingers,  // size() function pointer
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__fingers,  // get_const(index) function pointer
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__fingers,  // get(index) function pointer
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__fingers,  // fetch(index, &value) function pointer
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__fingers,  // assign(index, value) function pointer
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__resize_function__Hand__fingers  // resize(index) function pointer
  },
  {
    "arm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Hand, arm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_members = {
  "leap_msgs__msg",  // message namespace
  "Hand",  // message name
  9,  // number of fields
  sizeof(leap_msgs__msg__Hand),
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array,  // message members
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_init_function,  // function to initialize message memory (memory has to be allocated)
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle = {
  0,
  &leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_leap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Hand)() {
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Finger)();
  leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[8].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Arm)();
  if (!leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle.typesupport_identifier) {
    leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &leap_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
