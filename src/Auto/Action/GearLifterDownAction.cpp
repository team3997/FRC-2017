
#include "GearLifterDownAction.h"
#include "../../Params.h"

//distance: distance in inches for the bot to drive
//maxSpeed: max speed robot can drive to hit setpoint
//timeout: amount of allowed time this action can run before ending
GearLifterDownAction::GearLifterDownAction(RobotModel *robot, DriveController *driveController, GearController *gearController,
		double distance, double maxSpeed, double timeout, bool waitForTimeout) {
	this->driveController = driveController;
	this->gearController = gearController;
	this->distance = distance;
	this->timeout = timeout;
	this->robot = robot;
	this->maxSpeed = maxSpeed;
	this->waitForTimeout = waitForTimeout;
	reachedSetpoint = false;
	target_pass = 0;
	leftEncoderStartDistance, rightEncoderStartDistance = 0.0;

	P = robot->pini->getf("DRIVE_PID", "drive_p", 0.0);
	I = robot->pini->getf("DRIVE_PID", "drive_i", 0.0);
	D = robot->pini->getf("DRIVE_PID", "drive_d", 0.0);
}

bool GearLifterDownAction::IsFinished() {
	if(waitForTimeout)
        return (Timer::GetFPGATimestamp() >= start_time + timeout);
	else
        return (Timer::GetFPGATimestamp() >= start_time + timeout) || reachedSetpoint;

}

void GearLifterDownAction::Update() {
	if (driveController->leftPID->OnTarget() && driveController->rightPID->OnTarget()) {
		reachedSetpoint = true;
	} else {
		reachedSetpoint = false;
	}

	robot->gearIntakeMotor->Set(-GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
	if(robot->gearPot->Get() <= 0.32) {
		robot->SetGearTilterSpeed(0.1);
	}
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", true);
}

void GearLifterDownAction::Done() {
	driveController->leftPID->Disable();
	driveController->rightPID->Disable();
	gearController->gearTilterPID->Disable();
	SmartDashboard::PutBoolean("ACTION_DriveSetpointStraight", false);
	driveController->Stop();
}

void GearLifterDownAction::Start() {
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

	gearController->gearTilterPID->Disable();
}

