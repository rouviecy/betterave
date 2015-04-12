#include "State_machine.h"

using namespace std;

State_machine::State_machine() : ComThread(){

	guard = true;

	fsm.Add_state("state_1");
	fsm.Add_state("state_2");
	fsm.Add_state("state_3");

	fsm.Add_event("event_1to2");
	fsm.Add_event("event_2to3");
	fsm.Add_event("event_3to1");

	fsm.Add_guard("my_guard", &guard);

	fsm.Add_action("Action_1to2", &(State_machine::Action_1to2));
	fsm.Add_action("Action_2to3", &(State_machine::Action_2to3));
	fsm.Add_action("Action_3to1", &(State_machine::Action_3to1));

	fsm.Add_transition("state_1", "state_2", "event_1to2", "my_guard", "Action_1to2", (void*) this);
	fsm.Add_transition("state_2", "state_3", "event_2to3", "my_guard", "Action_2to3", (void*) this);
	fsm.Add_transition("state_3", "state_1", "event_3to1", "my_guard", "Action_3to1", (void*) this);

	fsm.Launch("state_1");
	drawer.Draw_FSM( "FSM", &fsm);

}

State_machine::~State_machine(){}

void State_machine::On_start(){}

void State_machine::IO(){
	Link_input("my_data", &data_in);
}

void State_machine::Job(){
	Critical_receive();
	cout << "Received data : " << data_in << endl;
	int data_int = (int) floor(data_in);
	if(data_int % 2 < 1){
		cout << "\tGuard is blocking" << endl;
		guard = false;
	}
	else{
		cout << "\tGuard is passing" << endl;
		guard = true;
	}
	if(data_int % 3 < 1){
		cout << "\tCalling event_1to2" << endl;
		fsm.Call_event("event_1to2");
	}
	else if(data_int % 3 - 1 < 1){
		cout << "\tCalling event_2to3" << endl;
		fsm.Call_event("event_2to3");
	}
	else{
		cout << "\tCalling event_3to1" << endl;
		fsm.Call_event("event_3to1");
	}
}

void State_machine::Action_1to2(void* obj){cout << "\t\tSwitching from state_1 to state_2" << endl;}
void State_machine::Action_2to3(void* obj){cout << "\t\tSwitching from state_2 to state_3" << endl;}
void State_machine::Action_3to1(void* obj){cout << "\t\tSwitching from state_3 to state_1" << endl;}
