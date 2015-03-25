/*
 * @(#)		Robot.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- grab data from joystick
 * 	- send it to state manager
 */

#ifndef ROBOT
#define ROBOT

#include "core/Maestro.h"
#include "parts/Sensor.h"
#include "parts/State.h"

class Robot : public Maestro{

public:

	Robot();
	void Shutdown();

private:

	Sensor sensor;
	State state;

};

#endif
