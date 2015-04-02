#include "Java_to_python.h"

using namespace std;

Java_to_python::Java_to_python() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",		10000);		// 10 ms
	Add_thread(&state,	"My state manager",	1000000);	// 1 s

	corejava.Java_init();
	sensor.Connect_java(&corejava, "Java_parts/Fake_sensor");

	Link_all();
	Draw("coms");
	Launch_all();

}

void Java_to_python::Shutdown(){
	Join_all();
	sensor.Disconnect_java();
	state.Disconnect_python();
	corejava.Java_close();
}

int main(){
	Java_to_python robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
