#include "Sensor_Joystick.h"

using namespace std;

Sensor_Joystick::Sensor_Joystick() : ComThread(){
	data_out = 0.;
	joystick.Connect_joystick(0);
	joystick.Print_infos();
	data_joystick = joystick.Get_axes();
}

Sensor_Joystick::~Sensor_Joystick(){}

void Sensor_Joystick::On_start(){}

void Sensor_Joystick::IO(){
	Link_output("my_data", COMFLOAT, 1, &data_out);
}

void Sensor_Joystick::Job(){
	joystick.Update_event();
	data_out = (float) data_joystick[3];
	Critical_send();
}
