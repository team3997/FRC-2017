/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(RobotModel *robot, DriveController* driveTrain) {
    this->robot = robot;
    this->driveTrain = driveTrain;
}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
   DriveDistanceStraight(robot, driveTrain, 129, .8, 7, 7, false);
   DriveDistanceRotate(robot, driveTrain, 90, .8, 3, 3, false);
   DriveDistanceStraight(robot, driveTrain, 15, .8, 5, 5, false);

}
// 15in 129v
