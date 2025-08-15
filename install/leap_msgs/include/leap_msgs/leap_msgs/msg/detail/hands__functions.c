// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from leap_msgs:msg/Hands.idl
// generated code does not contain a copyright notice
#include "leap_msgs/msg/detail/hands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `hands`
#include "leap_msgs/msg/detail/hand__functions.h"

bool
leap_msgs__msg__Hands__init(leap_msgs__msg__Hands * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    leap_msgs__msg__Hands__fini(msg);
    return false;
  }
  // hands
  if (!leap_msgs__msg__Hand__Sequence__init(&msg->hands, 0)) {
    leap_msgs__msg__Hands__fini(msg);
    return false;
  }
  return true;
}

void
leap_msgs__msg__Hands__fini(leap_msgs__msg__Hands * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // hands
  leap_msgs__msg__Hand__Sequence__fini(&msg->hands);
}

bool
leap_msgs__msg__Hands__are_equal(const leap_msgs__msg__Hands * lhs, const leap_msgs__msg__Hands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // hands
  if (!leap_msgs__msg__Hand__Sequence__are_equal(
      &(lhs->hands), &(rhs->hands)))
  {
    return false;
  }
  return true;
}

bool
leap_msgs__msg__Hands__copy(
  const leap_msgs__msg__Hands * input,
  leap_msgs__msg__Hands * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // hands
  if (!leap_msgs__msg__Hand__Sequence__copy(
      &(input->hands), &(output->hands)))
  {
    return false;
  }
  return true;
}

leap_msgs__msg__Hands *
leap_msgs__msg__Hands__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hands * msg = (leap_msgs__msg__Hands *)allocator.allocate(sizeof(leap_msgs__msg__Hands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(leap_msgs__msg__Hands));
  bool success = leap_msgs__msg__Hands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
leap_msgs__msg__Hands__destroy(leap_msgs__msg__Hands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    leap_msgs__msg__Hands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
leap_msgs__msg__Hands__Sequence__init(leap_msgs__msg__Hands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hands * data = NULL;

  if (size) {
    data = (leap_msgs__msg__Hands *)allocator.zero_allocate(size, sizeof(leap_msgs__msg__Hands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = leap_msgs__msg__Hands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        leap_msgs__msg__Hands__fini(&data[i - 1]);
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
leap_msgs__msg__Hands__Sequence__fini(leap_msgs__msg__Hands__Sequence * array)
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
      leap_msgs__msg__Hands__fini(&array->data[i]);
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

leap_msgs__msg__Hands__Sequence *
leap_msgs__msg__Hands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  leap_msgs__msg__Hands__Sequence * array = (leap_msgs__msg__Hands__Sequence *)allocator.allocate(sizeof(leap_msgs__msg__Hands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = leap_msgs__msg__Hands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
leap_msgs__msg__Hands__Sequence__destroy(leap_msgs__msg__Hands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    leap_msgs__msg__Hands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
leap_msgs__msg__Hands__Sequence__are_equal(const leap_msgs__msg__Hands__Sequence * lhs, const leap_msgs__msg__Hands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!leap_msgs__msg__Hands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
leap_msgs__msg__Hands__Sequence__copy(
  const leap_msgs__msg__Hands__Sequence * input,
  leap_msgs__msg__Hands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(leap_msgs__msg__Hands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    leap_msgs__msg__Hands * data =
      (leap_msgs__msg__Hands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!leap_msgs__msg__Hands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          leap_msgs__msg__Hands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!leap_msgs__msg__Hands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
