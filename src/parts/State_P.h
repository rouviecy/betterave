/*
 * @(#)		State_P.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * State of the robot managed by python script
 */

#ifndef STATE_P
#define STATE_P

#include <iostream>
#include "../core/ComPython.h"

class State_P : public ComPython{

public:

	State_P();
	~State_P();

private:

	float data_in;

	void Job();
	void IO();

};

#endif
