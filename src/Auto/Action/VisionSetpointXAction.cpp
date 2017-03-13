/*
 * VisionSetpointXAction.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#include "Auto/Action/VisionSetpointXAction.h"

VisionSetpointXAction::VisionSetpointXAction(VisionController *vision,
		DriveController *driveController, RobotModel *robot, int setpoint, double maxSpeed, double timeout) {
	// TODO Auto-generated constructor stub
	this->vision = vision;
	this->driveController = driveController;
	this->setpoint = setpoint;
	this->maxSpeed = maxSpeed;
	this->robot = robot;
	this->timeout = timeout;

	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = 0;
	I = 0;
	D = 0;
}

bool VisionSetpointXAction::IsFinished() {
	return (Timer::GetFPGATimestamp() >= start_time + timeout);
}

void VisionSetpointXAction::Update() {
	if(driveController->vision->GetRightContour() == 0.0){
		driveController->visionPID->Disable();
	}
	else {
		driveController->visionPID->Enable();
	}
}

void VisionSetpointXAction::Done() {
	driveController->visionPID->Disable();
	driveController->Stop();
}

void VisionSetpointXAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->visionPID->SetOutputRange(-maxSpeed, maxSpeed);
	driveController->visionPID->SetPID(P, I, D);
	driveController->visionPID->SetSetpoint(setpoint + leftEncoderStartDistance);

	driveController->visionPID->Enable();
}

VisionSetpointXAction::~VisionSetpointXAction() {

}
