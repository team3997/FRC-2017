#include "WPILib.h"
#include "RobotModel.h"
#include "DriveController.h"
#include "SuperstructureController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "ShooterController.h"
#include <string.h>

class MainProgram: public frc::IterativeRobot {
  //LiveWindow helps in Test mode
  LiveWindow *lw;
  //Creates a robot from class RobotModel
  RobotModel *robot;
  //Creates a human control from RemoteControl, which includes ControlBoard
  RemoteControl *humanControl;
  //Creates a controller for drivetrain and superstructure
  DriveController *driveController;
  SuperstructureController *superstructureController;
  ShooterController *shooterController;
  //Creates an object of Dashboardlogger
  DashboardLogger *dashboardLogger;


  //Creates a time-keeper
  double currTimeSec;
  double lastTimeSec;
  double deltaTimeSec;
public:
  MainProgram(void) {
    robot = new RobotModel();
    humanControl = new ControlBoard();
    driveController = new DriveController(robot, humanControl);
    dashboardLogger = new DashboardLogger(robot, humanControl);
    superstructureController = new SuperstructureController(robot, humanControl);
    shooterController = new ShooterController(robot, humanControl);

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
    superstructureController->Reset();

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
    superstructureController->Reset();
    shooterController->Reset();

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

    //robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
    driveController->Update(currTimeSec, deltaTimeSec);
    shooterController->Update(currTimeSec, deltaTimeSec);
    superstructureController->Update(currTimeSec, deltaTimeSec);
  }

  void DisabledInit() {
	robot->ResetEncoders();
    driveController->Reset();
    superstructureController->Reset();

  }

  void DisabledPeriodic() {
    dashboardLogger->UpdateData();
    //robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
  }
};

START_ROBOT_CLASS(MainProgram);
