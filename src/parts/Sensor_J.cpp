#include "Sensor_J.h"

using namespace std;

Sensor_J::Sensor_J() : ComThread(){
	data_out = 0.;
	joystick.Connect_joystick(0);
	joystick.Print_infos();
	data_joystick = joystick.Get_axes();
}

Sensor_J::~Sensor_J(){}

void Sensor_J::On_start(){}

void Sensor_J::IO(){
	Link_output("my_data", &data_out);
}

void Sensor_J::Job(){
	joystick.Update_event();
	data_out = (float) data_joystick[3];
	Critical_send();
}
