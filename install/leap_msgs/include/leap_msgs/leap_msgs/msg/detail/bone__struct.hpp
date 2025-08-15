// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from leap_msgs:msg/Bone.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_HPP_
#define LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'prev_joint'
// Member 'next_joint'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'direction'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__leap_msgs__msg__Bone __attribute__((deprecated))
#else
# define DEPRECATED__leap_msgs__msg__Bone __declspec(deprecated)
#endif

namespace leap_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Bone_
{
  using Type = Bone_<ContainerAllocator>;

  explicit Bone_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : prev_joint(_init),
    next_joint(_init),
    direction(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->length = 0.0f;
      this->width = 0.0f;
    }
  }

  explicit Bone_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : prev_joint(_alloc, _init),
    next_joint(_alloc, _init),
    direction(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->length = 0.0f;
      this->width = 0.0f;
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _prev_joint_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _prev_joint_type prev_joint;
  using _next_joint_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _next_joint_type next_joint;
  using _direction_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _direction_type direction;
  using _length_type =
    float;
  _length_type length;
  using _width_type =
    float;
  _width_type width;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__prev_joint(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->prev_joint = _arg;
    return *this;
  }
  Type & set__next_joint(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->next_joint = _arg;
    return *this;
  }
  Type & set__direction(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__length(
    const float & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    leap_msgs::msg::Bone_<ContainerAllocator> *;
  using ConstRawPtr =
    const leap_msgs::msg::Bone_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<leap_msgs::msg::Bone_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<leap_msgs::msg::Bone_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Bone_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Bone_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Bone_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Bone_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<leap_msgs::msg::Bone_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<leap_msgs::msg::Bone_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__leap_msgs__msg__Bone
    std::shared_ptr<leap_msgs::msg::Bone_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__leap_msgs__msg__Bone
    std::shared_ptr<leap_msgs::msg::Bone_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Bone_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->prev_joint != other.prev_joint) {
      return false;
    }
    if (this->next_joint != other.next_joint) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    return true;
  }
  bool operator!=(const Bone_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Bone_

// alias to use template instance with default allocator
using Bone =
  leap_msgs::msg::Bone_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__BONE__STRUCT_HPP_
