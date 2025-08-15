// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from leap_msgs:msg/Arm.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__ARM__FUNCTIONS_H_
#define LEAP_MSGS__MSG__DETAIL__ARM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "leap_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "leap_msgs/msg/detail/arm__struct.h"

/// Initialize msg/Arm message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * leap_msgs__msg__Arm
 * )) before or use
 * leap_msgs__msg__Arm__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__init(leap_msgs__msg__Arm * msg);

/// Finalize msg/Arm message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
void
leap_msgs__msg__Arm__fini(leap_msgs__msg__Arm * msg);

/// Create msg/Arm message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * leap_msgs__msg__Arm__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
leap_msgs__msg__Arm *
leap_msgs__msg__Arm__create();

/// Destroy msg/Arm message.
/**
 * It calls
 * leap_msgs__msg__Arm__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
void
leap_msgs__msg__Arm__destroy(leap_msgs__msg__Arm * msg);

/// Check for msg/Arm message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__are_equal(const leap_msgs__msg__Arm * lhs, const leap_msgs__msg__Arm * rhs);

/// Copy a msg/Arm message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__copy(
  const leap_msgs__msg__Arm * input,
  leap_msgs__msg__Arm * output);

/// Initialize array of msg/Arm messages.
/**
 * It allocates the memory for the number of elements and calls
 * leap_msgs__msg__Arm__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__Sequence__init(leap_msgs__msg__Arm__Sequence * array, size_t size);

/// Finalize array of msg/Arm messages.
/**
 * It calls
 * leap_msgs__msg__Arm__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
void
leap_msgs__msg__Arm__Sequence__fini(leap_msgs__msg__Arm__Sequence * array);

/// Create array of msg/Arm messages.
/**
 * It allocates the memory for the array and calls
 * leap_msgs__msg__Arm__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
leap_msgs__msg__Arm__Sequence *
leap_msgs__msg__Arm__Sequence__create(size_t size);

/// Destroy array of msg/Arm messages.
/**
 * It calls
 * leap_msgs__msg__Arm__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
void
leap_msgs__msg__Arm__Sequence__destroy(leap_msgs__msg__Arm__Sequence * array);

/// Check for msg/Arm message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__Sequence__are_equal(const leap_msgs__msg__Arm__Sequence * lhs, const leap_msgs__msg__Arm__Sequence * rhs);

/// Copy an array of msg/Arm messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_leap_msgs
bool
leap_msgs__msg__Arm__Sequence__copy(
  const leap_msgs__msg__Arm__Sequence * input,
  leap_msgs__msg__Arm__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LEAP_MSGS__MSG__DETAIL__ARM__FUNCTIONS_H_
