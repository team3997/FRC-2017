#include "WPILib.h"
#include "Params.h"
#include "DriveController.h"
#include "RobotModel.h"

DriveController::DriveController(RobotModel *myRobot,
    RemoteControl *myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;
  driveTrain = new RobotDrive(robot->leftDriveMotorA, robot->leftDriveMotorB,
      robot->rightDriveMotorA, robot->rightDriveMotorB);

  m_stateVal = kInitialize;
  nextState = kInitialize;
}

DriveController::~DriveController() {
}

void DriveController::Update(double currTimeSec, double deltaTimeSec) {
  switch (m_stateVal) {
  case (kInitialize):
    nextState = kTeleopDrive;
    break;
  case (kTeleopDrive):
    double driverLeftX;
    driverLeftX = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kLX);
    double driverLeftY;
    driverLeftY = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kLY);
    double driverRightX;
    driverRightX = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kRX);
    double driverRightY;
    driverRightY = humanControl->GetJoystickValue(RemoteControl::kDriverJoy,
        RemoteControl::kRY);

    if (humanControl->GetArcadeDriveDesired()) {
      ArcadeDrive(driverLeftY, -driverRightX);
    } else {
      TankDrive(driverLeftY, driverRightY);
    }

    nextState = kTeleopDrive;
    break;
  } // end of switch

  m_stateVal = nextState;
}

void DriveController::ArcadeDrive(double myY, double myX) {
  if (humanControl->GetReverseDriveDesired()) {
    myX = -myX;
    myY = -myY;
  }

  if (humanControl->GetClimberDesired()){
	  GLOBAL_DRIVE_SPEED_MULTIPLIER = 0.5;
	  SQUARE_DRIVE_AXIS_INPUT = false;
  }
  else {
	  GLOBAL_DRIVE_SPEED_MULTIPLIER = 1.0;
	  SQUARE_DRIVE_AXIS_INPUT = true;
  }

  driveTrain->ArcadeDrive(myY * GLOBAL_DRIVE_SPEED_MULTIPLIER,
		  myX * GLOBAL_DRIVE_SPEED_MULTIPLIER, SQUARE_DRIVE_AXIS_INPUT);
}

void DriveController::TankDrive(double myLeft, double myRight) {
  if (humanControl->GetReverseDriveDesired()) {
    myLeft = -myLeft;
    myRight = -myRight;
  }

  driveTrain->TankDrive(myLeft * GLOBAL_DRIVE_SPEED_MULTIPLIER,
		  myRight * GLOBAL_DRIVE_SPEED_MULTIPLIER, SQUARE_DRIVE_AXIS_INPUT);
}

void DriveController::Reset() {
  m_stateVal = kInitialize;
}
