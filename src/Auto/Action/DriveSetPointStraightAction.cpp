/*
 * DriveSetPoint.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#include "DriveSetPointStraightAction.h"

//distance: distance in inches for the bot to drive
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
DriveSetPointStraightAction::DriveSetPointStraightAction(RobotModel *robot, DriveController *driveController, double distance, double maxSpeed, double timeout) {
	this->driveController = driveController;
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
	reachedSetpoint = driveController->driveYPID->OnTarget();
}

void DriveSetPointStraightAction::Done() {
	driveController->driveYPID->Disable();
	driveController->Stop();
}

void DriveSetPointStraightAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->driveYPID->SetOutputRange(-maxSpeed, maxSpeed);
	//driveController->driveYPID->SetPID(p, i ,d);
	driveController->driveYPID->SetSetpoint(distance + ((leftEncoderStartDistance + rightEncoderStartDistance) / 2.0 ));

	driveController->driveYPID->Enable();
}
