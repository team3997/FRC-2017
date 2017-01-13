#include "WPILib.h"
#include "RobotModel.h"
#include "DriveController.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include <string.h>

class MainProgram: public frc::IterativeRobot {
  //LiveWindow helps in Test mode
  LiveWindow *lw;
  //Creates a robot from class RobotModel
  RobotModel *robot;
  //Creates a human control from RemoteControl, which includes ControlBoard
  RemoteControl *humanControl;
  //Creates a controller for drivetrain
  DriveController *driveController;
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

    robot->UpdateCurrent();
  }

  void TeleopInit() {

    robot->ResetTimer();

    driveController->Reset();

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

    robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
    driveController->Update(currTimeSec, deltaTimeSec);
  }

  void DisabledInit() {

    driveController->Reset();

  }

  void DisabledPeriodic() {
    dashboardLogger->UpdateData();

    robot->UpdateCurrent();

    //Reads controls and updates controllers accordingly
    humanControl->ReadControls();
  }
};

START_ROBOT_CLASS(MainProgram);
