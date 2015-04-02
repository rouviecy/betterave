#include "ComJava.h"

using namespace std;

ComJava::ComJava() : ComThread(){
	connected = false;
}

ComJava::~ComJava(){
	Disconnect_java();
}

JOBJECTS_STRUCT* ComJava::Build_objects(){

	#ifdef ENABLE_JAVA

		// Load java class
		jclass java_class = jstr->env->FindClass(full_class_name.c_str());
		if(!java_class){
			cout << "Error searching Java class \"" + full_class_name + "\"" << endl;
			return NULL;
		}
		java_class = reinterpret_cast <jclass> (jstr->env->NewGlobalRef(java_class));

		// Load class constructor
		jmethodID java_class_constructor = jstr->env->GetMethodID(java_class, "<init>", "()V");
		if(!java_class_constructor){
			cout << "Error searching constructor of Java class \"" + full_class_name + "\"" << endl;
			return NULL;
		}

		// Instantiate object
		jobject java_instance = jstr->env->NewObject(java_class, java_class_constructor);
		if(!java_instance){
			cout << "Error instantiating Java class \"" + full_class_name + "\"" << endl;
			return NULL;
		}
		java_instance = reinterpret_cast <jobject> (jstr->env->NewGlobalRef(java_instance));

		// Load Job method
		jmethodID java_job = jstr->env->GetMethodID(java_class, "Job", "()V");
		if(!java_class_constructor){
			cout << "Error searching Job method of Java class \"" + full_class_name + "\"" << endl;
			return NULL;
		}

		// Return structure
		JOBJECTS_STRUCT* result = new JOBJECTS_STRUCT();
		result->java_class = java_class;
		result->java_instance = java_instance;
		result->java_job = java_job;
		return result;

	#else
		return NULL;
	#endif

}

void ComJava::Connect_java(CoreJava* corejava, string full_class_name){

	if(connected){
		cout << "[Warning] java is already connected !" << endl;
		return;
	}

	#ifdef ENABLE_JAVA
		this->jstr = corejava->Get_jstr();
		this->full_class_name = full_class_name;
		if(!jstr || !corejava->Is_connected()){
			cout << "Error connecting Java class \"" + full_class_name + "\"to JavaCore" << endl;
			return;
		}
		jobj = Build_objects();
		if(!jobj){
			cout << "Error initialising Java class \"" + full_class_name + "\"" << endl;
			return;
		}
		connected = true;
	#endif
}

void ComJava::Disconnect_java(){
	#ifdef ENABLE_JAVA
		if(connected){
			jstr->env->DeleteGlobalRef(jobj->java_class);
			jstr->env->DeleteGlobalRef(jobj->java_instance);
			jstr->jvm->DetachCurrentThread();
			connected = false;
		}
	#endif
}

void ComJava::On_start(){
	#ifdef ENABLE_JAVA
		int env_status = this->jstr->jvm->GetEnv((void **) &(this->jstr->env), JNI_VERSION_1_6);
		if(env_status == JNI_EDETACHED)		{this->jstr->jvm->AttachCurrentThread((void **) &(this->jstr->env), NULL);}
		else if(env_status == JNI_EVERSION)	{cout << "Error getting Java Env (version issue)" << endl; return;}
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
		jstr->env->CallVoidMethod(jobj->java_instance, jobj->java_job);
	#endif	
}
