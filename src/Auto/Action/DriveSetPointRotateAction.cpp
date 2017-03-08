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
	if(driveController->leftPID->OnTarget() && driveController->rightPID->OnTarget() && (Timer::GetFPGATimestamp() >= start_time + 6.0)){
		reachedSetpoint = true;
	}
	else{
		reachedSetpoint = false;
	}
}

void DriveSetPointRotateAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	driveController->Stop();
}

void DriveSetPointRotateAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->leftPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->leftPID->SetPID(0.125, 0.0, 0.0);
	driveController->leftPID->SetSetpoint(distance + leftEncoderStartDistance);

	driveController->rightPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->rightPID->SetPID(0.125, 0.0, 0.0);
	driveController->rightPID->SetSetpoint(-1.0 * (distance + rightEncoderStartDistance));

	driveController->leftPID->Enable();
	driveController->rightPID->Enable();
}
