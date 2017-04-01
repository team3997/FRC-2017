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
	DriveDistanceStraight(robot, kDrive, 193.0, 0.8, 10.0, false);
	WaitTime(2.0);
}

void DriveForwardRoutine::Prestart() {

}

