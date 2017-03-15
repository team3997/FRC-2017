/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->vision = vision;
}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
   DriveDistanceStraight(robot, driveTrain, 129, .8, 7, false);
   DriveDistanceRotate(robot, driveTrain, 90, .8, 3, false);
   DriveDistanceStraight(robot, driveTrain, 15, .8, 5, false);
}
// 15in 129v
