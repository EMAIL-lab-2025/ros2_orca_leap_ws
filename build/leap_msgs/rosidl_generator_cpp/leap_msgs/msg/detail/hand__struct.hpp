// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from leap_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_
#define LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'velocity'
// Member 'normal'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"
// Member 'fingers'
#include "leap_msgs/msg/detail/finger__struct.hpp"
// Member 'arm'
#include "leap_msgs/msg/detail/arm__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__leap_msgs__msg__Hand __attribute__((deprecated))
#else
# define DEPRECATED__leap_msgs__msg__Hand __declspec(deprecated)
#endif

namespace leap_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Hand_
{
  using Type = Hand_<ContainerAllocator>;

  explicit Hand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    velocity(_init),
    normal(_init),
    orientation(_init),
    arm(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->grab_strength = 0.0f;
      this->pinch_strength = 0.0f;
    }
  }

  explicit Hand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    position(_alloc, _init),
    velocity(_alloc, _init),
    normal(_alloc, _init),
    orientation(_alloc, _init),
    arm(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->grab_strength = 0.0f;
      this->pinch_strength = 0.0f;
    }
  }

  // field types and members
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;
  using _normal_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _normal_type normal;
  using _orientation_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _orientation_type orientation;
  using _grab_strength_type =
    float;
  _grab_strength_type grab_strength;
  using _pinch_strength_type =
    float;
  _pinch_strength_type pinch_strength;
  using _fingers_type =
    std::vector<leap_msgs::msg::Finger_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<leap_msgs::msg::Finger_<ContainerAllocator>>>;
  _fingers_type fingers;
  using _arm_type =
    leap_msgs::msg::Arm_<ContainerAllocator>;
  _arm_type arm;

  // setters for named parameter idiom
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__normal(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->normal = _arg;
    return *this;
  }
  Type & set__orientation(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__grab_strength(
    const float & _arg)
  {
    this->grab_strength = _arg;
    return *this;
  }
  Type & set__pinch_strength(
    const float & _arg)
  {
    this->pinch_strength = _arg;
    return *this;
  }
  Type & set__fingers(
    const std::vector<leap_msgs::msg::Finger_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<leap_msgs::msg::Finger_<ContainerAllocator>>> & _arg)
  {
    this->fingers = _arg;
    return *this;
  }
  Type & set__arm(
    const leap_msgs::msg::Arm_<ContainerAllocator> & _arg)
  {
    this->arm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    leap_msgs::msg::Hand_<ContainerAllocator> *;
  using ConstRawPtr =
    const leap_msgs::msg::Hand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<leap_msgs::msg::Hand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<leap_msgs::msg::Hand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Hand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Hand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      leap_msgs::msg::Hand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<leap_msgs::msg::Hand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<leap_msgs::msg::Hand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<leap_msgs::msg::Hand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__leap_msgs__msg__Hand
    std::shared_ptr<leap_msgs::msg::Hand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__leap_msgs__msg__Hand
    std::shared_ptr<leap_msgs::msg::Hand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hand_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->normal != other.normal) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->grab_strength != other.grab_strength) {
      return false;
    }
    if (this->pinch_strength != other.pinch_strength) {
      return false;
    }
    if (this->fingers != other.fingers) {
      return false;
    }
    if (this->arm != other.arm) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hand_

// alias to use template instance with default allocator
using Hand =
  leap_msgs::msg::Hand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace leap_msgs

#endif  // LEAP_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_
