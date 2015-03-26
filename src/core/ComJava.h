/*
 * @(#)		ComJava.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * Execute Java code instead of C++ code
 */

#ifndef COMJAVA
#define COMJAVA

#ifdef ENABLE_JAVA
	#include <jni.h>
#endif

#include <iostream>
#include "ComThread.h"

class ComJava : public ComThread{

public:

	ComJava();
	~ComJava();

	void Connect_java(			// Connect to a Python script
		std::string script_name,		// Script name (without .py) in src/parts/python
		std::string class_name);		// Class to use in this script
	void Disconnect_java();			// Close Python (destructor calls it if you forget ...)

private:

	#ifdef ENABLE_JAVA

	#endif
	bool connected;
	PFloatMap input_keys, output_keys;

protected:

	void Link_input_java(			// Link input from Betterave AND output to Java (do not use Link_input)
		std::string key,			// Topic name
		float *p_float);			// Pointer to associated variable

	void Link_output_java(			// Link output to Betterave AND input from Java (do not use Link_output)
		std::string key,			// Topic name
		float *p_float);			// Pointer to associated variable

	void Send_to_java();			// Publish input variables to Java
	void Receive_from_java();		// Refresh output variables from Java
	void Job_java();			// Call Job() method of Java script

};

#endif
