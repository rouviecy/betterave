#BETTERAVE
Better Autonomous Vehicles Engine

## Why ?
Easy communication between threads, which is useful for Robotics (publisher/subscriber communication inspired from Robot Operating System http://www.ros.org). Each thread can be written in C++, Java or Python ; and you do not have to be concerned about how it works ! Simply overwrite some methods provided by this middleware, and your threads will communicate.

## Dependencies
+    **CMake**
+    **GCC** for c++11
+    **GNU/Linux** (not tested on Windows and MAC OS)

## Optional (can be enabled in `CMakeLists.txt`)
+    **Graphviz** to generate connexion graph
+    **Java Native Interface** to communicate with Java6 code (needs to set JAVA_LIBMAWT_PATH)
+    **Python3 C-API** to communicate with python scripts
+    **SDL2** to listen joystick (and draw soon)

## To compile and execute
    git clone https://github.com/rouviecy/betterave
    cd betterave
    mkdir build
    cd build
    mkdir test
    cmake ..
    make
    ./simple