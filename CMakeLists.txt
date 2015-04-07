cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

set(ENABLE_GRAPHVIZ ON)
set(ENABLE_PYTHON ON)
set(ENABLE_JAVA ON)
set(ENABLE_SDL ON)
set(JAVA_LIBMAWT_PATH /etc/java-config-2/current-system-vm/jre/lib/amd64/xawt)

include(${CMAKE_CURRENT_SOURCE_DIR}/src/core/CMakeLists.txt)

add_library(BETTERAVE_USER
	src/interfaces/Joystick.h	src/interfaces/Joystick.cpp
	src/interfaces/Serial.h		src/interfaces/Serial.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
	src/parts/Sensor_Java.h		src/parts/Sensor_Java.cpp
	src/parts/Sensor_Joystick.h	src/parts/Sensor_Joystick.cpp
	src/parts/State.h		src/parts/State.cpp
	src/parts/State_Python.h	src/parts/State_Python.cpp
)

add_executable(simple src/mains/Simple.cpp)
target_link_libraries(simple ${LIBS} BETTERAVE_USER BETTERAVE_CORE)

add_executable(joystick_to_python src/mains/Joystick_to_python.cpp)
target_link_libraries(joystick_to_python ${LIBS} BETTERAVE_USER BETTERAVE_CORE)

add_executable(java_to_python src/mains/Java_to_python.cpp)
target_link_libraries(java_to_python ${LIBS} BETTERAVE_USER BETTERAVE_CORE)
