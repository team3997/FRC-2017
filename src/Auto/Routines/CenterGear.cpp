/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"

CenterGear::CenterGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain) {
  this->robot = robot;
  this->driveTrain = driveTrain;
  this->vision = vision;
}

void CenterGear::Routine() {
	DriveDistanceStraight(robot, driveTrain, 30.0, 0.5, 4.0, 4.0, false);
	SmartDashboard::PutString("CENTERGEARSTATE", "WAITING");
	WaitTime(1.0);
	SmartDashboard::PutString("CENTERGEARSTATE", "GOING");
	VisionSetpointX(vision, driveTrain, robot, 207, 0.3, 5.0);
	DriveDistanceStraight(robot, driveTrain, 45.0, 0.5, 4.0, 45.0, false);
	//DriveDistanceStraight(robot, driveTrain, 80.0, 0.5, 4.0, 4.0, false);
}

void CenterGear::Prestart() {
	SmartDashboard::PutString("CENTERGEARSTATE", "RESET");
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

