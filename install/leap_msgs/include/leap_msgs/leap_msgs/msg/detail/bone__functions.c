// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from leap_msgs:msg/Bone.idl
// generated code does not contain a copyright notice
#include "leap_msgs/msg/detail/bone__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `prev_joint`
// Member `next_joint`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `direction`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
leap_msgs__msg__Bone__init(leap_msgs__msg__Bone * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // prev_joint
  if (!geometry_msgs__msg__Point__init(&msg->prev_joint)) {
    leap_msgs__msg__Bone__fini(msg);
    return false;
  }
  // next_joint
  if (!geometry_msgs__msg__Point__init(&msg->next_joint)) {
    leap_msgs__msg__Bone__fini(msg);
    return false;
  }
  // direction
  if (!geometry_msgs__msg__Vector3__init(&msg->direction)) {
    leap_msgs__msg__Bone__fini(msg);
    return false;
  }
  // length
  // width
  return true;
}

void
leap_msgs__msg__Bone__fini(leap_msgs__msg__Bone * msg)
{
  if (!msg) {
    return;
  }
  // type
  // prev_joint
  geometry_msgs__msg__Point__fini(&msg->prev_joint);
  // next_joint
  geometry_msgs__msg__Point__fini(&msg->next_joint);
  // direction
  geometry_msgs__msg__Vector3__fini(&msg->direction);
  // length
  // width
}

bool
leap_msgs__msg__Bone__are_equal(const leap_msgs__msg__Bone * lhs, const leap_msgs__msg__Bone * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // prev_joint
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->prev_joint), &(rhs->prev_joint)))
  {
    return false;
  }
  // next_joint
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->next_joint), &(rhs->next_joint)))
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
leap_msgs__msg__Bone__copy(
  const leap_msgs__msg__Bone * input,
  leap_msgs__msg__Bone * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // prev_joint
  if (!geometry_msgs__msg__Point__copy(
      &(input->prev_joint), &(output->prev_joint)))
  {
    return false;
  }
  // next_joint
  if (!geometry_msgs__msg__Point__copy(
      &(input->next_joint), &(output->next_joint)))
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

leap_msgs__msg__Bone *
leap_msgs__msg__Bone__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Bone * msg = (leap_msgs__msg__Bone *)allocator.allocate(sizeof(leap_msgs__msg__Bone), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(leap_msgs__msg__Bone));
  bool success = leap_msgs__msg__Bone__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
leap_msgs__msg__Bone__destroy(leap_msgs__msg__Bone * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    leap_msgs__msg__Bone__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
leap_msgs__msg__Bone__Sequence__init(leap_msgs__msg__Bone__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Bone * data = NULL;

  if (size) {
    data = (leap_msgs__msg__Bone *)allocator.zero_allocate(size, sizeof(leap_msgs__msg__Bone), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = leap_msgs__msg__Bone__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        leap_msgs__msg__Bone__fini(&data[i - 1]);
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
leap_msgs__msg__Bone__Sequence__fini(leap_msgs__msg__Bone__Sequence * array)
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
      leap_msgs__msg__Bone__fini(&array->data[i]);
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

leap_msgs__msg__Bone__Sequence *
leap_msgs__msg__Bone__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Bone__Sequence * array = (leap_msgs__msg__Bone__Sequence *)allocator.allocate(sizeof(leap_msgs__msg__Bone__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = leap_msgs__msg__Bone__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
leap_msgs__msg__Bone__Sequence__destroy(leap_msgs__msg__Bone__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    leap_msgs__msg__Bone__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
leap_msgs__msg__Bone__Sequence__are_equal(const leap_msgs__msg__Bone__Sequence * lhs, const leap_msgs__msg__Bone__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!leap_msgs__msg__Bone__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
leap_msgs__msg__Bone__Sequence__copy(
  const leap_msgs__msg__Bone__Sequence * input,
  leap_msgs__msg__Bone__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(leap_msgs__msg__Bone);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    leap_msgs__msg__Bone * data =
      (leap_msgs__msg__Bone *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!leap_msgs__msg__Bone__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          leap_msgs__msg__Bone__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!leap_msgs__msg__Bone__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
