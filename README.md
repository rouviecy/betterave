#BETTERAVE
Better Autonomous Vehicles Engine

## Why ?
Easy communication between threads, which is useful for Robotics (publisher/subscriber communication inspired from Robot Operating System http://www.ros.org)

## Dependencies
+    **CMake**
+    **GCC** for c++11
+    **GNU/Linux** (not tested on Windows and MAC OS)

## Optional (can be enabled in `CMakeLists.txt`)
+    **Graphviz** to generate connexion graph
+    **SDL2** to listen joystick (and draw soon)

## To compile and execute
    git clone https://github.com/rouviecy/betterave
    cd betterave
    mkdir build
    cd build
    mkdir test
    cmake ..
    make
    ./example