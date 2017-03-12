#include "WPILib.h"
#include "Params.h"
#include "ShooterController.h"
#include "RobotModel.h"

ShooterController::ShooterController(RobotModel *myRobot, RemoteControl *myHumanControl) {
	robot = myRobot;
	humanControl = myHumanControl;

	shooterP = SHOOTER_PID_VALUES[0] * SHOOTER_PID_SCALE_VALUES[0];
	shooterI = SHOOTER_PID_VALUES[1] * SHOOTER_PID_SCALE_VALUES[1];
	shooterD = SHOOTER_PID_VALUES[2] * SHOOTER_PID_SCALE_VALUES[2];

	SmartDashboard::PutNumber("SHOOTER P", shooterP);
	SmartDashboard::PutNumber("SHOOTER I", shooterI);
	SmartDashboard::PutNumber("SHOOTER D", shooterD);

	pidOutput = new ShooterMotorsPIDOutput(robot->shooterMotorA,
			robot->shooterMotorB);
	shooterPID = new PIDController(shooterP, shooterI, shooterD,
			robot->shooterEncoder, pidOutput);

	shooterPID->SetPIDSourceType(PIDSourceType::kRate);

	shooterPID->SetSetpoint(SHOOTER_PID_SETPOINT / 60.0);
	shooterPID->SetAbsoluteTolerance(100.0 / 60.0); //RPM / 60 Seconds
	shooterPID->Disable();
	m_stateVal = kInitialize;
	nextState = kInitialize;

	feederPulseBool = false;

	currentPulse = 0;
	prevPulse = 0;

	feederPulseTimer = new Timer();
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

		prevPulse = 0.0;

		feederPulseTimer->Start();
		feederPulseTimer->Reset();
		break;
	case (kTeleop):

		SmartDashboard::PutNumber("feederPulseTimer", feederPulseTimer->Get());
		SmartDashboard::PutNumber("currentPulse", currentPulse);
		SmartDashboard::PutNumber("prevPulse", prevPulse);
		//Feeder Behaviour
		if (humanControl->GetFeederReverseDesired()) {
			robot->SetFeederMotorSpeed(-FEEDER_HARDSET_MOTOR_SPEED);
		} else if (humanControl->GetFeederRunDesired()) {

			currentPulse = feederPulseTimer->Get();

			if (currentPulse - prevPulse >= FEEDER_PULSE_TIME) {
				prevPulse = currentPulse;
				feederPulseBool = !feederPulseBool;
			}

			if (feederPulseBool) {
				robot->SetFeederMotorSpeed(FEEDER_HARDSET_MOTOR_SPEED);
			} else {
				robot->SetFeederMotorSpeed(0.0);
			}

		} else {
			robot->SetFeederMotorSpeed(0.0);
		}

		//shooter Behaviour
		if (humanControl->GetShooterRunDesired()) {
			if (SHOOTER_USE_PID) {
				shooterPID->Enable();
			} else {
				robot->SetShooterMotorsSpeed(SHOOTER_HARDSET_MOTOR_SPEED);
			}

		} else if (humanControl->GetFeederReverseDesired()) {
			robot->SetShooterMotorsSpeed(-0.5);
		} else {
			if (SHOOTER_USE_PID) {
				shooterPID->Disable();
			} else {
				robot->SetShooterMotorsSpeed(0.0);
			}
		}
		nextState = kTeleop;
		break;
	}

	m_stateVal = nextState;
}
