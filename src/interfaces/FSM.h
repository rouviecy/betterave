/*
 * @(#)		FSM.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * Provide a Finite State Machine
 * 	- First, add states and events you will use, with string keys
 * 	- Then, add transitions by providing :
 * 		- name of in/out states
 * 		- name of event which triggers the transition
 * 		- pointer to a guard (can be NULL) which block transition if false
 * 		- pointer to static function (can be NULL) which is called during transition
 * 		- pointer to an object (can be NULL) you want use in this function (usually, "this" self-pointer to change instance variables)
 * 	- To finish configuration, launch with the name of init state (you can call it several times)
 * 	- When FSM is working, use Call_event(string name) to change states
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

#ifndef FSM_H
#define FSM_H

class FSM{

public:

	FSM();
	~FSM();

	bool Add_state(std::string name);

	bool Add_event(std::string name);

	bool Add_transition(
		std::string state_from,
		std::string state_to,
		std::string event,
		bool* guard,
		void (*action)(void*),
		void* obj);

	bool Launch(std::string state_init);

	bool Call_event(std::string name);


private:

	typedef struct{
		std::string state_from;
		std::string state_to;
		bool* guard;
		void (*action)(void*);
		void* obj;
		
	}transition;

	typedef struct{
		std::string name;
		std::vector <transition*> transitions;
	}state;

	typedef struct{
		std::string name;
		std::vector <transition*> listening_transitions;
	}event;

	typedef std::map <std::string, state*> StateMap;
	typedef std::map <std::string, event*> EventMap;

	StateMap states;
	EventMap events;

	std::vector <state*> current_states;

};

#endif
