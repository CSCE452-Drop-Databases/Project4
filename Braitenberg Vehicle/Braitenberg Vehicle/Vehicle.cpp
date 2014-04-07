#include "Vehicle.h"


Vehicle::Vehicle(Point origin, int _k) {
	
	width = VEHICLE_DEFAULT_WIDTH;
	height = VEHICLE_DEFAULT_HEIGHT;
	center = origin;
	wheelSpeeds = Matrix<double>(2, 1);
	wheelSpeeds[0][0] = 1;
	wheelSpeeds[1][0] = 1;
	k = Matrix<double>(2, 2);
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
	//velocity = Velocity(1,1);


	lSensor = Point(origin.x + width / 4, origin.y + height / 2);
	rSensor = Point(origin.x - width / 4, origin.y + height / 2);

}

Vehicle::Vehicle(const Vehicle &v) {
	width = v.width;
	height = v.height;
	center = v.center;
	lSensor = v.lSensor;
	rSensor = v.rSensor;
	//velocity = v.velocity;
	k = v.k;
	rotation = v.rotation;
}

void Vehicle::update(std::vector<LightSource> ls) {
	updateWheelSpeed(ls);

	// figure out wheel speed differences
	double dif = rSOut - lSOut;

	//TODO update vehicle's rotation and position according to wheel speeds
	center.x += 0;
	center.y += 1;
	
	//TODO update vehicle's sensor positions according to center position and rotation
}

// double Vehicle::getRotation() {
// 	//TODO should this be in degrees or radians?
// 	//TODO implement this function

// 	return 0; //placeholder
// }

void Vehicle::updateWheelSpeed(std::vector<LightSource> ls) {
	// TODO: Determine where sensors are since vehicle can rotate
	// TODO: Decide how to implement this
	// Could do it where it sums all intensities from every light
	// OR could do it where it only uses closest light

	// finding closest light source
	int closest = 0;
	double closestDist = INT_MAX;
	for (int i = 0; i < ls.size(); ++i) {
		double dist = center.distance(ls[i].center);
		if (dist < closestDist) {
			closest = i;
			closestDist = dist;
		}
	}
	//printf("Closest light source = %d\n", closest);

	rSOut = ls[closest].intensity(rSensor);
	lSOut = ls[closest].intensity(lSensor);

	Matrix<double> senseMat(2, 1);
	senseMat[0][0] = lSOut;
	senseMat[1][0] = rSOut;

	wheelSpeeds = k * senseMat;
	//std::cout << "Wheel speeds: " << wheelSpeeds[0][0] << ", " << wheelSpeeds[1][0] << std::endl;
}
