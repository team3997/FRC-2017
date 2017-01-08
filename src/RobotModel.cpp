/*
 * RobotModel.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#include "RobotModel.h"

//RobotModel constructor: inits all variables and objects
RobotModel::RobotModel() {
  pdp = new PowerDistributionPanel();

  leftDriveMotorA = new Talon(LEFT_DRIVE_MOTOR_A_PWM_PORT);
  leftDriveMotorB = new Talon(LEFT_DRIVE_MOTOR_B_PWM_PORT);
  rightDriveMotorA = new Talon(RIGHT_DRIVE_MOTOR_A_PWM_PORT);
  rightDriveMotorB = new Talon(RIGHT_DRIVE_MOTOR_B_PWM_PORT);

  leftDriveMotorA->SetSafetyEnabled(false);
  leftDriveMotorB->SetSafetyEnabled(false);
  rightDriveMotorA->SetSafetyEnabled(false);
  rightDriveMotorB->SetSafetyEnabled(false);

}


//sets the speed for a given wheel(s)..used for autonomous
void RobotModel::SetWheelSpeed(Wheels w, double speed) {
  switch (w) {
  case (kLeftWheels):
    leftDriveMotorA->Set(speed);
    leftDriveMotorB->Set(speed);
    break;
  case (kRightWheels):
    rightDriveMotorA->Set(-speed); //negative value since wheels are inverted on robot
    rightDriveMotorB->Set(-speed); //negative value since wheels are inverted on robot
    break;
  case (kAllWheels):
    leftDriveMotorA->Set(speed);
    leftDriveMotorB->Set(speed);
    rightDriveMotorA->Set(-speed); //negative value since wheels are inverted on robot
    rightDriveMotorB->Set(-speed); //negative value since wheels are inverted on robot
    break;
  }
}

//returns the speed of a given wheel
float RobotModel::GetWheelSpeed(Wheels w) {
    switch(w) {
    case (kLeftWheels):
        return leftDriveMotorA->Get();
        break;
    case (kRightWheels):
        return rightDriveMotorA->Get();
        break;
    default:
        return 0.0;
        break;
    }
}

//initializes variables pertaining to current
/*void RobotModel::UpdateCurrent() {
    leftDriveACurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_A_PDP_CHAN);
    leftDriveBCurrent = pdp->GetCurrent(LEFT_DRIVE_MOTOR_B_PDP_CHAN);
    rightDriveACurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_A_PDP_CHAN);
    rightDriveBCurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_B_PDP_CHAN);
    intakeCurrent = pdp->GetCurrent(RIGHT_DRIVE_MOTOR_B_PDP_CHAN);
    compressorCurrent = compressor->GetCompressorCurrent();
    roboRIOCurrent = ControllerPower::GetInputCurrent();
}*/

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

RobotModel::~RobotModel() {
  // TODO Auto-generated destructor stub
}

