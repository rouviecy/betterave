/*
 * @(#)		Sensor_Java.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * Grab data from java
 */

#ifndef SENSOR_JAVA
#define SENSOR_JAVA

#include "../core/ComJava.h"

class Sensor_Java : public ComJava{

public:

	Sensor_Java();
	~Sensor_Java();

private:

	void Job();
	void IO();
	
	float data_out;

};

#endif
