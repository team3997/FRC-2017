/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPoint.h"

DriveSetPoint::DriveSetPoint(DriveController *driveTrain) {
  this->driveTrain = driveTrain;
}

bool DriveSetPoint::IsFinished() {
  //return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void DriveSetPoint::Update() {
  //kDrive->ArcadeDrive(y_drive, x_drive, false);
}

void DriveSetPoint::Done() {
  //kDrive->Stop();
}

void DriveSetPoint::Start() {
  //start_time = Timer::GetFPGATimestamp();
}
