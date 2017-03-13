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
DriveSetPointStraightAction::DriveSetPointStraightAction(RobotModel *robot,
		DriveController *driveController, double distance, double maxSpeed,
		double minTime, double timeout, bool wantMinTime) {
	this->driveController = driveController;
	this->distance = distance;
	this->timeout = timeout;
	this->robot = robot;
	this->maxSpeed = maxSpeed;
	this->minTime = minTime;
	this->wantMinTime = wantMinTime;
	reachedSetpoint = false;
	target_pass = 0;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = robot->pini->getf("DRIVE_PID", "drive_p", 0.0);
	I = robot->pini->getf("DRIVE_PID", "drive_i", 0.0);
	D = robot->pini->getf("DRIVE_PID", "drive_d", 0.0);
}

bool DriveSetPointStraightAction::IsFinished() {
	return (Timer::GetFPGATimestamp() >= start_time + timeout) || (reachedSetpoint);
}

void DriveSetPointStraightAction::Update() {
	if (driveController->leftPID->OnTarget()
			&& driveController->rightPID->OnTarget()
			&& (Timer::GetFPGATimestamp() >= start_time + minTime)) {
		reachedSetpoint = true;
	} else {
		reachedSetpoint = false;
	}
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", true);
}

void DriveSetPointStraightAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", false);
	driveController->Stop();
}

void DriveSetPointStraightAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->leftPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->leftPID->SetPID(P, I, D);
	driveController->leftPID->SetSetpoint(distance + leftEncoderStartDistance);

	driveController->rightPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->rightPID->SetPID(P, I, D);
	driveController->rightPID->SetSetpoint(
			distance + rightEncoderStartDistance);

	driveController->leftPID->Enable();
	driveController->rightPID->Enable();
}
