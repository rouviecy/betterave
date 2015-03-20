#include "Sensor.h"

using namespace std;

Sensor::Sensor() : ComThread(), Serial(){
	Serial_init("/dev/ttyUSB0");
	data_out = 0.;
}

Sensor::~Sensor(){
	Serial_close();
}

void Sensor::IO(){
	Link_output("my_data", &data_out);
}

void Sensor::Job(){
	data_out += 1.;
	if(data_out > 42.){
		data_out = 0.;
	}
	Critical_send();
	Serial_write("chose\0");
}
