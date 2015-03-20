#include "State.h"

using namespace std;

State::State() : ComThread(), Serial(){
	Serial_init("/dev/ttyACM0");
}

State::~State(){
	Serial_close();
}

void State::IO(){
	Link_input("my_data", &data_in);
}

void State::Job(){
	Critical_receive();
	cout << "Received data " << data_in << endl;
	cout << "Serial read : " << Serial_read() << endl;
}
