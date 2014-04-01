#pragma once
class Point {
public:
	int x, y;

	Point(int _x = 0, int _y = 0);
};

double point_distance(Point a, Point b);