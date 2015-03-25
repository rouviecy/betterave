#include "ComPython.h"

using namespace std;

ComPython::ComPython() : ComThread(){
	#define SCRIPT_NAME "chose"
	#define FUNCTION_NAME "ping"

	PyObject *pName, *pModule, *pFunc;
	PyObject *pArgs, *pValue;

	// Initialize and include current path to PYTHONPATH
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.insert(0, '../src/parts/python')");

	// Load file
	pName = PyUnicode_FromString(SCRIPT_NAME);
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);
	if(pModule == NULL){
		cout << "Error loading python script : " + string(SCRIPT_NAME) << endl;
		return;
	}

	// Load function
	pFunc = PyObject_GetAttrString(pModule, FUNCTION_NAME);
	if(!pFunc || !PyCallable_Check(pFunc)) {
		Py_DECREF(pFunc);
		Py_DECREF(pModule);
		PyErr_Print();
		cout << "Error calling function : " + string(FUNCTION_NAME) << endl;
		return;
	}

	// Load arguments
	pArgs = PyTuple_New(1);
	pValue = PyLong_FromLong(42);
	if(!pValue){
		Py_DECREF(pArgs);
		Py_DECREF(pModule);
		cout << "Error creating argument" << endl;
		return;
	}
	PyTuple_SetItem(pArgs, 0, pValue);

	// Load return
	pValue = PyObject_CallObject(pFunc, pArgs);
	Py_DECREF(pArgs);
	if(pValue == NULL){
		cout << "Error loading return" << endl;
		Py_DECREF(pValue);
		return;
	}
	cout << "Result : " << PyLong_AsLong(pValue) << endl;

	Py_DECREF(pValue);
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);

	Py_Finalize();

}

ComPython::~ComPython(){}
