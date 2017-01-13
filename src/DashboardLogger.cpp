/*
 * DashboardLogger.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: mikec
 */

#include "WPILib.h"
#include <DashboardLogger.h>

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
  PutRobotCurrentData();
  PutDriveMotorCurrentData();
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

void DashboardLogger::PutDriverMotorOutputs() {
  SmartDashboard::PutNumber("MOTOR_leftDriveMotorA", robot->leftDriveMotorA->Get());
  SmartDashboard::PutNumber("MOTOR_leftDriveMotorB", robot->leftDriveMotorB->Get());
  SmartDashboard::PutNumber("MOTOR_rightDriveMotorA", robot->rightDriveMotorA->Get());
  SmartDashboard::PutNumber("MOTOR_rightDriveMotorB", robot->rightDriveMotorB->Get());
}

