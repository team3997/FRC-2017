/*
 * PassAutoLine.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "PassAutoLine.h"

PassAutoLine::PassAutoLine(RobotModel *robot, DriveController* driveTrain, LightsController* lights) {
  this->robot = robot;
  this->driveTrain = driveTrain;
  this->lights = lights;
}

void PassAutoLine::Routine() {
	DriveDistanceStraight(robot, driveTrain, 193.0, 0.8, 10.0, false, lights);

}

void PassAutoLine::Prestart() {}




// alliance wall 93.45 in

//90 degrees from hopper 173v 100h in
