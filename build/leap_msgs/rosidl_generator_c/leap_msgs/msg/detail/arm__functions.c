// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from leap_msgs:msg/Arm.idl
// generated code does not contain a copyright notice
#include "leap_msgs/msg/detail/arm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `elbow_position`
// Member `wrist_position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `direction`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
leap_msgs__msg__Arm__init(leap_msgs__msg__Arm * msg)
{
  if (!msg) {
    return false;
  }
  // elbow_position
  if (!geometry_msgs__msg__Point__init(&msg->elbow_position)) {
    leap_msgs__msg__Arm__fini(msg);
    return false;
  }
  // wrist_position
  if (!geometry_msgs__msg__Point__init(&msg->wrist_position)) {
    leap_msgs__msg__Arm__fini(msg);
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__init(&msg->direction)) {
    leap_msgs__msg__Arm__fini(msg);
    return false;
  }
  // length
  // width
  return true;
}

void
leap_msgs__msg__Arm__fini(leap_msgs__msg__Arm * msg)
{
  if (!msg) {
    return;
  }
  // elbow_position
  geometry_msgs__msg__Point__fini(&msg->elbow_position);
  // wrist_position
  geometry_msgs__msg__Point__fini(&msg->wrist_position);
  // direction
  geometry_msgs__msg__Vector3__fini(&msg->direction);
  // length
  // width
}

bool
leap_msgs__msg__Arm__are_equal(const leap_msgs__msg__Arm * lhs, const leap_msgs__msg__Arm * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // elbow_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->elbow_position), &(rhs->elbow_position)))
  {
    return false;
  }
  // wrist_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->wrist_position), &(rhs->wrist_position)))
  {
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // length
  if (lhs->length != rhs->length) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  return true;
}

bool
leap_msgs__msg__Arm__copy(
  const leap_msgs__msg__Arm * input,
  leap_msgs__msg__Arm * output)
{
  if (!input || !output) {
    return false;
  }
  // elbow_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->elbow_position), &(output->elbow_position)))
  {
    return false;
  }
  // wrist_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->wrist_position), &(output->wrist_position)))
  {
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // length
  output->length = input->length;
  // width
  output->width = input->width;
  return true;
}

leap_msgs__msg__Arm *
leap_msgs__msg__Arm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Arm * msg = (leap_msgs__msg__Arm *)allocator.allocate(sizeof(leap_msgs__msg__Arm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(leap_msgs__msg__Arm));
  bool success = leap_msgs__msg__Arm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
leap_msgs__msg__Arm__destroy(leap_msgs__msg__Arm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    leap_msgs__msg__Arm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
leap_msgs__msg__Arm__Sequence__init(leap_msgs__msg__Arm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Arm * data = NULL;

  if (size) {
    data = (leap_msgs__msg__Arm *)allocator.zero_allocate(size, sizeof(leap_msgs__msg__Arm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = leap_msgs__msg__Arm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        leap_msgs__msg__Arm__fini(&data[i - 1]);
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
leap_msgs__msg__Arm__Sequence__fini(leap_msgs__msg__Arm__Sequence * array)
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
      leap_msgs__msg__Arm__fini(&array->data[i]);
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

leap_msgs__msg__Arm__Sequence *
leap_msgs__msg__Arm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Arm__Sequence * array = (leap_msgs__msg__Arm__Sequence *)allocator.allocate(sizeof(leap_msgs__msg__Arm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = leap_msgs__msg__Arm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
leap_msgs__msg__Arm__Sequence__destroy(leap_msgs__msg__Arm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    leap_msgs__msg__Arm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
leap_msgs__msg__Arm__Sequence__are_equal(const leap_msgs__msg__Arm__Sequence * lhs, const leap_msgs__msg__Arm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!leap_msgs__msg__Arm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
leap_msgs__msg__Arm__Sequence__copy(
  const leap_msgs__msg__Arm__Sequence * input,
  leap_msgs__msg__Arm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(leap_msgs__msg__Arm);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    leap_msgs__msg__Arm * data =
      (leap_msgs__msg__Arm *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!leap_msgs__msg__Arm__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          leap_msgs__msg__Arm__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!leap_msgs__msg__Arm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
