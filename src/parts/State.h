/*
 * @(#)		State.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * State of the robot
 */

#ifndef STATE
#define STATE

#include <iostream>
#include "../core/ComThread.h"
#include "../interfaces/Serial.h"

class State : public ComThread, Serial{

public:

	State();
	~State();

private:

	float data_in;

	void Job();
	void IO();

};

#endif
