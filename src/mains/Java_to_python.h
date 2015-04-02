/*
 * @(#)		Java_to_python.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- grab data from joystick
 * 	- send it to python state manager
 */

#ifndef JAVA_TO_PYTHON
#define JAVA_TO_PYTHON

#include "../core/CoreJava.h"
#include "../core/Maestro.h"
#include "../parts/Sensor_Java.h"
#include "../parts/State_Python.h"

class Java_to_python : public Maestro{

public:

	Java_to_python();
	void Shutdown();

private:

	CoreJava corejava;
	Sensor_Java sensor;
	State_Python state;

};

#endif
