/*
 * DashboardLogger.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: mikec
 */

#include "WPILib.h"
#include "DashboardLogger.h"
#include "Ports.h"

DashboardLogger::DashboardLogger(RobotModel *myRobot,
		RemoteControl *myHumanControl) {
	robot = myRobot;
	humanControl = myHumanControl;
}

DashboardLogger::~DashboardLogger(){
	// TODO Auto-generated destructor stub
}

void DashboardLogger::UpdateData() {
	PutDriverJoystickAxesData();
	PutDriverMotorOutputs();
	PutDriveEncoderData();
	PutGamePadButtonPress();
	SmartDashboard::PutNumber("DEBUG_FPGATimestamp", robot->timer->GetFPGATimestamp());
	SmartDashboard::PutNumber("POT_GearTilterPot", robot->gearPot->Get());
}

/*  double GetVoltage(); //returns the voltage
 double GetTotalEnergy(); //returns the total energy of the PDP
 double GetTotalCurrent(); //returns the total current of the PDP
 double GetTotalPower(); //returns the total power of the PDP
 double GetCurrent(int channel); //returns the current of a given channel*/

void DashboardLogger::PutRobotCurrentData() {
	SmartDashboard::PutNumber("PDP_Voltage", robot->GetVoltage());
	SmartDashboard::PutNumber("PDP_TotalEnergy", robot->GetTotalEnergy());
	SmartDashboard::PutNumber("PDP_TotalCurrent", robot->GetTotalCurrent());
	SmartDashboard::PutNumber("PDP_TotalPower", robot->GetTotalPower());
}

void DashboardLogger::PutDriveMotorCurrentData() {
	SmartDashboard::PutNumber("PDP_leftDriveMotorA", robot->GetCurrent(LEFT_DRIVE_MOTOR_A_PDP_CHAN));
	SmartDashboard::PutNumber("PDP_leftDriveMotorB", robot->GetCurrent(LEFT_DRIVE_MOTOR_B_PDP_CHAN));
	SmartDashboard::PutNumber("PDP_rightDriveMotorA", robot->GetCurrent(RIGHT_DRIVE_MOTOR_A_PDP_CHAN));
	SmartDashboard::PutNumber("PDP_rightDriveMotorB", robot->GetCurrent(RIGHT_DRIVE_MOTOR_B_PDP_CHAN));
}

void DashboardLogger::PutDriveEncoderData() {
	SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetDistance()", robot->leftDriveEncoder->GetDistance());
	SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetDistance()", robot->rightDriveEncoder->GetDistance());
}

void DashboardLogger::PutDriverJoystickAxesData() {
	SmartDashboard::PutNumber("DRIVERJOY_driverLeftX", humanControl->GetJoystickValue(RemoteControl::kDriverJoy, RemoteControl::kLX));
	SmartDashboard::PutNumber("DRIVERJOY_driverLeftY", humanControl->GetJoystickValue(RemoteControl::kDriverJoy, RemoteControl::kLY));
	SmartDashboard::PutNumber("DRIVERJOY_driverRightX", humanControl->GetJoystickValue(RemoteControl::kDriverJoy, RemoteControl::kRX));
	SmartDashboard::PutNumber("DRIVERJOY_driverRightY", humanControl->GetJoystickValue(RemoteControl::kDriverJoy, RemoteControl::kRY));
}

void DashboardLogger::PutGamePadButtonPress() {
	SmartDashboard::PutBoolean("BUTTON_reverseDriveDesired", humanControl->GetReverseDriveDesired());
	SmartDashboard::PutBoolean("BUTTON_slowDriveTier1Desired", humanControl->GetSlowDriveTier1Desired());
	SmartDashboard::PutBoolean("BUTTON_slowDriveTier2Desired", humanControl->GetSlowDriveTier2Desired());
	SmartDashboard::PutBoolean("BUTTON_gearTilterDownDesired", humanControl->GetGearTitlerDownDesired());
	SmartDashboard::PutBoolean("BUTTON_gearIntakeDesired", humanControl->GetGearTitlerIntakeDesired());
	SmartDashboard::PutBoolean("BUTTON_gearOuttakeDesired", humanControl->GetGearTitlerOuttakeDesired());

}

void DashboardLogger::PutDriverMotorOutputs() {
	SmartDashboard::PutNumber("MOTOR_leftDriveMotorA", robot->leftDriveMotorA->Get());
	SmartDashboard::PutNumber("MOTOR_leftDriveMotorB", robot->leftDriveMotorB->Get());
	SmartDashboard::PutNumber("MOTOR_rightDriveMotorA", robot->rightDriveMotorA->Get());
	SmartDashboard::PutNumber("MOTOR_rightDriveMotorB", robot->rightDriveMotorB->Get());
}

