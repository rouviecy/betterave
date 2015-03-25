#include "State.h"

using namespace std;

State::State() : ComPython(){
	Connect_python("brain", "speaker");
}

State::~State(){

}

void State::IO(){
	Link_input_python("my_data", &data_in);
}

void State::Job(){
	Critical_receive();
	cout << "Received data " << data_in << " from sensor" << endl;
	Send_to_python();
	Job_python();
}
