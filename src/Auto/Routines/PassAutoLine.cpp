/*
 * PassAutoLine.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "PassAutoLine.h"

PassAutoLine::PassAutoLine(RobotModel *robot, DriveController* driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
}

void PassAutoLine::Routine() {
    DriveDistanceStraight(robot, driveTrain, 94.0, .8, 10, false);

}

void PassAutoLine::Prestart() {}




// alliance wall 93.45 in

//90 degrees from hopper 173v 100h in
