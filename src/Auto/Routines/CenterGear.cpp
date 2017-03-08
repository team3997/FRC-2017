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
	DriveDistanceStraight(robot, driveTrain, 100.0, 0.4, 8.0, 6.0);
}

void CenterGear::Prestart() {}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

