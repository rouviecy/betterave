#include "Joystick_to_python.h"

using namespace std;

Joystick_to_python::Joystick_to_python() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",		10000);		// 10 ms
	Add_thread(&state,	"My state manager",	1000000);	// 1 s

	Link_all();
	Draw("coms");
	Launch_all();

}

void Joystick_to_python::Shutdown(){
	Join_all();
}

int main(){
	Joystick_to_python robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
