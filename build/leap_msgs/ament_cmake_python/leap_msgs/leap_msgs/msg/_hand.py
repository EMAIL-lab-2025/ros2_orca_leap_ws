# generated from rosidl_generator_py/resource/_idl.py.em
# with input from leap_msgs:msg/Hand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Hand(type):
    """Metaclass of message 'Hand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('leap_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'leap_msgs.msg.Hand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hand
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hand
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hand
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hand
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hand

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from leap_msgs.msg import Arm
            if Arm.__class__._TYPE_SUPPORT is None:
                Arm.__class__.__import_type_support__()

            from leap_msgs.msg import Finger
            if Finger.__class__._TYPE_SUPPORT is None:
                Finger.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Hand(metaclass=Metaclass_Hand):
    """Message class 'Hand'."""

    __slots__ = [
        '_type',
        '_position',
        '_velocity',
        '_normal',
        '_orientation',
        '_grab_strength',
        '_pinch_strength',
        '_fingers',
        '_arm',
    ]

    _fields_and_field_types = {
        'type': 'string',
        'position': 'geometry_msgs/Point',
        'velocity': 'geometry_msgs/Vector3',
        'normal': 'geometry_msgs/Vector3',
        'orientation': 'geometry_msgs/Quaternion',
        'grab_strength': 'float',
        'pinch_strength': 'float',
        'fingers': 'sequence<leap_msgs/Finger>',
        'arm': 'leap_msgs/Arm',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['leap_msgs', 'msg'], 'Finger')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['leap_msgs', 'msg'], 'Arm'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', str())
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        from geometry_msgs.msg import Vector3
        self.velocity = kwargs.get('velocity', Vector3())
        from geometry_msgs.msg import Vector3
        self.normal = kwargs.get('normal', Vector3())
        from geometry_msgs.msg import Quaternion
        self.orientation = kwargs.get('orientation', Quaternion())
        self.grab_strength = kwargs.get('grab_strength', float())
        self.pinch_strength = kwargs.get('pinch_strength', float())
        self.fingers = kwargs.get('fingers', [])
        from leap_msgs.msg import Arm
        self.arm = kwargs.get('arm', Arm())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.type != other.type:
            return False
        if self.position != other.position:
            return False
        if self.velocity != other.velocity:
            return False
        if self.normal != other.normal:
            return False
        if self.orientation != other.orientation:
            return False
        if self.grab_strength != other.grab_strength:
            return False
        if self.pinch_strength != other.pinch_strength:
            return False
        if self.fingers != other.fingers:
            return False
        if self.arm != other.arm:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'type' field must be of type 'str'"
        self._type = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'velocity' field must be a sub message of type 'Vector3'"
        self._velocity = value

    @builtins.property
    def normal(self):
        """Message field 'normal'."""
        return self._normal

    @normal.setter
    def normal(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'normal' field must be a sub message of type 'Vector3'"
        self._normal = value

    @builtins.property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'orientation' field must be a sub message of type 'Quaternion'"
        self._orientation = value

    @builtins.property
    def grab_strength(self):
        """Message field 'grab_strength'."""
        return self._grab_strength

    @grab_strength.setter
    def grab_strength(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'grab_strength' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'grab_strength' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._grab_strength = value

    @builtins.property
    def pinch_strength(self):
        """Message field 'pinch_strength'."""
        return self._pinch_strength

    @pinch_strength.setter
    def pinch_strength(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pinch_strength' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pinch_strength' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pinch_strength = value

    @builtins.property
    def fingers(self):
        """Message field 'fingers'."""
        return self._fingers

    @fingers.setter
    def fingers(self, value):
        if __debug__:
            from leap_msgs.msg import Finger
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Finger) for v in value) and
                 True), \
                "The 'fingers' field must be a set or sequence and each value of type 'Finger'"
        self._fingers = value

    @builtins.property
    def arm(self):
        """Message field 'arm'."""
        return self._arm

    @arm.setter
    def arm(self, value):
        if __debug__:
            from leap_msgs.msg import Arm
            assert \
                isinstance(value, Arm), \
                "The 'arm' field must be a sub message of type 'Arm'"
        self._arm = value
