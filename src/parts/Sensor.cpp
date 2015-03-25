#include "Sensor.h"

using namespace std;

Sensor::Sensor() : ComThread(){
	data_out = 0.;
	joystick.Connect_joystick(0);
	joystick.Print_infos();
	data_joystick = joystick.Get_axes();
}

Sensor::~Sensor(){}

void Sensor::IO(){
	Link_output("my_data", &data_out);
}

void Sensor::Job(){
	joystick.Update_event();
	data_out = (float) data_joystick[0];
	Critical_send();
}
