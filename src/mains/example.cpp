/*
 * @(#)		example.cpp
 * @version	1.0
 * @autor	C. Rouvière
 */

 /**
 * Example of Betterave implementation
 */

#include "../Robot.h"

using namespace std;

int main(){
	Robot robot;
	usleep(5000000);
	robot.Shutdown();
	return 0;
}
