#include "Finite_state_machine.h"

using namespace std;

Finite_state_machine::Finite_state_machine() : Maestro(){

	// Warning : pass-by-reference to avoid slicing !
	Add_thread(&sensor,	"My sensor",	10000);	// 10 ms
	Add_thread(&state,	"My FSM",	12345);	// avoid round numbers

	Link_all();
	Draw("coms");
	Launch_all();

}

void Finite_state_machine::Shutdown(){
	Join_all();
}

int main(){
	Finite_state_machine robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
