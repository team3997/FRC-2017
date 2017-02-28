/*
 * DashboardLogger.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: mikec
 */

#include "WPILib.h"
#include "DashboardLogger.h"
#include "Ports.h"


DashboardLogger::DashboardLogger(RobotModel *myRobot, RemoteControl *myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;
}

DashboardLogger::~DashboardLogger() {
  // TODO Auto-generated destructor stub
}

void DashboardLogger::UpdateData() {
  PutDriverJoystickAxesData();
  PutDriverMotorOutputs();
  PutShooterEncoderData();
  PutDriveEncoderData();
  PutShooterMotorOutputs();
  PutGamePadButtonPress();
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

void DashboardLogger::PutShooterEncoderData() {
  SmartDashboard::PutNumber("SHOOTER_ENC_GetDistance()", robot->shooterEncoder->GetDistance());
  //SmartDashboard::PutNumber("SHOOTER_ENC_GetRate()", robot->shooterEncoder->GetRate());
  SmartDashboard::PutNumber("SHOOTER_ENC_GetRPM", robot->shooterEncoder->GetRate()*60.0);
  SmartDashboard::PutNumber("SHOOTER_ENC_GetRPMGRAPH", robot->shooterEncoder->GetRate()*60.0);
  //SmartDashboard::PutNumber("SHOOTER_ENC_GetPeriod()", robot->shooterEncoder->GetPeriod());
  //SmartDashboard::PutNumber("SHOOTER_ENC_GetRaw()", robot->shooterEncoder->GetRaw());
}

void DashboardLogger::PutDriveEncoderData() {
  SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetDistance()", robot->leftDriveEncoder->GetDistance());
  //SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetRate()", robot->leftDriveEncoder->GetRate());
  //SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetRPM", robot->leftDriveEncoder->GetRate()*60.0);
  //SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetRPMGRAPH", robot->leftDriveEncoder->GetRate()*60.0);
  //SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetPeriod()", robot->leftDriveEncoder->GetPeriod());
  //SmartDashboard::PutNumber("LEFTDRIVE_ENC_GetRaw()", robot->leftDriveEncoder->GetRaw());

  SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetDistance()", robot->rightDriveEncoder->GetDistance());
  //SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetRate()", robot->rightDriveEncoder->GetRate());
  //SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetRPM", robot->rightDriveEncoder->GetRate()*60.0);
  //SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetRPMGRAPH", robot->rightDriveEncoder->GetRate()*60.0);
  //SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetPeriod()", robot->rightDriveEncoder->GetPeriod());
  //SmartDashboard::PutNumber("RIGHTDRIVE_ENC_GetRaw()", robot->rightDriveEncoder->GetRaw());
}

void DashboardLogger::PutShooterMotorOutputs() {
  SmartDashboard::PutNumber("MOTOR_shooterMotorA", robot->shooterMotorA->Get());
  SmartDashboard::PutNumber("MOTOR_shooterMotorB", robot->shooterMotorB->Get());
}

void DashboardLogger::PutDriverJoystickAxesData() {
  SmartDashboard::PutNumber("JOY_driverLeftX",
      humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
          RemoteControl::kLX));
  SmartDashboard::PutNumber("JOY_driverLeftY",
      humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
          RemoteControl::kLY));
  SmartDashboard::PutNumber("JOY_driverRightX",
      humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
          RemoteControl::kRX));
  SmartDashboard::PutNumber("JOY_driverRightY",
      humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
          RemoteControl::kRY));
}

void DashboardLogger::PutGamePadButtonPress() {
  SmartDashboard::PutBoolean("BUTTON_shooterRunDesired", humanControl->GetShooterRunDesired());
  SmartDashboard::PutBoolean("BUTTON_reverseDriveDesired", humanControl->GetReverseDriveDesired());
  SmartDashboard::PutBoolean("BUTTON_climberRunDesired", humanControl->GetClimberDesired());
}

void DashboardLogger::PutDriverMotorOutputs() {
  SmartDashboard::PutNumber("MOTOR_leftDriveMotorA", robot->leftDriveMotorA->Get());
  SmartDashboard::PutNumber("MOTOR_leftDriveMotorB", robot->leftDriveMotorB->Get());
  SmartDashboard::PutNumber("MOTOR_rightDriveMotorA", robot->rightDriveMotorA->Get());
  SmartDashboard::PutNumber("MOTOR_rightDriveMotorB", robot->rightDriveMotorB->Get());
}

