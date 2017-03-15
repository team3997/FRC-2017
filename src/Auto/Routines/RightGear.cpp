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
    DriveDistanceStraight(robot, driveTrain, 76.0, .8, 3.5, false);
    DriveDistanceRotate(robot, driveTrain, -50.0, .8, 1.5, false);
    VisionSetpointX(vision, driveTrain, robot, 207, 0.4, 1.5, false);
    DriveDistanceStraight(robot, driveTrain, 15, .8, 5, false);

}
