#include "Point.h"
#include <math.h>

Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
}

double point_distance(Point _a, Point _b) {
	double dx = _a.x - _b.x;
	double dy = _a.y - _b.y;
	double result = sqrt(pow(dx, 2) + pow(dy, 2));
	return result;
}