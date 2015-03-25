/*
 * @(#)		Sensor.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A sensor providing data
 */

#ifndef SENSOR
#define SENSOR

#include "../core/ComThread.h"
#include "../interfaces/Joystick.h"

class Sensor : public ComThread{

public:

	Sensor();
	~Sensor();

private:

	Joystick joystick;

	void Job();
	void IO();
	
	float data_out;

	int *data_joystick;

};

#endif
