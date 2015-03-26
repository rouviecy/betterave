/*
 * @(#)		Simple.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- generate fake dat sensor
 * 	- send it to state manager
 */

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
