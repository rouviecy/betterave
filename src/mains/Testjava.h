/*
 * @(#)		Testjava.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- grab data from joystick
 * 	- send it to python state manager
 */

#ifndef TESTJAVA
#define TESTJAVA

#include "../core/Maestro.h"
#include "../parts/Sensor_Java.h"
#include "../parts/State_P.h"

class Testjava : public Maestro{

public:

	Testjava();
	void Shutdown();

private:

	Sensor_Java sensor;
	State_P state;

};

#endif
