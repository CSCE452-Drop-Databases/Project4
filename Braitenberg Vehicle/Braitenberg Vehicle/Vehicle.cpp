#include "Vehicle.h"


Vehicle::Vehicle(int w, int h, Point origin, Velocity v, Matrix<int> _k) {
	if (w < VEHICLE_DEFAULT_WIDTH) {
		printf("Error: Invalid vehicle width, using default (%d)\n", VEHICLE_DEFAULT_WIDTH);
		w = VEHICLE_DEFAULT_WIDTH;
	}
	if (h < VEHICLE_DEFAULT_HEIGHT) {
		printf("Error: Invalid vehicle height, using default (%d)\n", VEHICLE_DEFAULT_HEIGHT);
		h 
			= VEHICLE_DEFAULT_HEIGHT;
	}
	width = w;
	height = h;
	center = origin;
	velocity = v;
	k = _k;
}

Vehicle::Vehicle(const Vehicle &v) {
	width = v.width;
	height = v.height;
	center = v.center;
	velocity = v.velocity;
	k = v.k;
}

double Vehicle::getRotation() {
	//TODO should this be in degrees or radians?
	//TODO implement this function

	return 0; //placeholder
}