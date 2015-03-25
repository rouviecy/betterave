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

};

#endif
