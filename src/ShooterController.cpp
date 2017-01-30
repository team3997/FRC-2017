#include "WPILib.h"
#include "Params.h"
#include "ShooterController.h"
#include "RobotModel.h"

ShooterController::ShooterController(RobotModel *myRobot, RemoteControl *myHumanControl)
  robot = myRobot;
  humanControl = myHumanControl;

  pidType = PIDSourceType.kRate;

  m_stateVal = kInitialize;
  nextState = kInitialize;
}

ShooterController::~ShooterController() {

}

void ShooterController::Reset() {

}

void ShooterController::Update(double currTimeSec, double deltaTimeSec) {
  switch (m_stateVal) {
    case (kInitialize):
      nextState = kTeleop;
      break;
    case (kTeleopDrive):
      nextState = kTeleop;
      //Shooter Behaviour
      if(humanControl->GetShooterRunDesired()){
        if(SHOOTER_USE_PID){
               
        }
        else {
          robot->SetShooterMotorSpeed(SHOOTER_HARDSET_MOTOR_SPEED);
        }
      }
      else { 
        if(SHOOTER_USE_PID){

        }
        else {
          robot->SetShooterMotorSpeed(0.0);   
        }
      }
      break;
  } 

  m_stateVal = nextState;
}
