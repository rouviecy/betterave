#include "FSM.h"

using namespace std;

FSM::FSM(){}

FSM::~FSM(){
	for(StateMap::iterator it = states.begin(); it != states.end(); ++it){
		for(int i = 0; i < it->second->transitions.size(); i++){
			delete it->second->transitions[i];
		}
		delete it->second;
	}
	for(EventMap::iterator it = events.begin(); it != events.end(); ++it){
		delete it->second;
	}
}

bool FSM::Add_state(string name){
	if(states.count(name) > 0){
		cout << "[Warning] Trying to create state \"" + name + "\" which already exist" << endl;
		return false;
	}
	state *new_state = new state;
	if(new_state == NULL){
		cout << "[Error] Failed to create state \"" + name + "\" : null pointer" << endl;
		return false;
	}
	new_state->name = name;
	states[name] = new_state;
	return true;
}

bool FSM::Add_event(string name){
	if(events.count(name) > 0){
		cout << "[Warning] Trying to create event \"" + name + "\" which already exist" << endl;
		return false;
	}
	event *new_event = new event;
	if(new_event == NULL){
		cout << "[Error] Failed to create event \"" + name + "\" : null pointer" << endl;
		return false;
	}
	new_event->name = name;
	events[name] = new_event;
	return true;
}

bool FSM::Add_transition(string state_from, string state_to, string event, bool* guard, void (*action)(void*), void* obj){
	if(states.count(state_from) == 0){
		cout << "[Error] Failed to create transition from \"" + state_from + "\" to \"" + state_to + "\" : state \"" + state_from + "\" does not exist" << endl;
		return false;
	}
	if(states.count(state_to) == 0){
		cout << "[Error] Failed to create transition from \"" + state_from + "\" to \"" + state_to + "\" : state \"" + state_to + "\" does not exist" << endl;
		return false;
	}
	if(events.count(event) == 0){
		cout << "[Error] Failed to create transition from \"" + state_from + "\" to \"" + state_to + "\" : event \"" + event + "\" does not exist" << endl;
		return false;
	}
	transition* new_transition = new transition;
	if(new_transition == NULL){
		cout << "[Error] Failed to create transition from \"" + state_from + "\" to \"" + state_to + "\" : null pointer" << endl;
		return false;
	}
	new_transition->state_from = state_from;
	new_transition->state_to = state_to;
	new_transition->guard = guard;
	new_transition->action = action;
	new_transition->obj = obj;
	events[event]->listening_transitions.push_back(new_transition);
	states[state_from]->transitions.push_back(new_transition);
	return true;
}

bool FSM::Launch(string state_init){
	if(states.count(state_init) == 0){
		cout << "[Error] Failed to launch FSM : state \"" + state_init + "\" does not exist" << endl;
		return false;
	}
	current_states.push_back(states[state_init]);
	return true;
}

bool FSM::Call_event(string name){
	if(events.count(name) == 0){
		cout << "[Error] Event \"" + name + "\" does not exist" << endl;
		return false;
	}
	for(int i = 0; i < events[name]->listening_transitions.size(); i++){
		transition* processed_transition = events[name]->listening_transitions[i];
		if(!(bool) *(processed_transition->guard)){continue;}
		for(int j = 0; j < current_states.size(); j++){
			if(current_states[j] != states[processed_transition->state_from]){continue;}
			current_states[j] = states[processed_transition->state_to];
			if(processed_transition->action != NULL){
				processed_transition->action(processed_transition->obj);
			}
		}
	}
	return true;
}
