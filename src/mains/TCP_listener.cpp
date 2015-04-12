#include "TCP_listener.h"

using namespace std;

TCP_listener::TCP_listener() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,		"My sensor",		-1);		// manual loop
	Add_thread(&sensor_fake,	"My TCP sensor",	100000);	// 100 ms
	Add_thread(&state,		"My state manager",	1000000);	// 1 s

	sensor_fake.Connect_to_server();

	Link_all();
	Draw("coms");
	Launch_all();

}

void TCP_listener::Shutdown(){
	sensor.Stop();
	Join_all();
}

int main(){
	TCP_listener robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
