#include "WPILib.h"
#include "ControlBoard.h"
#include "Ports.h"

//This file defines all the joysticks, buttons, other variables, and functions necessary
//to control the robot during teleop by getting human input from the driver station.

//Constructor defines all variables
ControlBoard::ControlBoard() {
  //Two Joysticks
  driverJoy = new Joystick(DRIVER_JOY_USB_PORT);
  operatorJoy = new Joystick(OPERATOR_JOY_USB_PORT);

  //Drivetrain buttons
  driveDirectionButton = new ButtonReader(driverJoy,
      DRIVE_DIRECTION_BUTTON_PORT);

  //Joystick positions that will set speed of robot movement
  driverLeftJoyX = 0;
  driverLeftJoyY = 0;
  driverRightJoyX = 0;
  driverRightJoyY = 0;

  //Drivetrain variables
  reverseDriveDesired = false;
  arcadeDriveDesired = USE_ARCADE_DRIVE;

}

//ReadControls reads the states of all the buttons and joysticks, and sets variables
//according to the values of the controls.
void ControlBoard::ReadControls() {
  ReadAllButtons();

  if (USING_WIN_DRIVER_STATION) {
    driverLeftJoyX = driverJoy->GetRawAxis(F310_WIN_LEFT_X_AXIS);
    driverLeftJoyY = -driverJoy->GetRawAxis(F310_WIN_LEFT_Y_AXIS);
    driverRightJoyX = driverJoy->GetRawAxis(F310_WIN_RIGHT_X_AXIS);
    driverRightJoyY = -driverJoy->GetRawAxis(F310_WIN_RIGHT_Y_AXIS);

    operatorLeftJoyX = operatorJoy->GetRawAxis(F310_WIN_LEFT_X_AXIS);
    operatorLeftJoyY = -operatorJoy->GetRawAxis(F310_WIN_LEFT_Y_AXIS);
    operatorRightJoyX = operatorJoy->GetRawAxis(F310_WIN_RIGHT_X_AXIS);
    operatorRightJoyY = -operatorJoy->GetRawAxis(F310_WIN_RIGHT_Y_AXIS);
  } else {
    driverLeftJoyX = driverJoy->GetRawAxis(F310_LINUX_LEFT_X_AXIS);
    driverLeftJoyY = driverJoy->GetRawAxis(F310_LINUX_LEFT_Y_AXIS);
    driverRightJoyX = driverJoy->GetRawAxis(F310_LINUX_RIGHT_X_AXIS);
    driverRightJoyY = driverJoy->GetRawAxis(F310_LINUX_RIGHT_Y_AXIS);

    operatorLeftJoyX = operatorJoy->GetRawAxis(F310_LINUX_LEFT_X_AXIS);
    operatorLeftJoyY = operatorJoy->GetRawAxis(F310_LINUX_LEFT_Y_AXIS);
    operatorRightJoyX = operatorJoy->GetRawAxis(F310_LINUX_RIGHT_X_AXIS);
    operatorRightJoyY = operatorJoy->GetRawAxis(F310_LINUX_RIGHT_Y_AXIS);
  }

  //DriveTrain Variables
  reverseDriveDesired = driveDirectionButton->IsDown();
}


//Returns the joystick and axis being used
double ControlBoard::GetJoystickValue(Joysticks j, Axes a) {
  switch (j) {
  case (kDriverJoy):
    if (a == kLX) {
      return driverLeftJoyX;
    } else if (a == kLY) {
      return driverLeftJoyY;
    } else if (a == kRX) {
      return driverRightJoyX;
    } else if (a == kRY) {
      return driverRightJoyY;
    }
    break;
  case (kOperatorJoy):
    if (a == kLX) {
      return operatorLeftJoyX;
    } else if (a == kLY) {
      return operatorLeftJoyY;
    } else if (a == kRX) {
      return operatorRightJoyX;
    } else if (a == kRY) {
      return operatorRightJoyX;
    }
    break;
  default:
    return 0.0;
    break;
  }
  return 0.0;
}

//Returns true if reverse drive is desired
bool ControlBoard::GetReverseDriveDesired() {
  return reverseDriveDesired;
}

//Returns true if arcade drive is desired
bool ControlBoard::GetArcadeDriveDesired() {
  return arcadeDriveDesired;
}

//Reads the values of all buttons defined by this class
void ControlBoard::ReadAllButtons() {
  driveDirectionButton->ReadValue();
}
