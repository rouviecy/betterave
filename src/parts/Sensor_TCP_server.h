/*
 * @(#)		Sensor_TCP_server.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * A sensor providing data grabbed from TCP
 */

#ifndef SENSOR_TCP_SERVER
#define SENSOR_TCP_SERVER

#include "../core/ComThread.h"
#include "../interfaces/TCP_server.h"

class Sensor_TCP_server : public ComThread{

public:

	Sensor_TCP_server();
	~Sensor_TCP_server();

	void Stop();

private:

	TCP_server tcp_server;

	void On_start();
	void Job();
	void IO();

	bool go_on;
	float data_out;

};

#endif
