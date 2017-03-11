/*
 * RightGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "RightGear.h"

RightGear::RightGear(RobotModel *robot, DriveController* driveTrain) {
    this->robot = robot;
    this->driveTrain = driveTrain;
}

void RightGear::Prestart() {

}

void RightGear::Routine() {
    DriveDistanceStraight(robot, driveTrain, 129, .8, 7, 7, false);
    DriveDistanceRotate(robot, driveTrain, -90, .8, 3, 3, false);
    DriveDistanceStraight(robot, driveTrain, 15, .8, 5, 5, false);

}
