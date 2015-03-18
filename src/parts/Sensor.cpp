#include "Sensor.h"

using namespace std;

Sensor::Sensor() : ComThread(){
	data_out = 0.;
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
}
