/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"

CenterGear::CenterGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain, GearController* gearController) {
  this->robot = robot;
  this->driveTrain = driveTrain;
  this->vision = vision;
  this->gearController = gearController;
}

void CenterGear::Routine() {
	DriveDistanceStraight(robot, driveTrain, 87.0, 0.5, 8.0, true);
}

void CenterGear::Prestart() {
	SmartDashboard::PutString("CENTERGEARSTATE", "RESET");
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

