/*
 * @(#)		Sensor_Joystick.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * Grab data from joystick
 */

#ifndef SENSOR_JOYSTICK
#define SENSOR_JOYSTICK

#include "../core/ComThread.h"
#include "../interfaces/Joystick.h"

class Sensor_Joystick : public ComThread{

public:

	Sensor_Joystick();
	~Sensor_Joystick();

private:

	Joystick joystick;

	void On_start();
	void Job();
	void IO();
	
	float data_out;

	int *data_joystick;

};

#endif
