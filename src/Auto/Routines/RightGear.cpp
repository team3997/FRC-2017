/*
 * RightGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "RightGear.h"

RightGear::RightGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->vision = vision;
}

void RightGear::Prestart() {

}

void RightGear::Routine() {
	   DriveDistanceStraight(robot, driveTrain, 98, 0.5, 3.3, true);
	   DriveDistanceRotate(robot, driveTrain, -73, 0.6, 1.5, true);
	   DriveDistanceStraight(robot, driveTrain, 10, 1.0, 1, false);
	   DriveDistanceStraight(robot, driveTrain, 15, 0.4, 5, false);

}
