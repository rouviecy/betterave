#include "State.h"

using namespace std;

State::State() : ComThread(){}

State::~State(){}

void State::On_start(){}

void State::IO(){
	Link_input("my_data",		COMFLOAT, 1, &data_in);
	Link_input("my_data_array",	COMFLOAT, 2, data_in_array);
}

void State::Job(){
	Critical_receive();
	cout << "Received data : " << data_in << ", " << data_in_array[0] << ", " << data_in_array[1] << endl;
}
