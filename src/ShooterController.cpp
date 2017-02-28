#include "WPILib.h"
#include "Params.h"
#include "ShooterController.h"
#include "RobotModel.h"

ShooterController::ShooterController(RobotModel *myRobot,
		RemoteControl *myHumanControl) {
	robot = myRobot;
	humanControl = myHumanControl;

	shooterP = SHOOTER_PID_VALUES[0];
	shooterI = SHOOTER_PID_VALUES[1];
	shooterD = SHOOTER_PID_VALUES[2];

	pidOutput = new ShooterMotorsPIDOutput(robot->shooterMotorA,
			robot->shooterMotorB);
	shooterPID = new PIDController(shooterP, shooterI, shooterD,
			robot->shooterEncoder, pidOutput);

	shooterPID->SetPIDSourceType(PIDSourceType::kRate);

	shooterPID->SetSetpoint(SHOOTER_PID_SETPOINT);
	shooterPID->SetAbsoluteTolerance(100.0 / 60.0);
	shooterPID->Disable();
	m_stateVal = kInitialize;
	nextState = kInitialize;
}

ShooterController::~ShooterController() {

}

void ShooterController::Reset() {
	m_stateVal = kInitialize;
}

void ShooterController::Update(double currTimeSec, double deltaTimeSec) {
	switch (m_stateVal) {
	case (kInitialize):
		nextState = kTeleop;
		break;
	case (kTeleop):
		//Shooter Behaviour
		if (humanControl->GetFeederReverseDesired()) {
			robot->SetFeederMotorSpeed(-FEEDER_HARDSET_MOTOR_SPEED);
			robot->SetShooterMotorsSpeed(-0.8);
		} else if (humanControl->GetShooterRunDesired()) {
			if (SHOOTER_USE_PID) {
				shooterPID->Enable();
			} else {
				robot->SetShooterMotorsSpeed(SHOOTER_HARDSET_MOTOR_SPEED);
			}

			if ((robot->shooterEncoder->GetRate() * 60.0) >= SHOOTER_THRESHOLD_FOR_FEEDER) {
				robot->SetFeederMotorSpeed(FEEDER_HARDSET_MOTOR_SPEED);
			} else {
				robot->SetFeederMotorSpeed(0.0);
			}
		} else {
			if (SHOOTER_USE_PID) {
				shooterPID->Disable();
			} else {
				robot->SetShooterMotorsSpeed(0.0);
			}

			robot->SetFeederMotorSpeed(0.0);
		}
		nextState = kTeleop;
		break;
	}

	m_stateVal = nextState;
}
