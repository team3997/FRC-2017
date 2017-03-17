/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(RobotModel *robot, DriveController* kDrive) {
	this->robot = robot;
	this->kDrive = kDrive;
}

void DriveForwardRoutine::Routine() {
	// TODO Auto-generated constructor stub
	DriveDistanceStraight(robot, kDrive, 97.0, 0.8, 4.0, true);
}

void DriveForwardRoutine::Prestart() {

}

