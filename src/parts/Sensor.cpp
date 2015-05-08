#include "Sensor.h"

using namespace std;

Sensor::Sensor() : ComThread(){
	data_out = 0.;
	data_out_array[0] = 42.;
	data_out_array[1] = 42.;
}

Sensor::~Sensor(){}

void Sensor::On_start(){}

void Sensor::IO(){
	Link_output("my_data",		COMFLOAT, 1, &data_out);
	Link_output("my_data_array",	COMFLOAT, 2, data_out_array);
}

void Sensor::Job(){
	data_out += 1.;
	Critical_send();
}
