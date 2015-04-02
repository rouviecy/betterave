#include "Sensor_Java.h"

using namespace std;

Sensor_Java::Sensor_Java() : ComJava(){
	data_out = 0.;
}

Sensor_Java::~Sensor_Java(){}

void Sensor_Java::IO(){
	Link_output_java("my_data", &data_out);
}

void Sensor_Java::Job(){
	Job_java();
	Receive_from_java();
	Critical_send();
}
