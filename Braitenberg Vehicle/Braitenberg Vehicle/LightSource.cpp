#include "LightSource.h"

LightSource::LightSource(int _x, int _y) {
	//center.x = _x;
	//center.y = _y;
	LightSource(Point(_x, _y));
}

LightSource::LightSource(Point _p) {
	center = _p;
	width = LIGHT_SOURCE_DEFAULT_WIDTH;
	height = LIGHT_SOURCE_DEFAULT_HEIGHT;
}

//Point LightSource::getSourceLocation() {
//	return center;
//}

double LightSource::intensity(Point _p) {
	double distance = _p.distance(center);
	if (distance <= 1) {
		return 100;
	} else {
		return (100 / distance);
	}
}