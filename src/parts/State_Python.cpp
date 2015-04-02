#include "State_Python.h"

using namespace std;

State_Python::State_Python() : ComPython(){
	Connect_python("brain", "speaker");
}

State_Python::~State_Python(){}

void State_Python::On_start(){}

void State_Python::IO(){
	Link_input_python("my_data", &data_in);
}

void State_Python::Job(){
	Critical_receive();
	Send_to_python();
	Job_python();
}
