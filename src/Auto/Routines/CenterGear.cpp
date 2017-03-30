/*
 * CenterGear.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "CenterGear.h"
CenterGear::CenterGear(VisionController* vision, RobotModel* robot,
                       DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->vision = vision;
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->lights = lights;
    this->gearController = gearController;
}
void CenterGear::Routine() {

    DriveDistanceStraight(robot, driveTrain, 87.0, 0.5, 8.0, true, lights);
}

void CenterGear::Prestart() {
	SmartDashboard::PutString("CENTERGEARSTATE", "RESET");
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

