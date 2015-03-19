#include "Robot.h"

using namespace std;

Robot::Robot() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",		10000);
	Add_thread(&state,	"My state manager",	1000000);

	Link_all();
	Draw("coms");
	Launch_all();

}

void Robot::Shutdown(){
	Join_all();
}
