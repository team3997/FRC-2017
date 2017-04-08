/*
 * PassAutoLine.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "PassAutoLine.h"
#include "../../Params.h"

PassAutoLine::PassAutoLine(RobotModel *robot, DriveController* driveTrain, GearController *gearController, LightsController* lights) {
  this->robot = robot;
  this->driveTrain = driveTrain;
  this->lights = lights;
  this->gearController = gearController;
}

void PassAutoLine::Routine() {
	gearController->gearTilterPID->Enable();
	DriveDistanceStraight(robot, driveTrain, gearController, 100.0, 0.4, 4.0, false, lights, false);
	gearController->gearTilterPID->Disable();
}

void PassAutoLine::Prestart() {
	gearController->gearTilterPID->SetPID(
	        				gear_p,
							gear_i,
							gear_d,
							gear_f);
	        		gearController->gearTilterPID->SetOutputRange(-1.0, 1.0);
	        		gearController->gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
}




// alliance wall 93.45 in

//90 degrees from hopper 173v 100h in
