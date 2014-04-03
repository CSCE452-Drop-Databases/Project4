#include "Point.h"
#include <math.h>

Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}

double Point::distance(Point _b) {
	double dx = x - _b.x;
	double dy = y - _b.y;
	double result = sqrt(pow(dx, 2) + pow(dy, 2));
	return result;
}