#BETTERAVE
Better Autonomous Vehicles Engine

## Warning
Python and Java support are currently broken (for new exchange types)

## Why ?
Easy communication between threads, which is useful for Robotics (publisher/subscriber communication inspired from Robot Operating System http://www.ros.org). Each thread can be written in C++, Java or Python ; and you do not have to be concerned about how it works ! Simply overwrite some methods provided by this middleware, and your threads will communicate.

## Dependencies
+    **CMake**
+    **GCC** for c++11
+    **GNU/Linux** (not tested on Windows and MAC OS)

## Optional (can be enabled in `CMakeLists.txt`)
+    **Graphviz** to generate connexion graph
+    **Java Native Interface** to communicate with Java6 or Java7 code (needs to set 
JAVA_LIBMAWT_PATH)
+    **Python3 C-API** to communicate with python scripts
+    **SDL2** to listen joystick (and draw soon)

## Supported languages
+    **C++**
+    **Java**
+    **Python3**

## Tutorial
See https://github.com/rouviecy/betterave/blob/master/Tuto.md
