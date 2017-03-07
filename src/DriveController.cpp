
#include "Params.h"
#include "DriveController.h"
#include "WPILib.h"

DriveController::DriveController(RobotModel *myRobot,
    RemoteControl *myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;
  driveTrain = new RobotDrive(robot->leftDriveMotorA, robot->leftDriveMotorB, robot->rightDriveMotorA, robot->rightDriveMotorB);
  driveTrain->SetSafetyEnabled(false);

  robot->leftDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
  robot->leftDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

  robot->rightDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
  robot->rightDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

  /*driveEncodersPIDSource = new DriveEncodersPIDSource(robot->leftDriveEncoder, robot->rightDriveEncoder);
  driveYPIDOutput = new DriveYMotorsPIDOutput(driveTrain);
  driveYPID = new PIDController(
		  DRIVE_Y_PID_VALUES[0] * DRIVE_Y_PID_SCALE_VALUES[0],
		  DRIVE_Y_PID_VALUES[1] * DRIVE_Y_PID_SCALE_VALUES[1],
		  DRIVE_Y_PID_VALUES[2] * DRIVE_Y_PID_SCALE_VALUES[2],
		  driveEncodersPIDSource, driveYPIDOutput);/*

  //driveXPIDOutput = new DriveRotateMotorsPIDOutput(driveTrain);
  //driveXPID = new PIDController(DRIVE_X_PID_VALUES[0], DRIVE_X_PID_VALUES[1], DRIVE_X_PID_VALUES[2], driveEncodersPIDSource, driveXPIDOutput);


  /*driveYPID->SetOutputRange(-1.0, 1.0);
  driveYPID->SetPercentTolerance(DRIVE_Y_PID_TOLERANCE);

  driveYPID->Disable(); */


  //driveXPID->SetOutputRange(-1.0, 1.0);
  //driveXPID->SetPercentTolerance(DRIVE_X_PID_TOLERANCE);

  //driveXPID->Disable();

  leftPIDOutput = new WheelsPIDOutput(robot, robot->LeftWheels);
  leftPID = new PIDController(0.0, 0.0, 0.0, robot->leftDriveEncoder, leftPIDOutput);
  leftPID->SetOutputRange(-1.0, 1.0);
  leftPID->SetAbsoluteTolerance(1);
  leftPID->Disable();

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
      ArcadeDrive(driverLeftY, -driverRightX, true);
    } else {
      TankDrive(driverLeftY, driverRightY);
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
    } else {
	    GLOBAL_DRIVE_SPEED_MULTIPLIER = 1.0;
	    SQUARE_DRIVE_AXIS_INPUT = true;
    }

    driveTrain->ArcadeDrive(myY * GLOBAL_DRIVE_SPEED_MULTIPLIER, myX * GLOBAL_DRIVE_SPEED_MULTIPLIER, SQUARE_DRIVE_AXIS_INPUT);

  } else {
    driveTrain->ArcadeDrive(myY, myX, false);
  }
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

void DriveController::Stop() {
  driveTrain->ArcadeDrive(0.00, 0.00, false);
}
void DriveController::RefreshIni() {
    testVariable = robot->pini->getf("DEBUGGING", "testVariable", 0.0);
    test2Variable = robot->pini->getf("DEBUGGING", "test2Variable", 100.0);
    SmartDashboard::PutNumber("testVariable", testVariable);
    SmartDashboard::PutNumber("test2Variable", test2Variable);
}
