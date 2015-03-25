/*
 * @(#)		ComPython.h
 * @version	1.0
 * @autor	C. Rouvière
 */

/**
 * Execute Python script instead of C++ code
 */

#ifndef COMPYTHON
#define COMPYTHON

#include <Python.h>
#include <iostream>
#include "ComThread.h"

class ComPython : public ComThread{

public:

	ComPython();
	~ComPython();

	void Connect_python(std::string script_name, std::string class_name);
	void Disconnect_python();

private:

	bool connected;
	PyObject *pObject;
	PFloatMap input_keys, output_keys;

protected:

	void Link_input_python(
		std::string key,
		float *p_float);

	void Link_output_python(
		std::string key,
		float *p_float);

	void Send_to_python();
	void Receive_from_python();
	void Job_python();

};

#endif
