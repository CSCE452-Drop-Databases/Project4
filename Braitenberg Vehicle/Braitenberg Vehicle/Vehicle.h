#pragma once

#include "stdafx.h"
#include "Point.h"
#include "Velocity.h"
#include "Matrix.h"
#include "LightSource.h"

static const int VEHICLE_DEFAULT_WIDTH = 20;
static const int VEHICLE_DEFAULT_HEIGHT = 30;
static const int VEHICLE_K_STRAIGHT = 0;
static const int VEHICLE_K_CROSSED = 1;



class Vehicle {
public:
	int width, height;
	Point center, lSensor, rSensor;
	double rSOut, lSOut;
	//Velocity velocity;
	Matrix<double> k;
	Matrix<double> wheelSpeeds;
	double rotation; // rotation in degrees


	Vehicle(Point origin, int _k);
	Vehicle(const Vehicle &v);
	
	// Updates the vehicles speed and position
	void update(std::vector<LightSource> ls);

	//Returns the vehicle's current rotation in (DEG?/RAD?)
	//double getRotation();

	// Iterates over light sources and updates wheel speeds
	void updateWheelSpeed(std::vector<LightSource> ls);
};
