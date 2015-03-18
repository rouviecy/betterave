/*
 * @(#)		Robot.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A robot
 */

#ifndef ROBOT
#define ROBOT

#include <vector>
#include "core/Share.h"
#include "core/ComDraw.h"
#include "core/ComThread.h"
#include "parts/Sensor.h"
#include "parts/State.h"

class Robot{

public:

	Robot();

private:

	std::vector <ComThread*> threads;

	void Link_all();
	void Launch_all();
	void Join_all();

	ComDraw drawer;
	Share share;

	Sensor sensor;
	State state;
};

#endif
