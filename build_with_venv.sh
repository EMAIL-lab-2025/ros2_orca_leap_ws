#!/bin/bash

echo "Activating virtual environment..."
source /home/xingyi/.venvs/leapc/bin/activate

echo "Building workspace..."
cd ~/ros2_orca_leap/ros2_orca_leap_ws

colcon build \
  --cmake-args \
    -DPython3_EXECUTABLE=/home/xingyi/.venvs/leapc/bin/python \
    -DPYTHON_EXECUTABLE=/home/xingyi/.venvs/leapc/bin/python

echo "Fixing shebang lines..."
find ./install/ -type f -executable -name "*" | while read file; do
    if head -n1 "$file" 2>/dev/null | grep -q "#!/usr/bin/python"; then
        sed -i '1s|#!/usr/bin/python.*|#!/home/xingyi/.venvs/leapc/bin/python|' "$file"
        echo "Fixed: $file"
    fi
done

echo "Build complete! Don't forget to source the setup file:"
echo "source install/setup.bash"
