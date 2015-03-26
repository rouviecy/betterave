/*
 * @(#)		Joystick_to_python.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- grab data from joystick
 * 	- send it to python state manager
 */

#ifndef JOYSTICK_TO_PYTHON
#define JOYSTICK_TO_PYTHON

#include "../core/Maestro.h"
#include "../parts/Sensor_J.h"
#include "../parts/State_P.h"

class Joystick_to_python : public Maestro{

public:

	Joystick_to_python();
	void Shutdown();

private:

	Sensor_J sensor;
	State_P state;

};

#endif
