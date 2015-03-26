#include "Testjava.h"

using namespace std;

Testjava::Testjava() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",		10000);		// 10 ms
	Add_thread(&state,	"My state manager",	1000000);	// 1 s

	Link_all();
	Draw("coms");
	Launch_all();

}

void Testjava::Shutdown(){
	Join_all();
}

int main(){
	Testjava robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
