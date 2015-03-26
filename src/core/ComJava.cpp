#include "ComJava.h"

using namespace std;

ComJava::ComJava() : ComThread(){
	connected = false;
}

ComJava::~ComJava(){
	Disconnect_java();
}

void ComJava::Connect_java(string script_name, string class_name){

	#ifdef ENABLE_JAVA
		//TODO
		connected = true;

	#else
		cout << "[Warning] You are trying to connect Java without Java enabled" << endl;
	#endif 
}

void ComJava::Disconnect_java(){
	#ifdef ENABLE_JAVA
		if(connected){
			//TODO
			connected = false;
		}
	#endif
}

void ComJava::Link_input_java(string key, float *p_float){
	Link_input(key, p_float);
	#ifdef ENABLE_JAVA
		//TODO
	#endif
}

void ComJava::Link_output_java(string key, float *p_float){
	Link_output(key, p_float);
	#ifdef ENABLE_JAVA
		//TODO
	#endif
}

void ComJava::Send_to_java(){
	#ifdef ENABLE_JAVA
		//TODO
	#endif
}

void ComJava::Receive_from_java(){
	#ifdef ENABLE_JAVA
		//TODO
	#endif
}

void ComJava::Job_java(){
	#ifdef ENABLE_JAVA
		//TODO
	#endif	
}
