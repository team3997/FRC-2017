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
	gearController->GearPIDUp();
	DriveDistanceStraight(robot, driveTrain, gearController, 61.0, 0.4, 4.0, true, lights, false);
	DriveDistanceStraight(robot, driveTrain, gearController, 25.0, 0.25, 2.0, false, lights, false);
	gearController->GearPIDDown();
	DriveDistanceStraight(robot, driveTrain, gearController, -5.0, 0.25, 1.5, true, lights, true);
	robot->SetGearIntakeSpeed(0.0);
}

void CenterGear::Prestart() {
}


CenterGear::~CenterGear() {
  // TODO Auto-generated destructor stub
}

