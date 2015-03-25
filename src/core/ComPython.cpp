#include "ComPython.h"

using namespace std;

ComPython::ComPython() : ComThread(){
	#define SCRIPT_NAME "chose"
	#define CLASS_NAME "chouette"
	#define FUNCTION_NAME "ping"

	// Initialize and include current path to PYTHONPATH
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.insert(0, '../src/parts/python')");

	// Load file
	PyObject *pName = PyUnicode_FromString(SCRIPT_NAME);
	PyObject *pModule = PyImport_Import(pName);
	Py_DECREF(pName);
	if(pModule == NULL){
		cout << "Error loading python script : " + string(SCRIPT_NAME) << endl;
		return;
	}

	// Load class
	PyObject *pClass = PyObject_GetAttrString(pModule, CLASS_NAME);
	Py_DECREF(pModule);
	if(!pClass){
		cout << "Error loading class : " + string(CLASS_NAME) << endl;
		return;
	}

	// Instantiate object (without argument)
	pObject = PyObject_CallObject(pClass, NULL);
	Py_DECREF(pClass);
	if(pObject == NULL || !PyObject_IsInstance(pObject, pClass)){
		cout << "Error loading instantiating class : " + string(CLASS_NAME) << endl;
		return;
	}

	// Load function from object
	PyObject *pFunc = PyObject_GetAttrString(pObject, FUNCTION_NAME);
	if(!pFunc){
		cout << "Error loading function : " + string(FUNCTION_NAME) << endl;
		return;
	}

	// Load arguments
	PyObject *pArgs = PyTuple_New(1);
	PyObject *pValue = PyLong_FromLong(42);
	if(!pValue){
		cout << "Error creating argument" << endl;
		Py_DECREF(pArgs);
		Py_DECREF(pValue);
		Py_DECREF(pFunc);
		return;
	}
	PyTuple_SetItem(pArgs, 0, pValue);

	// Call function
	pValue = PyObject_CallObject(pFunc, pArgs);
	Py_DECREF(pArgs);
	if(pValue == NULL){
		cout << "Error loading return" << endl;
		Py_DECREF(pFunc);
		return;
	}
	cout << "Result : " << PyLong_AsLong(pValue) << endl;
	Py_DECREF(pValue);
	Py_DECREF(pFunc);
	Py_DECREF(pObject);
	
	Py_Finalize();

}

ComPython::~ComPython(){}
