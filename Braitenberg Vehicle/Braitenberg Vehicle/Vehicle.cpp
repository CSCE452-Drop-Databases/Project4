#include "Vehicle.h"


Vehicle::Vehicle(Point origin, int _k) {
	
	width = VEHICLE_DEFAULT_WIDTH;
	height = VEHICLE_DEFAULT_HEIGHT;
	center = origin;
	k = Matrix<int>(2, 2);
	if (_k == VEHICLE_K_CROSSED) {
		k[0][0] = 0;
		k[0][1] = 1;
		k[1][0] = 1;
		k[1][1] = 0;
	}
	else {
		k[0][0] = 1;
		k[0][1] = 0;
		k[1][0] = 0;
		k[1][1] = 1;
	}

}

Vehicle::Vehicle(const Vehicle &v) {
	width = v.width;
	height = v.height;
	center = v.center;
	//velocity = v.velocity;
	k = v.k;
}

double Vehicle::getRotation() {
	//TODO should this be in degrees or radians?
	//TODO implement this function

	return 0; //placeholder
}

void Vehicle::updateWheelSpeed(std::vector<LightSource> ls) {
	// TODO: Determine where sensors are since vehicle can rotate
	// TODO: Decide how to implement this
	// Could do it where it sums all intensities from every light
	// OR could do it where it only uses closest light
	rSOut = 0;
	lSOut = 0;
}