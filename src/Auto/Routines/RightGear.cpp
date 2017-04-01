/*
 * RightGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "RightGear.h"

RightGear::RightGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->vision = vision;
    this->lights = lights;
    this->gearController = gearController;

}

void RightGear::Prestart() {

}

void RightGear::Routine() {
	   DriveDistanceStraight(robot, driveTrain, gearController, 98, 0.5, 3.3, true, lights, false);
	   DriveDistanceRotate(robot, driveTrain, -73, 0.6, 1.5, true, lights);
	   DriveDistanceStraight(robot, driveTrain, gearController, 10, 1.0, 1, false, lights, false);
	   DriveDistanceStraight(robot, driveTrain, gearController, 15, 0.4, 5, false, lights, false);

}
