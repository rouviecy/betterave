cmake_minimum_required(VERSION 2.8)
project(betterave)

find_package(PkgConfig)

# Beginning of custom zone

set(ENABLE_GRAPHVIZ ON)
set(ENABLE_PYTHON ON)
set(ENABLE_JAVA ON)
set(ENABLE_SDL ON)
set(JAVA_LIBMAWT_PATH /etc/java-config-2/current-system-vm/jre/lib/amd64/xawt)

# End of custom zone

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

if(${ENABLE_JAVA})
	find_package(Java REQUIRED)
	find_package(JNI REQUIRED)
	if(JNI_FOUND)
		include(UseJava)
		set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.6" "-target" "1.6")
		file(GLOB JAVA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/parts/java/*.java")
		add_jar(Java_parts ${JAVA_SOURCES})
		get_target_property(_jarFile Java_parts JAR_FILE)
		get_target_property(_classDir Java_parts CLASSDIR)
		add_definitions(-DENABLE_JAVA)
		include_directories(${JNI_INCLUDE_DIRS})
		find_library(JAVA_MAWT_LIBRARY mawt ${JAVA_LIBMAWT_PATH})
		set(LIBS ${LIBS} ${JNI_LIBRARIES} ${JAVA_JVM_LIBRARY} ${JAVA_AWT_LIBRARY} ${JAVA_MAWT_LIBRARY})
	endif(JNI_FOUND)
endif(${ENABLE_JAVA})

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
	src/core/ComJava.h		src/core/ComJava.cpp
	src/core/ComPython.h		src/core/ComPython.cpp
	src/core/ComThread.h		src/core/ComThread.cpp
	src/core/CoreJava.h		src/core/CoreJava.cpp
	src/core/Maestro.h		src/core/Maestro.cpp
	src/core/Share.h		src/core/Share.cpp
	src/interfaces/Joystick.h	src/interfaces/Joystick.cpp
	src/interfaces/Serial.h		src/interfaces/Serial.cpp
	src/parts/Sensor.h		src/parts/Sensor.cpp
	src/parts/Sensor_Java.h		src/parts/Sensor_Java.cpp
	src/parts/Sensor_Joystick.h	src/parts/Sensor_Joystick.cpp
	src/parts/State.h		src/parts/State.cpp
	src/parts/State_Python.h	src/parts/State_Python.cpp
)

add_executable(simple src/mains/Simple.cpp)
target_link_libraries(simple ${LIBS} BETTERAVE_LIBS)

add_executable(joystick_to_python src/mains/Joystick_to_python.cpp)
target_link_libraries(joystick_to_python ${LIBS} BETTERAVE_LIBS)

add_executable(java_to_python src/mains/Java_to_python.cpp)
target_link_libraries(java_to_python ${LIBS} BETTERAVE_LIBS)
