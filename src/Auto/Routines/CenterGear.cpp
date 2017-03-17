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
	/*DriveDistanceStraight(robot, driveTrain, 30.0, 0.5, 4.0, false); //we want this done quickly. consider upping speed to 0.65 or 0.7 and lowering time to 2.75s
	SmartDashboard::PutString("CENTERGEARSTATE", "WAITING");
	WaitTime(1.0);//no need to wait 
	SmartDashboard::PutString("CENTERGEARSTATE", "GOING");
	VisionSetpointX(vision, driveTrain, robot, 207, 0.3, 5.0, true); //Give vision a maximum of 3 seconds
	DriveDistanceStraight(robot, driveTrain, 45.0, 0.5, 45.0, false);
	//DriveDistanceStraight(robot, driveTrain, 80.0, 0.5, 4.0, 4.0, false);
	*/
	DriveDistanceStraight(robot, driveTrain, 74.0, 0.5, 8.0, true);
}

void CenterGear::Prestart() {
	SmartDashboard::PutString("CENTERGEARSTATE", "RESET");
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

