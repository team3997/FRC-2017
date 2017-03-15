/*
 * VisionSetpointXAction.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#include "Auto/Action/VisionSetpointXAction.h"

VisionSetpointXAction::VisionSetpointXAction(VisionController *vision, DriveController *driveController, RobotModel *robot, int setpoint, double maxSpeed, double timeout, bool waitForTimeout) {
	// TODO Auto-generated constructor stub
	this->vision = vision;
	this->driveController = driveController;
	this->setpoint = setpoint;
	this->maxSpeed = maxSpeed;
	this->robot = robot;
	this->timeout = timeout;
	this->waitForTimeout = waitForTimeout;

	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	//P = 1.0 / 250.0;
	//I = 0.0;
	//D = 1.0 / 150.0;

	P = 1.0 / robot->pini->getf("PINI", "PINI_P", 0.0);
	I = 1.0 / robot->pini->getf("PINI", "PINI_I", 0.0);
	D = 1.0 / robot->pini->getf("PINI", "PINI_D", 0.0);
}

bool VisionSetpointXAction::IsFinished() {
	if(waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
	else
		return (Timer::GetFPGATimestamp() >= start_time + timeout) || (driveController->visionPID->OnTarget());
}

void VisionSetpointXAction::Update() {

	if(driveController->vision->GetRightContour() == 0.0){
		driveController->visionPID->Disable();
		SmartDashboard::PutString("Running_VISION", "STOPPED");
	}
	else {
		driveController->visionPID->Enable();
		SmartDashboard::PutString("Running_VISION", "RUNNING");
	}
}

void VisionSetpointXAction::Done() {
	driveController->visionPID->Disable();
	driveController->Stop();
	SmartDashboard::PutString("Running_VISION", "DONE");
}

void VisionSetpointXAction::Start() {
	start_time = Timer::GetFPGATimestamp();

	robot->leftDriveEncoder->Reset();
	robot->rightDriveEncoder->Reset();

	leftEncoderStartDistance = robot->leftDriveEncoder->GetDistance();
	rightEncoderStartDistance = robot->rightDriveEncoder->GetDistance();

	driveController->visionPID->SetOutputRange(-maxSpeed, maxSpeed);
	SmartDashboard::PutNumber("Vision_P", P);
	SmartDashboard::PutNumber("Vision_I", I);
	SmartDashboard::PutNumber("Vision_D", D);
	driveController->visionPID->SetPID(P, I, D);
	driveController->visionPID->SetSetpoint(setpoint + leftEncoderStartDistance);

	driveController->visionPID->Enable();
}

VisionSetpointXAction::~VisionSetpointXAction() {

}
