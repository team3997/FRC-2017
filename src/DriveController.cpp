#include "Params.h"
#include "DriveController.h"
#include "WPILib.h"

DriveController::DriveController(RobotModel *myRobot,
		RemoteControl *myHumanControl, VisionController *myVision) {
	robot = myRobot;
	vision = myVision;
	humanControl = myHumanControl;
	driveTrain = new RobotDrive(robot->leftDriveMotorA, robot->leftDriveMotorB,
			robot->rightDriveMotorA, robot->rightDriveMotorB);
	driveTrain->SetSafetyEnabled(false);

	robot->leftDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
	robot->leftDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

	robot->rightDriveEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
	robot->rightDriveEncoder->SetSamplesToAverage(DRIVE_Y_PID_SAMPLES_AVERAGE);

	leftPIDOutput = new WheelsPIDOutput(robot, robot->LeftWheels);
	leftPID = new PIDController(0.0, 0.0, 0.0, robot->leftDriveEncoder, leftPIDOutput);
	leftPID->SetOutputRange(-1.0, 1.0);
	leftPID->SetAbsoluteTolerance(0.25);
	leftPID->Disable();

	rightPIDOutput = new WheelsPIDOutput(robot, robot->RightWheels);
	rightPID = new PIDController(0.0, 0.0, 0.0, robot->rightDriveEncoder, rightPIDOutput);
	rightPID->SetOutputRange(-1.0, 1.0);
	rightPID->SetAbsoluteTolerance(0.25);
	rightPID->Disable();

	visionPIDSource = new VisionPIDSource(vision);
	driveXPIDOutput = new DriveRotateMotorsPIDOutput(driveTrain);
	visionPID = new PIDController(0.0, 0.0, 0.0, visionPIDSource, driveXPIDOutput);
	visionPID->SetOutputRange(-1.0, 1.0);
	visionPID->SetAbsoluteTolerance(1);
	visionPID->Disable();

	m_stateVal = kInitialize;
	nextState = kInitialize;
}

DriveController::~DriveController() {
}

void DriveController::Update(double currTimeSec, double deltaTimeSec) {
	switch (m_stateVal) {
	case (kInitialize):
		visionPID->Disable();
		leftPID->Disable();
		rightPID->Disable();
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

		if(leftPID->IsEnabled() || rightPID->IsEnabled()){
			leftPID->Disable();
			rightPID->Disable();
		}

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

		if((humanControl->GetSlowDriveTier1Desired() && !humanControl->GetSlowDriveTier2Desired())
				|| (!humanControl->GetSlowDriveTier1Desired() && humanControl->GetSlowDriveTier2Desired())) {
			GLOBAL_DRIVE_SPEED_MULTIPLIER = 0.65;
			SQUARE_DRIVE_AXIS_INPUT = false;
		}
		else if(humanControl->GetSlowDriveTier1Desired() && humanControl->GetSlowDriveTier2Desired()) {
			GLOBAL_DRIVE_SPEED_MULTIPLIER = 0.35;
			SQUARE_DRIVE_AXIS_INPUT = false;
		}
		else {
			GLOBAL_DRIVE_SPEED_MULTIPLIER = 1.0;
			SQUARE_DRIVE_AXIS_INPUT = true;
		}

		driveTrain->ArcadeDrive(myY * GLOBAL_DRIVE_SPEED_MULTIPLIER * HARDSET_DRIVE_SPEED_MAX,
				myX * GLOBAL_DRIVE_SPEED_MULTIPLIER * HARDSET_DRIVE_SPEED_MAX, SQUARE_DRIVE_AXIS_INPUT);

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
