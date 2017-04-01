/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(RobotModel *robot, DriveController* kDrive, LightsController* lights) {
	this->robot = robot;
	this->kDrive = kDrive;
	this->lights = lights;
}

void DriveForwardRoutine::Routine() {
	// TODO Auto-generated constructor stub
	//DriveDistanceStraight(robot, kDrive, 97.0, 0.8, 4.0, true);
	DriveDistanceStraight(robot, kDrive, 193.0, 0.8, 10.0, false, lights);
}

void DriveForwardRoutine::Prestart() {

}

