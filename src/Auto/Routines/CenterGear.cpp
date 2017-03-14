/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"

CenterGear::CenterGear(RobotModel *robot, DriveController* driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
}

void CenterGear::Routine() {
	//DriveDistanceStraight(robot, driveTrain, 73.0, 0.45, 4.0, 4.0, false);
	//DriveDistanceRotate(robot, driveTrain, -180.0, 0.7, 7.0, 7.0, false);
	//DriveDistanceStraight(robot, driveTrain, 80.0, 0.5, 4.0, 4.0, false);
}

void CenterGear::Prestart() {}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

