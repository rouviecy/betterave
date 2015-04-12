/*
 * @(#)		TCP_listener.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * A robot example :
 * 	- generate fake data sensor by TCP
 * 	- send it to state manager
 */

#ifndef TCP_LISTENER
#define TCP_LISTENER

#include "../core/Maestro.h"
#include "../parts/Sensor_TCP_client.h"
#include "../parts/Sensor_TCP_server.h"
#include "../parts/State.h"

class TCP_listener : public Maestro{

public:

	TCP_listener();
	void Shutdown();

private:

	Sensor_TCP_server sensor;
	Sensor_TCP_client sensor_fake;
	State state;

};

#endif
