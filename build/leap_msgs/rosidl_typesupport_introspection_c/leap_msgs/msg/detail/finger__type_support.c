// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "leap_msgs/msg/detail/finger__rosidl_typesupport_introspection_c.h"
#include "leap_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "leap_msgs/msg/detail/finger__functions.h"
#include "leap_msgs/msg/detail/finger__struct.h"


// Include directives for member types
// Member `tip_position`
#include "geometry_msgs/msg/point.h"
// Member `tip_position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `direction`
// Member `velocity`
#include "geometry_msgs/msg/vector3.h"
// Member `direction`
// Member `velocity`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `bones`
#include "leap_msgs/msg/bone.h"
// Member `bones`
#include "leap_msgs/msg/detail/bone__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  leap_msgs__msg__Finger__init(message_memory);
}

void leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_fini_function(void * message_memory)
{
  leap_msgs__msg__Finger__fini(message_memory);
}

size_t leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__size_function__Finger__bones(
  const void * untyped_member)
{
  const leap_msgs__msg__Bone__Sequence * member =
    (const leap_msgs__msg__Bone__Sequence *)(untyped_member);
  return member->size;
}

const void * leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_const_function__Finger__bones(
  const void * untyped_member, size_t index)
{
  const leap_msgs__msg__Bone__Sequence * member =
    (const leap_msgs__msg__Bone__Sequence *)(untyped_member);
  return &member->data[index];
}

void * leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_function__Finger__bones(
  void * untyped_member, size_t index)
{
  leap_msgs__msg__Bone__Sequence * member =
    (leap_msgs__msg__Bone__Sequence *)(untyped_member);
  return &member->data[index];
}

void leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__fetch_function__Finger__bones(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const leap_msgs__msg__Bone * item =
    ((const leap_msgs__msg__Bone *)
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_const_function__Finger__bones(untyped_member, index));
  leap_msgs__msg__Bone * value =
    (leap_msgs__msg__Bone *)(untyped_value);
  *value = *item;
}

void leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__assign_function__Finger__bones(
  void * untyped_member, size_t index, const void * untyped_value)
{
  leap_msgs__msg__Bone * item =
    ((leap_msgs__msg__Bone *)
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_function__Finger__bones(untyped_member, index));
  const leap_msgs__msg__Bone * value =
    (const leap_msgs__msg__Bone *)(untyped_value);
  *item = *value;
}

bool leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__resize_function__Finger__bones(
  void * untyped_member, size_t size)
{
  leap_msgs__msg__Bone__Sequence * member =
    (leap_msgs__msg__Bone__Sequence *)(untyped_member);
  leap_msgs__msg__Bone__Sequence__fini(member);
  return leap_msgs__msg__Bone__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array[8] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tip_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, tip_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, direction),  // bytes offset in struct
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
    offsetof(leap_msgs__msg__Finger, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bones",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(leap_msgs__msg__Finger, bones),  // bytes offset in struct
    NULL,  // default value
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__size_function__Finger__bones,  // size() function pointer
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_const_function__Finger__bones,  // get_const(index) function pointer
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__get_function__Finger__bones,  // get(index) function pointer
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__fetch_function__Finger__bones,  // fetch(index, &value) function pointer
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__assign_function__Finger__bones,  // assign(index, value) function pointer
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__resize_function__Finger__bones  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_members = {
  "leap_msgs__msg",  // message namespace
  "Finger",  // message name
  8,  // number of fields
  sizeof(leap_msgs__msg__Finger),
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array,  // message members
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_init_function,  // function to initialize message memory (memory has to be allocated)
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_type_support_handle = {
  0,
  &leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_leap_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Finger)() {
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, leap_msgs, msg, Bone)();
  if (!leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_type_support_handle.typesupport_identifier) {
    leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &leap_msgs__msg__Finger__rosidl_typesupport_introspection_c__Finger_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
