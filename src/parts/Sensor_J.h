/*
 * @(#)		Sensor_J.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * Grab data from joystick
 */

#ifndef SENSOR_J
#define SENSOR_J

#include "../core/ComThread.h"
#include "../interfaces/Joystick.h"

class Sensor_J : public ComThread{

public:

	Sensor_J();
	~Sensor_J();

private:

	Joystick joystick;

	void On_start();
	void Job();
	void IO();
	
	float data_out;

	int *data_joystick;

};

#endif
