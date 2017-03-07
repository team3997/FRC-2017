/*
 * RobotModel.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#include "WPILib.h"
#include "RobotModel.h"
#include "Ports.h"
#include <math.h>

//RobotModel constructor: inits all variables and objects
RobotModel::RobotModel() {
	pdp = new PowerDistributionPanel();

	//Init drive motors
	leftDriveMotorA = new Spark(LEFT_DRIVE_MOTOR_A_PWM_PORT);
	leftDriveMotorB = new Spark(LEFT_DRIVE_MOTOR_B_PWM_PORT);
	rightDriveMotorA = new Spark(RIGHT_DRIVE_MOTOR_A_PWM_PORT);
	rightDriveMotorB = new Spark(RIGHT_DRIVE_MOTOR_B_PWM_PORT);

	//Init superstructure motors
	climberMotor = new Talon(CLIMBER_MOTOR_PWM_PORT);
	feederMotor = new Talon(FEEDER_MOTOR_PWM_PORT);

	//Init shooter motors
	shooterMotorA = new VictorSP(SHOOTER_MOTOR_A_PWM_PORT);
	shooterMotorB = new VictorSP(SHOOTER_MOTOR_B_PWM_PORT);

	//Init encoders
	shooterEncoder = new Encoder(SHOOTER_ENCODER_PORTS[0],
			SHOOTER_ENCODER_PORTS[1]);
	leftDriveEncoder = new Encoder(LEFT_DRIVE_ENCODER_PORTS[0],
			LEFT_DRIVE_ENCODER_PORTS[1]);
	rightDriveEncoder = new Encoder(RIGHT_DRIVE_ENCODER_PORTS[0],
			RIGHT_DRIVE_ENCODER_PORTS[1]);

	shooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
	shooterEncoder->SetDistancePerPulse((1.0) / (250.0));
	shooterEncoder->SetSamplesToAverage(90);
	climberMotor->SetSafetyEnabled(false);

	shooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
	leftDriveEncoder->SetReverseDirection(false);
	leftDriveEncoder->SetDistancePerPulse(((1.0) / (250.0)) * ((4.0) * (M_PI)));
	leftDriveEncoder->SetSamplesToAverage(90);
	rightDriveEncoder->SetReverseDirection(false);
	rightDriveEncoder->SetDistancePerPulse(
			((1.0) / (250.0)) * ((4.0) * (M_PI)));
	rightDriveEncoder->SetSamplesToAverage(90);

	leftDriveMotorA->SetSafetyEnabled(false);
	leftDriveMotorB->SetSafetyEnabled(false);
	rightDriveMotorA->SetSafetyEnabled(false);
	rightDriveMotorB->SetSafetyEnabled(false);
	shooterMotorA->SetSafetyEnabled(false);
	shooterMotorB->SetSafetyEnabled(false);
	feederMotor->SetSafetyEnabled(false);
	climberMotor->SetInverted(true);

	leftDriveMotorA->SetInverted(false);
	leftDriveMotorB->SetInverted(false);
	rightDriveMotorA->SetInverted(false);
	rightDriveMotorB->SetInverted(false);
	shooterMotorA->SetInverted(true);
	shooterMotorB->SetInverted(true);
	feederMotor->SetInverted(true);

	leftDriveACurrent = 0;
	leftDriveBCurrent = 0;
	rightDriveACurrent = 0;
	rightDriveBCurrent = 0;
	shooterMotorACurrent = 0;
	shooterMotorBCurrent = 0;

	timer = new Timer();
	timer->Start();
	pini = new Ini("/home/lvuser/robot.ini");
}

RobotModel::~RobotModel() {
	// TODO Auto-generated destructor stub
}

//resets variables and objects
void RobotModel::Reset() {
	ResetEncoders();
}

//returns the voltage
double RobotModel::GetVoltage() {
	return pdp->GetVoltage();
}

//returns the total energy of the PDP
double RobotModel::GetTotalCurrent() {
	return pdp->GetTotalCurrent();
}
//returns the total current of the PDP
double RobotModel::GetTotalEnergy() {
	return pdp->GetTotalEnergy();
}

//returns the total power of the PDP
double RobotModel::GetTotalPower() {
	return pdp->GetTotalPower();
}

//initializes variables pertaining to current
void RobotModel::UpdateCurrent() {
	leftDriveACurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_A_PDP_CHAN);
	leftDriveBCurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_B_PDP_CHAN);
	rightDriveACurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_A_PDP_CHAN);
	rightDriveBCurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_B_PDP_CHAN);

	shooterMotorACurrent = pdp->GetCurrent(SHOOTER_MOTOR_A_PDP_CHAN);
	shooterMotorBCurrent = pdp->GetCurrent(SHOOTER_MOTOR_B_PDP_CHAN);
	climberMotorCurrent = pdp->GetCurrent(CLIMBER_MOTOR_PDP_CHAN);
}

//returns the current of a given channel
double RobotModel::GetCurrent(int channel) {
	switch (channel) {
	case RIGHT_DRIVE_MOTOR_A_PDP_CHAN:
		return rightDriveACurrent;
		break;
	case RIGHT_DRIVE_MOTOR_B_PDP_CHAN:
		return rightDriveBCurrent;
		break;
	case LEFT_DRIVE_MOTOR_A_PDP_CHAN:
		return leftDriveACurrent;
		break;
	case LEFT_DRIVE_MOTOR_B_PDP_CHAN:
		return leftDriveBCurrent;
		break;
	case SHOOTER_MOTOR_A_PDP_CHAN:
		return shooterMotorACurrent;
		break;
	case SHOOTER_MOTOR_B_PDP_CHAN:
		return shooterMotorBCurrent;
	case CLIMBER_MOTOR_PDP_CHAN:
		return climberMotorCurrent;
	default:
		return -1;
	}
}

//sets the speed for a given wheel(s)
void RobotModel::SetWheelSpeed(Wheels w, double speed) {
	switch (w) {
	case (LeftWheels):
		leftDriveMotorA->Set(speed);
		leftDriveMotorB->Set(speed);
		break;
	case (RightWheels):
		rightDriveMotorA->Set(-speed); //negative value since wheels are inverted on robot
		rightDriveMotorB->Set(-speed); //negative value since wheels are inverted on robot
		break;
	case (AllWheels):
		leftDriveMotorA->Set(speed);
		leftDriveMotorB->Set(speed);
		rightDriveMotorA->Set(-speed); //negative value since wheels are inverted on robot
		rightDriveMotorB->Set(-speed); //negative value since wheels are inverted on robot
		break;
	}
}

//returns the speed of a given wheel
float RobotModel::GetWheelSpeed(Wheels w) {
	switch (w) {
	case (LeftWheels):
		return leftDriveMotorA->Get();
		break;
	case (RightWheels):
		return -rightDriveMotorA->Get();
		break;
	default:
		return 0.0;
		break;
	}
}

//resets the time
void RobotModel::ResetTimer() {
	timer->Reset();
}

void RobotModel::ResetEncoders() {
	shooterEncoder->Reset();
	leftDriveEncoder->Reset();
	rightDriveEncoder->Reset();
}

//returns the time
double RobotModel::GetTime() {
	return timer->Get();
}

// SUPERSTRUCTURE ACCESSORS AND MUTATORS IN ROBOTMODEL

void RobotModel::SetShooterMotorsSpeed(double speed) {
	shooterMotorA->Set(speed);
	shooterMotorB->Set(speed);
}

double RobotModel::GetShooterMotorASpeed() {
	return shooterMotorA->Get();
}

double RobotModel::GetShooterMotorBSpeed() {
	return shooterMotorB->Get();
}

void RobotModel::SetClimberMotorSpeed(double speed) {
	climberMotor->Set(speed);
}

double RobotModel::GetClimberMotorSpeed() {
	return climberMotor->Get();
}

void RobotModel::SetFeederMotorSpeed(double speed) {
	feederMotor->Set(speed);
}

double RobotModel::GetFeederMotorSpeed() {
	return feederMotor->Get();
}
void RobotModel::RefreshIni() {
	delete pini;
	pini = new Ini("/home/lvuser/robot.ini");
}

