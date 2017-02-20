#include "WPILib.h"
#include "Params.h"
#include "DriveController.h"
#include "RobotModel.h"
#include "ControlBoard.h"

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
      ArcadeDrive(driverLeftX, driverRightY, true);
    } else {
      TankDrive(driverLeftY, driverRightY, true);
    }

    nextState = kTeleopDrive;
    break;
  } // end of switch

  m_stateVal = nextState;
}

void DriveController::ArcadeDrive(double myY, double myX, bool teleOp) {

  if (teleOp) {
    if (humanControl->GetReverseDriveDesired()) {
      myX = -myX;
      myY = -myY;
    }

    driveTrain->ArcadeDrive(myX, myY, SQUARE_DRIVE_AXIS_INPUT);

  } else {
    driveTrain->ArcadeDrive(myX, myY, false);
  }

  driveTrain->ArcadeDrive(myY, myX, SQUARE_DRIVE_AXIS_INPUT);
}

void DriveController::TankDrive(double myLeft, double myRight, bool teleOp) {
  if (teleOp) {
      if (humanControl->GetReverseDriveDesired()) {
        myLeft = -myLeft;
        myRight = -myRight;
      }

      driveTrain->TankDrive(myLeft, myRight, SQUARE_DRIVE_AXIS_INPUT);

    } else {
      driveTrain->TankDrive(myLeft, myRight, false);
    }

    driveTrain->TankDrive(myLeft, myRight, false);
}

void DriveController::Reset() {
  m_stateVal = kInitialize;
}
