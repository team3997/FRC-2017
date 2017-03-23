/*
 * BoilerFirstHopper.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#include "Auto/Routines/BoilerFirstHopper.h"

BoilerFirstHopper::BoilerFirstHopper(RobotModel *robot, DriveController *driveTrain, LightsController* lights) {
  this->robot = robot;
  this->driveTrain = driveTrain;
  this->lights = lights;
}

void BoilerFirstHopper::Routine() {
	DriveDistanceStraight(robot, driveTrain, 27.0*12.0, 0.8, 9, false, lights);
	WaitTime(1.0);
	DriveDistanceRotate(robot, driveTrain, 75.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, -20, 0.8, 2.5, false, lights);
	DriveDistanceRotate(robot, driveTrain, 69.0, 0.8, 1.5, false, lights);
	DriveDistanceStraight(robot, driveTrain, -100, 0.8, 7, false, lights);
}

void BoilerFirstHopper::Prestart() {

}

