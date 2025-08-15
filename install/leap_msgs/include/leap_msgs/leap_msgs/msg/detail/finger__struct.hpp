// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from leap_msgs:msg/Finger.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_HPP_
#define LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'tip_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'direction'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'bones'
#include "leap_msgs/msg/detail/bone__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__leap_msgs__msg__Finger __attribute__((deprecated))
#else
# define DEPRECATED__leap_msgs__msg__Finger __declspec(deprecated)
#endif

namespace leap_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Finger_
{
  using Type = Finger_<ContainerAllocator>;

  explicit Finger_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tip_position(_init),
    direction(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type = 0;
      this->length = 0.0f;
      this->width = 0.0f;
    }
  }

  explicit Finger_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tip_position(_alloc, _init),
    direction(_alloc, _init),
    velocity(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type = 0;
      this->length = 0.0f;
      this->width = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _type_type =
    uint8_t;
  _type_type type;
  using _tip_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _tip_position_type tip_position;
  using _direction_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _direction_type direction;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _length_type =
    float;
  _length_type length;
  using _width_type =
    float;
  _width_type width;
  using _bones_type =
    std::vector<leap_msgs::msg::Bone_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<leap_msgs::msg::Bone_<ContainerAllocator>>>;
  _bones_type bones;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__tip_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->tip_position = _arg;
    return *this;
  }
  Type & set__direction(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
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
  Type & set__bones(
    const std::vector<leap_msgs::msg::Bone_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<leap_msgs::msg::Bone_<ContainerAllocator>>> & _arg)
  {
    this->bones = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    leap_msgs::msg::Finger_<ContainerAllocator> *;
  using ConstRawPtr =
    const leap_msgs::msg::Finger_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<leap_msgs::msg::Finger_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<leap_msgs::msg::Finger_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Finger_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Finger_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Finger_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Finger_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<leap_msgs::msg::Finger_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<leap_msgs::msg::Finger_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__leap_msgs__msg__Finger
    std::shared_ptr<leap_msgs::msg::Finger_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__leap_msgs__msg__Finger
    std::shared_ptr<leap_msgs::msg::Finger_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Finger_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->tip_position != other.tip_position) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->bones != other.bones) {
      return false;
    }
    return true;
  }
  bool operator!=(const Finger_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Finger_

// alias to use template instance with default allocator
using Finger =
  leap_msgs::msg::Finger_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__FINGER__STRUCT_HPP_
