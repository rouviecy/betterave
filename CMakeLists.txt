cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

set(ENABLE_GRAPHVIZ ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

if(${ENABLE_GRAPHVIZ})
	pkg_check_modules(GVC REQUIRED libgvc)
	if(GVC_FOUND)
		add_definitions(-DENABLE_GRAPHVIZ)
		include_directories(${GVC_INCLUDE_DIRS})
		link_directories(${GVC_LIBRARY_DIRS})
		set(LIBS ${LIBS} ${GVC_LIBRARIES})
	endif(GVC_FOUND)
endif(${ENABLE_GRAPHVIZ})

add_library(BETTERAVE_LIBS
	src/core/ComDraw.h		src/core/ComDraw.cpp
	src/core/ComThread.h	src/core/ComThread.cpp
	src/core/Maestro.h		src/core/Maestro.cpp
	src/core/Share.h		src/core/Share.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
	src/parts/State.h		src/parts/State.cpp
	src/Robot.h				src/Robot.cpp
)

add_executable(example src/mains/example.cpp)
target_link_libraries(example ${LIBS} BETTERAVE_LIBS)
