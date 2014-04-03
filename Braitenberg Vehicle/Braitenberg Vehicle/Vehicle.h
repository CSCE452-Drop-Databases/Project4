#pragma once

#include "stdafx.h"
#include "Point.h"
#include "Velocity.h"
#include "Matrix.h"
#include "LightSource.h"

static const int VEHICLE_DEFAULT_WIDTH = 10;
static const int VEHICLE_DEFAULT_HEIGHT = 10;
static const int VEHICLE_K_STRAIGHT = 0;
static const int VEHICLE_K_CROSSED = 1;



class Vehicle {
public:
	int width, height;
	Point center, lSensor, rSensor;
	double rSOut, lSOut;
	//Velocity velocity;
	Matrix<int> k;

	Vehicle(Point origin, int _k);
	Vehicle(const Vehicle &v);
	~Vehicle() {
		
	}
	
	//Returns the vehicle's current rotation in (DEG?/RAD?)
	double getRotation();

	// Iterates over light sources and updates wheel speeds
	void updateWheelSpeed();
};