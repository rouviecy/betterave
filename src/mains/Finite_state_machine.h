/*
 * @(#)		Finite_state_machine.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- generate fake data sensor
 * 	- send it to a finite state machine
 */

#ifndef FINITE_STATE_MACHINE
#define FINITE_STATE_MACHINE

#include "../core/Maestro.h"
#include "../parts/Sensor.h"
#include "../parts/State_machine.h"

class Finite_state_machine : public Maestro{

public:

	Finite_state_machine();
	void Shutdown();

private:

	Sensor sensor;
	State_machine state;

};

#endif
