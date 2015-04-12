/*
 * @(#)		Sensor_TCP_client.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * A sensor providing data by TCP
 */

#ifndef SENSOR_TCP_CLIENT
#define SENSOR_TCP_CLIENT

#include "../core/ComThread.h"
#include "../interfaces/TCP_client.h"

class Sensor_TCP_client : public ComThread{

public:

	Sensor_TCP_client();
	~Sensor_TCP_client();

	void Connect_to_server();

private:

	TCP_client tcp_client;

	void On_start();
	void Job();
	void IO();
	
	int i;

};

#endif
