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
	GearLifterUp(robot, driveTrain, gearController, 87.0, 0.4, 8.0, true);
	GearLifterDown(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true);
}

void CenterGear::Prestart() {
	SmartDashboard::PutString("CENTERGEARSTATE", "RESET");
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

