cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

set(ENABLE_GRAPHVIZ ON)
set(ENABLE_PYTHON OFF)
set(ENABLE_JAVA OFF)
set(ENABLE_SDL ON)
set(JAVA_LIBMAWT_PATH /etc/java-config-2/current-system-vm/jre/lib/amd64/xawt)

include(${CMAKE_CURRENT_SOURCE_DIR}/src/core/CMakeLists.txt)

add_library(BETTERAVE_USER
	src/interfaces/FSM.h		src/interfaces/FSM.cpp
	src/interfaces/FSMDraw.h	src/interfaces/FSMDraw.cpp
	src/interfaces/Joystick.h	src/interfaces/Joystick.cpp
	src/interfaces/Serial.h		src/interfaces/Serial.cpp
	src/interfaces/SPI.h			src/interfaces/SPI.cpp
	src/interfaces/TCP_client.h	src/interfaces/TCP_client.cpp
	src/interfaces/TCP_server.h	src/interfaces/TCP_server.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
#	src/parts/Sensor_Java.h		src/parts/Sensor_Java.cpp
	src/parts/Sensor_Joystick.h	src/parts/Sensor_Joystick.cpp
	src/parts/Sensor_TCP_client.h	src/parts/Sensor_TCP_client.cpp
	src/parts/Sensor_TCP_server.h	src/parts/Sensor_TCP_server.cpp
	src/parts/State.h		src/parts/State.cpp
	src/parts/State_machine.h	src/parts/State_machine.cpp
#	src/parts/State_Python.h	src/parts/State_Python.cpp
	src/interfaces/Maths_tools.h
)

add_executable(simple src/mains/Simple.cpp)
target_link_libraries(simple BETTERAVE_USER BETTERAVE_CORE ${LIBS})

#add_executable(joystick_to_python src/mains/Joystick_to_python.cpp)
#target_link_libraries(joystick_to_python BETTERAVE_USER BETTERAVE_CORE ${LIBS})

#add_executable(java_to_python src/mains/Java_to_python.cpp)
#target_link_libraries(java_to_python BETTERAVE_USER BETTERAVE_CORE ${LIBS})

add_executable(tcp_listener src/mains/TCP_listener.cpp)
target_link_libraries(tcp_listener BETTERAVE_USER BETTERAVE_CORE ${LIBS})

add_executable(finite_state_machine src/mains/Finite_state_machine.cpp)
target_link_libraries(finite_state_machine BETTERAVE_USER BETTERAVE_CORE ${LIBS})
