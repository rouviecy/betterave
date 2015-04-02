#include "Testjava.h"

using namespace std;

Testjava::Testjava() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",		10000);		// 10 ms
	Add_thread(&state,	"My state manager",	1000000);	// 1 s

	corejava.Java_init();
	sensor.Connect_java(&corejava, "Java_parts/Test");

	Link_all();
	Draw("coms");
	Launch_all();

}

void Testjava::Shutdown(){
	Join_all();
	sensor.Disconnect_java();
	corejava.Java_close();
}

int main(){
	Testjava robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
