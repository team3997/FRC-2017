#include "WPILib.h"
#include "Params.h"
#include "ShooterController.h"
#include "RobotModel.h"

ShooterController::ShooterController(RobotModel *myRobot, RemoteControl *myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;

  shooterP = 0.1;
  shooterI = 0.0;
  shooterD = 0.0;

  pidOutput = new ShooterMotorsPIDOutput(robot->shooterMotorA, robot->shooterMotorB);

  shooterPID = new PIDController(shooterP, shooterI, shooterD, robot->shooterEncoder, pidOutput);

  shooterPID->SetSetpoint(500);

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
    case (kTeleop):
      nextState = kTeleop;
      //Shooter Behaviour
      if(humanControl->GetShooterRunDesired()){
        if(SHOOTER_USE_PID){
               
        }
        else {
          robot->SetShooterMotorsSpeed(SHOOTER_HARDSET_MOTOR_SPEED);
        }
      }
      else { 
        if(SHOOTER_USE_PID){

        }
        else {
          robot->SetShooterMotorsSpeed(0.0);
        }
      }
      break;
  } 

  m_stateVal = nextState;
}
