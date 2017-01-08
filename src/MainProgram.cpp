#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include <string.h>

class MainProgram: public frc::IterativeRobot {
  //LiveWindow helps in Test mode
  LiveWindow *lw;
  //Creates a robot from class RobotModel
  RobotModel *robot;
  //Creates a human control from RemoteControl, which includes ControlBoard
  RemoteControl *humanControl;
public:
  MainProgram(void) {
    robot = new RobotModel();
    humanControl = new ControlBoard();
  }
private:

  void RobotInit() {

  }

  void AutonomousInit() {

  }

  void AutonomousPeriodic() {

  }

  void TeleopInit() {

  }

  void TeleopPeriodic() {

  }

  void DisabledInit() {

  }

  void DisabledPeriodic() {

  }

};

START_ROBOT_CLASS(MainProgram);
