/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPointStraightAction.h"

DriveSetPointStraightAction::DriveSetPointStraightAction(RobotModel *robot, DriveController *driveTrain, double distance, double maxSpeed, double timeout) {
  this->driveTrain = driveTrain;
  this->distance = distance;
  this->timeout = timeout;
  this->robot = robot;
  this->maxSpeed = maxSpeed;

  reachedSetpoint = false;
  leftEncoderStartDistance, rightEncoderStartDistance = 0.0;
}

bool DriveSetPointStraightAction::IsFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + timeout) || (reachedSetpoint);
}

void DriveSetPointStraightAction::Update() {
  //kDrive->ArcadeDrive(y_drive, x_drive, false);
}

void DriveSetPointStraightAction::Done() {
  //kDrive->Stop();
}

void DriveSetPointStraightAction::Start() {
  start_time = Timer::GetFPGATimestamp();

  robot->leftDriveEncoder->Reset();
  robot->rightDriveEncoder->Reset();

  leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
  rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();


}
