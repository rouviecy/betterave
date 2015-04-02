/*
 * @(#)		State_Python.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * State of the robot managed by python script
 */

#ifndef STATE_PYTHON
#define STATE_PYTHON

#include <iostream>
#include "../core/ComPython.h"

class State_Python : public ComPython{

public:

	State_Python();
	~State_Python();

private:

	float data_in;

	void On_start();
	void Job();
	void IO();

};

#endif
