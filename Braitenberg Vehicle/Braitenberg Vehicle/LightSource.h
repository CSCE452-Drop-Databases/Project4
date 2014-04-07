#pragma once
#include "Point.h"

static const int LIGHT_SOURCE_DEFAULT_WIDTH = 10;
static const int LIGHT_SOURCE_DEFAULT_HEIGHT = 10;

class LightSource {
private:
	//Location of LightSource in the 2D world
	//Point center;

public:
    Point center;
    int width, height;

	//Constructor
	LightSource(int x = 0, int y = 0);

	//Constructor
	LightSource(Point p);

	Point getSourceLocation();

	//The intensity of this light source at point p
	double intensity(Point p);
};

//Intensity is measured by the distance from the source
//All sources have a max intensity of 100 when distance is 0
