#include "LightSource.h"

LightSource::LightSource(int _x, int _y) {
	source_location.x = _x;
	source_location.y = _y;
}

LightSource::LightSource(Point _p) {
	source_location = _p;
}

Point LightSource::getSourceLocation() {
	return source_location;
}

double LightSource::intensity(Point _p) {
	double distance = point_distance(_p, source_location);
	if (distance == 0) {
		return 100;
	} else {
		return (100 / distance);
	}
}