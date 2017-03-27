#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "LightsController.h"
#include "ShooterController.h"
#include "ClimberController.h"
#include "DriveController.h"
#include "VisionController.h"
#include "GearSuck.h"
#include <string.h>
#include "Auto/Auto.h"

class MainProgram : public frc::IterativeRobot {

	//Creates a robot from class RobotModel
	RobotModel *robot;

	//Creates a human control from RemoteControl, which includes ControlBoard
	RemoteControl *humanControl;
	VisionController *visionController;

	//Creates a controller for drivetrain and superstructure
	DriveController *driveController;
	ShooterController *shooterController;

	//Creates an object of Dashboardlogger
	DashboardLogger *dashboardLogger;

	ClimberController *climberController;

	LightsController* lights;
	GearSuck *gearController;
	Auto* auton;
	CameraServer *camera;

	//LightsController *lights;

	//Creates a time-keeper	`
	double currTimeSec;
	double lastTimeSec;
	double deltaTimeSec;

public:
	MainProgram(void) {
		robot             = new RobotModel();
		humanControl      = new ControlBoard();
		lights            = new LightsController(humanControl);
		visionController  = new VisionController();
		driveController   = new DriveController(robot, humanControl, visionController);
		dashboardLogger   = new DashboardLogger(robot, humanControl);
		shooterController = new ShooterController(robot, humanControl);
		climberController = new ClimberController(robot, humanControl);
		gearController    = new GearSuck(robot, humanControl);
		auton             = new Auto(visionController, driveController, robot, lights);
		//lights            = new LightsController(humanControl);
		//Initializes timekeeper variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;
	}
private:
	void RobotInit() {
		RefreshAllIni();
		robot->ResetTimer();
		robot->Reset();
		auton->ListOptions();
		visionController->Disable();
        camera = CameraServer::GetInstance();
        camera->StartAutomaticCapture();
        SmartDashboard::PutNumber("VISION_leftContour", 0.0);
        SmartDashboard::GetNumber("VISION_rightContour", 0.0);
	}

	void AutonomousInit() {
		auton->Stop();
		RefreshAllIni();
		robot->ResetTimer();
		robot->ResetEncoders();

		driveController->Reset();

		//Resets timer variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;

		visionController->Enable();
		auton->Start();

	}

	void AutonomousPeriodic() {
		//Autonoumous is running in a thread called by "auton->Start();"
		dashboardLogger->UpdateData(); //JOystick data does NOT update during autonomous
		visionController->Update();
		//lights->Update(true);
		SmartDashboard::PutNumber("LEFT", visionController->GetLeftContour());
		SmartDashboard::PutNumber("RIGHT", visionController->GetRightContour());
	}

	void TeleopInit() {
	    lights->SetEnabledRoutine();
		auton->Stop();
		RefreshAllIni();
		robot->ResetTimer();
		robot->ResetEncoders();

		driveController->Reset();
		shooterController->Reset();
		climberController->Reset();

		//Resets timer variables
		currTimeSec = 0.0;
		lastTimeSec = 0.0;
		deltaTimeSec = 0.0;

		visionController->Enable();
	}

	void TeleopPeriodic() {
		dashboardLogger->UpdateData();

		//Updates timer
		lastTimeSec = currTimeSec;
		currTimeSec = robot->GetTime();
		deltaTimeSec = currTimeSec - lastTimeSec;

		/*if (humanControl->GetResetEncodersDesired()){
		    robot->leftDriveEncoder->Reset();
		    robot->rightDriveEncoder->Reset();
		    robot->shooterEncoder->Reset();
	    }*/

		//Reads controls and updates controllers accordingly
		RefreshAllIni();
		humanControl->ReadControls();
		driveController->Update(currTimeSec, deltaTimeSec);
		shooterController->Update(currTimeSec, deltaTimeSec);
		climberController->Update();
		visionController->Update();
		gearController->Update();
		if(humanControl->GetClimberDesired()) {
		    lights->Climbing();
		} else if(humanControl->GetShoutRoutineDesired()) {
		    lights->SetShoutRoutine();
		} else {
		    lights->SetEnabledRoutine();
		}
	}

	void DisabledInit() {
		auton->Stop();

		RefreshAllIni();

		robot->ResetEncoders();
		driveController->Reset();
		shooterController->Reset();
		climberController->Reset();
		visionController->Disable();
		lights->SetDisabledRoutine();
	}

	void DisabledPeriodic() {

		dashboardLogger->UpdateData();
		//robot->UpdateCurrent();
		//auton->Stop();
		//Reads controls and updates controllers accordingly

		//lights->Update(false);
		visionController->Update();
	    humanControl->ReadControls();
	    RefreshAllIni();
	}
	void RefreshAllIni() {
	    robot->RefreshIni();
	    driveController->RefreshIni();
	    SmartDashboard::PutNumber("H_LOW", robot->pini->getf("CAMERA", "h_low", 0));
        SmartDashboard::PutNumber("H_HIGH", robot->pini->getf("CAMERA", "h_high", 0));
        SmartDashboard::PutNumber("S_LOW", robot->pini->getf("CAMERA", "s_low", 0));
        SmartDashboard::PutNumber("S_HIGH", robot->pini->getf("CAMERA", "s_high", 0));
        SmartDashboard::PutNumber("V_LOW", robot->pini->getf("CAMERA", "v_low", 0));
        SmartDashboard::PutNumber("V_HIGH", robot->pini->getf("CAMERA", "v_HIGH", 0));

        robot->pini->getf("PINI", "PINI_P", 0.0);
		robot->pini->getf("PINI", "PINI_I", 0.0);
		robot->pini->getf("PINI", "PINI_D", 0.0);
	}
};

START_ROBOT_CLASS(MainProgram);
