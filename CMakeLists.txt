cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_library(BETTERAVE_LIBS
	src/core/ComDraw.h		src/core/ComDraw.cpp
	src/core/ComThread.h	src/core/ComThread.cpp
	src/core/Share.h		src/core/Share.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
	src/parts/State.h		src/parts/State.cpp
	src/Robot.h				src/Robot.cpp
)

add_executable(example src/mains/example.cpp)
target_link_libraries(example BETTERAVE_LIBS)
