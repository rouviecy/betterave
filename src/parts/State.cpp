#include "State.h"

using namespace std;

State::State() : ComThread(){}

void State::IO(){
	Link_input("my_data", &data_in);
}

void State::Job(){
	Critical_receive();
	cout << "Received data " << data_in << endl;
}
