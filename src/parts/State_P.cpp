#include "State_P.h"

using namespace std;

State_P::State_P() : ComPython(){
	Connect_python("brain", "speaker");
}

State_P::~State_P(){}

void State_P::On_start(){}

void State_P::IO(){
	Link_input_python("my_data", &data_in);
}

void State_P::Job(){
	Critical_receive();
	Send_to_python();
	Job_python();
}
