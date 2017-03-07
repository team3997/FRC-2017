/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPointRotateAction.h"
#include "WPILib.h"
//distance: distance in inches for the bot to rotate
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
DriveSetPointRotateAction::DriveSetPointRotateAction(RobotModel *robot, DriveController *driveController, double distance, double maxSpeed, double timeout, double minTime, bool wantMinTime) {
	this->driveController = driveController;
	this->distance = distance;
	this->timeout = timeout;
	this->robot = robot;
	this->maxSpeed = maxSpeed;
    this->minTime = minTime;
    this->wantMinTime = wantMinTime;
	reachedSetpoint = false;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;
}

bool DriveSetPointRotateAction::IsFinished() {
	return (Timer::GetFPGATimestamp() >= start_time + timeout) || (reachedSetpoint);
}

void DriveSetPointRotateAction::Update() {
	reachedSetpoint = driveController->driveXPID->OnTarget();
}

void DriveSetPointRotateAction::Done() {
	driveController->driveXPID->Disable();
	driveController->Stop();
}

void DriveSetPointRotateAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->driveXPID->SetOutputRange(-maxSpeed, maxSpeed);
	//driveController->driveYPID->SetPID(p, i ,d);
	driveController->driveXPID->SetSetpoint(distance + ((leftEncoderStartDistance + rightEncoderStartDistance) / 2.0 ));

	driveController->driveXPID->Enable();
}
