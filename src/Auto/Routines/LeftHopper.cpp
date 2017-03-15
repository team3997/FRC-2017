/*
 * LeftHopper.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "LeftHopper.h"

LeftHopper::LeftHopper(RobotModel *robot, DriveController* driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
}

void LeftHopper::Routine() {
    DriveDistanceStraight(robot, driveTrain, 173.0, .8, 10, false);
    DriveDistanceRotate(robot, driveTrain, -90, .8, 10.0, false);

}

void LeftHopper::Prestart() {}




// alliance wall 93.45 in

//90 degrees from hopper 173v 100h in
