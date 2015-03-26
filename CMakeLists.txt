cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

set(ENABLE_GRAPHVIZ ON)
set(ENABLE_PYTHON ON)
set(ENABLE_SDL ON)

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

if(${ENABLE_SDL})
	pkg_search_module(SDL2 REQUIRED sdl2)
	if(SDL2_FOUND)
		add_definitions(-DENABLE_SDL)
		set(LIBS ${LIBS} ${SDL2_LIBRARIES})
	endif(SDL2_FOUND)
endif(${ENABLE_SDL})

if(${ENABLE_PYTHON})
	find_package(PythonLibs REQUIRED)
	if(PYTHONLIBS_FOUND)
		add_definitions(-DENABLE_PYTHON)
		include_directories(${PYTHON_INCLUDE_DIRS})
		set(LIBS ${LIBS} ${PYTHON_LIBRARIES})
	endif(PYTHONLIBS_FOUND)
endif(${ENABLE_PYTHON})

add_library(BETTERAVE_LIBS
	src/core/ComDraw.h		src/core/ComDraw.cpp
	src/core/ComPython.h		src/core/ComPython.cpp
	src/core/ComThread.h		src/core/ComThread.cpp
	src/core/Maestro.h		src/core/Maestro.cpp
	src/core/Share.h		src/core/Share.cpp
	src/interfaces/Joystick.h	src/interfaces/Joystick.cpp
	src/interfaces/Serial.h		src/interfaces/Serial.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
	src/parts/Sensor_J.h		src/parts/Sensor_J.cpp
	src/parts/State.h		src/parts/State.cpp
	src/parts/State_P.h		src/parts/State_P.cpp
)

add_executable(joystick_to_python src/mains/Joystick_to_python.cpp)
target_link_libraries(joystick_to_python ${LIBS} BETTERAVE_LIBS)

add_executable(simple src/mains/Simple.cpp)
target_link_libraries(simple ${LIBS} BETTERAVE_LIBS)
