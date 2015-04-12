#include "Sensor_TCP_client.h"

using namespace std;

Sensor_TCP_client::Sensor_TCP_client() : ComThread(){
	i = 0.;
}

Sensor_TCP_client::~Sensor_TCP_client(){}

void Sensor_TCP_client::On_start(){}

void Sensor_TCP_client::IO(){}

void Sensor_TCP_client::Job(){
	tcp_client.Send(to_string(i));
	i++;
}

void Sensor_TCP_client::Connect_to_server(){
	tcp_client.Configure("127.0.0.1", 4242);
}
