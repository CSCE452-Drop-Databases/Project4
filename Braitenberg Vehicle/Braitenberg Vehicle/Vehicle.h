#pragma once

#include "stdafx.h"
#include "Point.h"
#include "Velocity.h"
#include "Matrix.h"

static const int VEHICLE_DEFAULT_WIDTH = 10;
static const int VEHICLE_DEFAULT_HEIGHT = 10;


class Vehicle {
public:
	int width, height;
	Point center;
	Velocity velocity;
	Matrix<int> k;

	Vehicle(int w, int h, Point origin, Velocity v, Matrix<int> _k);
	Vehicle(const Vehicle &v);
	~Vehicle() {
	
	}
};