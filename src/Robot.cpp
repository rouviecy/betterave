#include "Robot.h"

using namespace std;

Robot::Robot(){

	// Warning : pass-by-reference to avoid slicing !
	threads.push_back(&sensor);
	threads.push_back(&state);

	sensor.Set_name("My sensor");
	sensor.Set_freq(10000);		// 10 ms
	state.Set_name("My state manager");
	state.Set_freq(1000000);	// 1 s

	Link_all();
	drawer.Draw_threads("graph", threads);
	Launch_all();

	usleep(5000000);

	Join_all();
}

void Robot::Link_all(){
	for(size_t i = 0; i < threads.size(); i++){
		threads[i]->Link(&share);
	}
}

void Robot::Launch_all(){
	for(size_t i = 0; i < threads.size(); i++){
		threads[i]->Launch();
	}
}

void Robot::Join_all(){
	for(size_t i = 0; i < threads.size(); i++){
		threads[i]->Join();
	}
}
