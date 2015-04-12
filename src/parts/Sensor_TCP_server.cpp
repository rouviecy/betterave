#include "Sensor_TCP_server.h"

using namespace std;

Sensor_TCP_server::Sensor_TCP_server() : ComThread(){
	go_on = true;
	data_out = 0.;
	tcp_server.Configure(4242);
}

Sensor_TCP_server::~Sensor_TCP_server(){}

void Sensor_TCP_server::On_start(){}

void Sensor_TCP_server::IO(){
	Link_output("my_data", &data_out);
}

void Sensor_TCP_server::Job(){
	while(go_on){
		string msg = tcp_server.Receive(0);
		data_out = stof(msg);
		Critical_send();
	}
}

void Sensor_TCP_server::Stop(){
	go_on = false;
	tcp_server.Close();
}
