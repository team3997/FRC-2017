/*
 * BoilerFirstHopper.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#include "Auto/Routines/BoilerFirstHopper.h"

BoilerFirstHopper::BoilerFirstHopper(RobotModel *robot, DriveController *driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
}

void BoilerFirstHopper::Routine() {
	DriveDistanceStraight(robot, driveTrain, 27.0*12.0, 0.8, 9, false);
	WaitTime(1.0);
	DriveDistanceRotate(robot, driveTrain, 75.0, 0.8, 1.5, false);
	DriveDistanceStraight(robot, driveTrain, -20, 0.8, 2.5, false);
	DriveDistanceRotate(robot, driveTrain, 69.0, 0.8, 1.5, false);
	DriveDistanceStraight(robot, driveTrain, -100, 0.8, 7, false);
}

void BoilerFirstHopper::Prestart() {

}

