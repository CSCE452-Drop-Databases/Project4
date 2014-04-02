#pragma once
#include "Point.h"

class LightSource {
private:
	//Location of LightSource in the 2D world
	Point source_location;

public:

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
