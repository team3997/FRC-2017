#include "WPILib.h"
#include "Params.h"
#include "XInput.h"
#include "ControlBoard.h"
#include "Ports.h"

//This file defines all the joysticks, buttons, other variables, and functions necessary
//to control the robot during teleop by getting human input from the driver station.

//Constructor defines all variables
ControlBoard::ControlBoard() {
  //Two Joysticks
  driverJoy = new Joystick(DRIVER_JOY_USB_PORT);
  //operatorJoy = new Joystick(OPERATOR_JOY_USB_PORT);

  //Drivetrain buttons
  if(USING_WIN_DRIVER_STATION){
  	driveDirectionButton = new ButtonReader(driverJoy, XINPUT_WIN_BACK_BUTTON);
  	shooterRunButton = new ButtonReader(driverJoy, XINPUT_WIN_GREEN_BUTTON);
  	climberRunButton = new ButtonReader(driverJoy, XINPUT_WIN_BLUE_BUTTON);
  	feederReverseButton = new ButtonReader(driverJoy, XINPUT_WIN_START_BUTTON);
  }
  else {
  	//driveDirectionButton = new ButtonReader(driverJoy, XINPUT_LINUX_BACK_BUTTON);
  	//shooterRunButton = new ButtonReader(driverJoy, XINPUT_LINUX_GREEN_BUTTON);
  }
  //Superstructure Buttons

  //Joystick positions that will set speed of robot movement
  driverLeftJoyX = 0;
  driverLeftJoyY = 0;
  driverRightJoyX = 0;
  driverRightJoyY = 0;

  //Drivetrain variables
  reverseDriveDesired = false;
  arcadeDriveDesired = USE_ARCADE_DRIVE;

	//Superstructure variables
  shooterRunDesired = false;

}

//ReadControls reads the states of all the buttons and joysticks, and sets variables
//according to the values of the controls.
void ControlBoard::ReadControls() {
  ReadAllButtons();

  if (USING_WIN_DRIVER_STATION) {
    driverLeftJoyX = driverJoy->GetRawAxis(XINPUT_WIN_LEFT_X_AXIS);
    driverLeftJoyY = -driverJoy->GetRawAxis(XINPUT_WIN_LEFT_Y_AXIS);
    driverRightJoyX = driverJoy->GetRawAxis(XINPUT_WIN_RIGHT_X_AXIS);
    driverRightJoyY = -driverJoy->GetRawAxis(XINPUT_WIN_RIGHT_Y_AXIS);

    /*operatorLeftJoyX = operatorJoy->GetRawAxis(XINPUT_WIN_LEFT_X_AXIS);
    operatorLeftJoyY = -operatorJoy->GetRawAxis(XINPUT_WIN_LEFT_Y_AXIS);
    operatorRightJoyX = operatorJoy->GetRawAxis(XINPUT_WIN_RIGHT_X_AXIS);
    operatorRightJoyY = -operatorJoy->GetRawAxis(XINPUT_WIN_RIGHT_Y_AXIS);*/
  } else {
    driverLeftJoyX = driverJoy->GetRawAxis(XINPUT_LINUX_LEFT_X_AXIS);
    driverLeftJoyY = driverJoy->GetRawAxis(XINPUT_LINUX_LEFT_Y_AXIS);
    driverRightJoyX = driverJoy->GetRawAxis(XINPUT_LINUX_RIGHT_X_AXIS);
    driverRightJoyY = driverJoy->GetRawAxis(XINPUT_LINUX_RIGHT_Y_AXIS);

    /*operatorLeftJoyX = operatorJoy->GetRawAxis(XINPUT_LINUX_LEFT_X_AXIS);
    operatorLeftJoyY = operatorJoy->GetRawAxis(XINPUT_LINUX_LEFT_Y_AXIS);
    operatorRightJoyX = operatorJoy->GetRawAxis(XINPUT_LINUX_RIGHT_X_AXIS);
    operatorRightJoyY = operatorJoy->GetRawAxis(XINPUT_LINUX_RIGHT_Y_AXIS);*/
  }

  //DriveTrain Variables
  reverseDriveDesired = driveDirectionButton->IsDown();

  //Superstructure Variables
  shooterRunDesired = shooterRunButton->IsDown();
  feederReverseDesired = feederReverseButton->IsDown();
  climbDesired = climberRunButton->IsDown();
}

//Reads the values of all buttons defined by this class
void ControlBoard::ReadAllButtons() {
  driveDirectionButton->ReadValue();
  shooterRunButton->ReadValue();
  feederReverseButton->ReadValue();
  climberRunButton->ReadValue();
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

//Returns true if running shooter is desired
bool ControlBoard::GetShooterRunDesired() {
  return shooterRunDesired;
}
//Returns true if arcade drive is desired
bool ControlBoard::GetArcadeDriveDesired() {
  return arcadeDriveDesired;
}

bool ControlBoard::GetClimberDesired() {
  return climbDesired;
}

bool ControlBoard::GetFeederReverseDesired() {
	return feederReverseDesired;
}

