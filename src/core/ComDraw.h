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

#ifdef ENABLE_GRAPHVIZ
	#include <gvc.h>
#endif

class ComDraw{

public:

	ComDraw();
	void Draw_threads(std::string name, std::vector <ComThread*> threads);

private:

	void Generate_dot(std::string name, std::vector <ComThread*> threads);
	void Generate_svg(std::string name);

};

#endif
