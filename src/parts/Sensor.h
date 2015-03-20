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
#include "../interfaces/Serial.h"

class Sensor : public ComThread, Serial{

public:

	Sensor();
	~Sensor();

private:

	void Job();
	void IO();
	
	float data_out;

};

#endif
