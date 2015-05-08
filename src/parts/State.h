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

class State : public ComThread{

public:

	State();
	~State();

private:

	void On_start();
	void Job();
	void IO();

	float data_in;
	float data_in_array[2];
};

#endif
