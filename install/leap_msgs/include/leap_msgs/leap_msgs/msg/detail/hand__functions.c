// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice
#include "leap_msgs/msg/detail/hand__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `velocity`
// Member `normal`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `fingers`
#include "leap_msgs/msg/detail/finger__functions.h"
// Member `arm`
#include "leap_msgs/msg/detail/arm__functions.h"

bool
leap_msgs__msg__Hand__init(leap_msgs__msg__Hand * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__init(&msg->normal)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // grab_strength
  // pinch_strength
  // fingers
  if (!leap_msgs__msg__Finger__Sequence__init(&msg->fingers, 0)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  // arm
  if (!leap_msgs__msg__Arm__init(&msg->arm)) {
    leap_msgs__msg__Hand__fini(msg);
    return false;
  }
  return true;
}

void
leap_msgs__msg__Hand__fini(leap_msgs__msg__Hand * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // velocity
  geometry_msgs__msg__Vector3__fini(&msg->velocity);
  // normal
  geometry_msgs__msg__Vector3__fini(&msg->normal);
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
  // grab_strength
  // pinch_strength
  // fingers
  leap_msgs__msg__Finger__Sequence__fini(&msg->fingers);
  // arm
  leap_msgs__msg__Arm__fini(&msg->arm);
}

bool
leap_msgs__msg__Hand__are_equal(const leap_msgs__msg__Hand * lhs, const leap_msgs__msg__Hand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->normal), &(rhs->normal)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  // grab_strength
  if (lhs->grab_strength != rhs->grab_strength) {
    return false;
  }
  // pinch_strength
  if (lhs->pinch_strength != rhs->pinch_strength) {
    return false;
  }
  // fingers
  if (!leap_msgs__msg__Finger__Sequence__are_equal(
      &(lhs->fingers), &(rhs->fingers)))
  {
    return false;
  }
  // arm
  if (!leap_msgs__msg__Arm__are_equal(
      &(lhs->arm), &(rhs->arm)))
  {
    return false;
  }
  return true;
}

bool
leap_msgs__msg__Hand__copy(
  const leap_msgs__msg__Hand * input,
  leap_msgs__msg__Hand * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // normal
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->normal), &(output->normal)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  // grab_strength
  output->grab_strength = input->grab_strength;
  // pinch_strength
  output->pinch_strength = input->pinch_strength;
  // fingers
  if (!leap_msgs__msg__Finger__Sequence__copy(
      &(input->fingers), &(output->fingers)))
  {
    return false;
  }
  // arm
  if (!leap_msgs__msg__Arm__copy(
      &(input->arm), &(output->arm)))
  {
    return false;
  }
  return true;
}

leap_msgs__msg__Hand *
leap_msgs__msg__Hand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hand * msg = (leap_msgs__msg__Hand *)allocator.allocate(sizeof(leap_msgs__msg__Hand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(leap_msgs__msg__Hand));
  bool success = leap_msgs__msg__Hand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
leap_msgs__msg__Hand__destroy(leap_msgs__msg__Hand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    leap_msgs__msg__Hand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
leap_msgs__msg__Hand__Sequence__init(leap_msgs__msg__Hand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hand * data = NULL;

  if (size) {
    data = (leap_msgs__msg__Hand *)allocator.zero_allocate(size, sizeof(leap_msgs__msg__Hand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = leap_msgs__msg__Hand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        leap_msgs__msg__Hand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
leap_msgs__msg__Hand__Sequence__fini(leap_msgs__msg__Hand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      leap_msgs__msg__Hand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

leap_msgs__msg__Hand__Sequence *
leap_msgs__msg__Hand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hand__Sequence * array = (leap_msgs__msg__Hand__Sequence *)allocator.allocate(sizeof(leap_msgs__msg__Hand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = leap_msgs__msg__Hand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
leap_msgs__msg__Hand__Sequence__destroy(leap_msgs__msg__Hand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    leap_msgs__msg__Hand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
leap_msgs__msg__Hand__Sequence__are_equal(const leap_msgs__msg__Hand__Sequence * lhs, const leap_msgs__msg__Hand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!leap_msgs__msg__Hand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
leap_msgs__msg__Hand__Sequence__copy(
  const leap_msgs__msg__Hand__Sequence * input,
  leap_msgs__msg__Hand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(leap_msgs__msg__Hand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    leap_msgs__msg__Hand * data =
      (leap_msgs__msg__Hand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!leap_msgs__msg__Hand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          leap_msgs__msg__Hand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!leap_msgs__msg__Hand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
