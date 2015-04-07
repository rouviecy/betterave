# Betterave Tutorial

## Install Betterave and dependencies

If you only want to use Betterave, download and unzip its sources :  
https://github.com/rouviecy/betterave/archive/master.zip

If you want to contribute, install Git and clone the repository :

    sudo apt-get install git
    git clone https://github.com/rouviecy/betterave

You will need GCC and CMake to compile your project :

    sudo apt-get install build-essential cmake

Moreover, you can add optional features :

    sudo apt-get install graphviz
    sudo apt-get install openjdk-6-jdk
    sudo apt-get install python-dev
    sudo apt-get install libsdl2-dev

1. Graphviz provides you a tool to generate a graph showing connexions between your threads
2. OpenJDK with JNI allows you to write Java threads
3. Python with C-API allows you to write Python threads
4. SDL2 adds joystick management

## Create your project

Your main program must be written in `src/main` directory. It will call thread files you write in `src/parts` directory. You do not have to write in `src/core` and `src/interfaces` which provide you Betterave functionnalities and plugins.

In this example, we will create a sensor `src/parts/Sensor.cpp` which provide a floating number `my_data` that a state manager `src/parts/State.cpp` has to process. The robot is simulated by `src/mains/Simple.cpp`.

Sensor and State should inherit `src/core/ComThread.cpp`. So create two headers :

`src/parts/Sensor.h` :

    #ifndef SENSOR_H
    #define SENSOR_H
    #include "../core/ComThread.h"

    class Sensor : public ComThread{
        public:
        	Sensor(); ~Sensor();
        private:
    	    void IO();
    	    void On_start();
    	    void Job();
    	    float data_out;
        };

    #endif

`src/parts/State.h`

    #ifndef STATE_H
    #define STATE_H
    #include "../core/ComThread.h"

    class Sensor : public ComThread{
        public:
        	State(); ~State();
        private:
        	void IO();
    	    void On_start();
    	    void Job();
    	    float data_in;
        };

    #endif

Three methods must be overwritten :  `IO()`, `On_start()` and `Job()`.

`IO()` is intented to link the object to the sharing environment with `Link_input(string key, float* p_float)` for incoming data, and `Link_output(string key, float* p_float)` for outgoing data. `key` is a string that all threads use for the same data, while `p_float` is a pointer to a local variable which has to be linked with this shared data. When `Critical_receive()` is called, each `p_float` will receive value from shared environment. When `Critical_send()` is called, each `p_float` will write its value on shared environment.

`On_start()` is automatically called at the begining of the thread. You do not have to write something in, but it must be present.

`Job()` represents what is done in the loop. Generally, you first call `Critical_receive()` to update your data, then you do your stuff with it, and finally you publish your results with `Critical_send()`.

`src/parts/Sensor.cpp`

    #include "Sensor.h"
    using namespace std;
    
    Sensor::Sensor() : ComThread(){
    	data_out = 0.;
    }
    
    Sensor::~Sensor(){}
    void Sensor::On_start(){}
    
    void Sensor::IO(){
    	Link_output("my_data", &data_out);
    }
    
    void Sensor::Job(){
    	data_out += 1.;
    	Critical_send();
    }

`src/parts/State.cpp`

    #include "State.h"
    using namespace std;
    
    State::State() : ComThread(){}
    State::~State(){}
    void State::On_start(){}
    
    void State::IO(){
    	Link_input("my_data", &data_in);
    }
    
    void State::Job(){
    	Critical_receive();
    	cout << "Received data : " << data_in << endl;
    }

In this example, Sensor links its local float number `data_out` to `my_data`, increments its each time `Job()` is called, and sends it to State which update its local float number `data_in` to show it in terminal.

In order to control these two parts, you have to write a class which inherits from `src/core/Maestro.cpp` :

`src/mains/Simple.h`

    #ifndef SIMPLE
    #define SIMPLE
    #include "../core/Maestro.h"
    #include "../parts/Sensor.h"
    #include "../parts/State.h"
    
    class Simple : public Maestro{
        public:
        	Simple();
        	void Shutdown();
        private:
        	Sensor sensor;
        	State state;
    };
    
    #endif

`src/mains/Simple.cpp`

    #include "Simple.h"
    using namespace std;
    
    Simple::Simple() : Maestro(){
    	Add_thread(&sensor,	"My sensor",		10000);		// 10 ms
    	Add_thread(&state,	"My state manager",	1000000);	// 1 s
    	Link_all();
    	Draw("coms");
    	Launch_all();
    }
    
    void Simple::Shutdown(){
    	Join_all();
    }
    
    int main(){
    	Simple robot;
    	usleep(5000000);
    	robot.Shutdown();
    	return 0;
    }

Here, `Add_thread(...)` puts your sensor and state manager in the list of threads which will be linked and launched by `Link_all()` and `Launch_all()`, at a frequency of 100Hz and 1Hz. `Draw("coms")` provides a connection graph in `build/test/coms.png`. After 5s, `Shutdown()` stops every threads to kill the robot and exit program.

That's all !

## Configuring your project for compiling

Parameters should be set in `CMakeLists.txt`. First, enable or disable optional features (SDL, Python, Java, ...). If you want Java, you have to adjust `JAVA_LIBMAWT_PATH` to indicate where to find mawt library. Betterave core building parameters are provided by `src/core/CMakeLists.txt`.

Then, add parts you have created and used interfaces in `BETTERAVE_USER`. And add executable for your `src/mains/...`. For the previous example, you should have :

`CMakeLists.txt`

    cmake_minimum_required(VERSION 2.8)
    project(betterave)
    
    find_package(PkgConfig)
    
    set(ENABLE_GRAPHVIZ ON)
    set(ENABLE_PYTHON OFF)
    set(ENABLE_JAVA OFF)
    set(ENABLE_SDL OFF)
    set(JAVA_LIBMAWT_PATH /etc/java-config-2/current-system-vm/jre/lib/amd64/xawt)
    
    include(${CMAKE_CURRENT_SOURCE_DIR}/src/core/CMakeLists.txt)
    
    add_library(BETTERAVE_USER
        src/parts/Sensor.h		src/parts/Sensor.cpp
        src/parts/State.h		src/parts/State.cpp
    )
    
    add_executable(simple src/mains/Simple.cpp)
    target_link_libraries(simple ${LIBS} BETTERAVE_USER BETTERAVE_CORE)

## Compile and execute

    cd betterave
    mkdir build
    cd build
    mkdir test
    cmake ..
    make
    ./simple
