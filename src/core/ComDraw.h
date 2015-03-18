/*
 * @(#)		ComDraw.h
 * @version	2.0
 * @autor	C. Rouvière
 */

/**
 * Draw threads from ComThread and links between them
 */

#ifndef COMDRAW
#define COMDRAW

#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "ComThread.h"

class ComDraw{

public:

	ComDraw();
	void Draw_threads(std::vector <ComThread*> threads);

private:

	#define DOT_PATH "test/ComGraph.gv"
	#define PNG_PATH "test/ComGraph.png"

};

#endif
