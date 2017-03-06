#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "ShooterController.h"
#include "ClimberController.h"
#include "DriveController.h"

class MainProgram: public frc::IterativeRobot {
	//Creates a robot from class RobotModel
	RobotModel *robot;

	//Creates a human control from RemoteControl, which includes ControlBoard
	RemoteControl *humanControl;

	//Creates a controller for drivetrain and superstructure
	DriveController *driveController;
	ShooterController *shooterController;

	//Creates an object of Dashboardlogger
	DashboardLogger *dashboardLogger;

	ClimberController *climberController;

	//Creates a time-keeper	`
	double currTimeSec;
	double lastTimeSec;
	double deltaTimeSec;

public:
	MainProgram(void) {
		robot = new RobotModel();
		humanControl = new ControlBoard();
		driveController = new DriveController(robot, humanControl);
		dashboardLogger = new DashboardLogger(robot, humanControl);
		shooterController = new ShooterController(robot, humanControl);
		climberController = new ClimberController(robot, humanControl);

		//Initializes timekeeper variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;
	}
private:
	void RobotInit() {
		robot->ResetTimer();
		robot->Reset();
	}

	void AutonomousInit() {
		robot->ResetTimer();
		robot->ResetEncoders();

		driveController->Reset();

		//Resets timer variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;
	}

	void AutonomousPeriodic() {
		dashboardLogger->UpdateData();

		//Timer is updated
		lastTimeSec = currTimeSec;
		currTimeSec = robot->GetTime();
		deltaTimeSec = currTimeSec - lastTimeSec;

		//robot->UpdateCurrent();
	}

	void TeleopInit() {
		robot->ResetTimer();
		robot->ResetEncoders();

		driveController->Reset();
		shooterController->Reset();
		climberController->Reset();

		//Resets timer variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;

	}

	void TeleopPeriodic() {
		dashboardLogger->UpdateData();

		//Updates timer
		lastTimeSec = currTimeSec;
		currTimeSec = robot->GetTime();
		deltaTimeSec = currTimeSec - lastTimeSec;

		//Reads controls and updates controllers accordingly
		humanControl->ReadControls();
		driveController->Update(currTimeSec, deltaTimeSec);
		shooterController->Update(currTimeSec, deltaTimeSec);
		climberController->Update();
	}

	void DisabledInit() {
		robot->ResetEncoders();
		driveController->Reset();
		shooterController->Reset();
		climberController->Reset();
	}

	void DisabledPeriodic() {
		dashboardLogger->UpdateData();
		humanControl->ReadControls();

	}
};

START_ROBOT_CLASS(MainProgram);
