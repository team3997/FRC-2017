/*
 * DriveInterval.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */
#include "Timer.h"
#include "DriveIntervalAction.h"

DriveIntervalAction::DriveIntervalAction(DriveController* kDrive,
        double seconds, double y, double x) {
  goal_time = seconds;
  x_drive = x;
  y_drive = y;
  this->kDrive = kDrive;

}
bool DriveIntervalAction::IsFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void DriveIntervalAction::Update() {
  kDrive->ArcadeDrive(y_drive, x_drive, false);
}

void DriveIntervalAction::Done() {
  kDrive->Stop();
}

void DriveIntervalAction::Start() {
  start_time = Timer::GetFPGATimestamp();
}
DriveIntervalAction::~DriveIntervalAction() {
  // TODO Auto-generated destructor stub
}

