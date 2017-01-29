#include "SuperstructureController.h"

SuperstructureController::SuperstructureController(RobotModel* myRobot, RemoteControl* myHumanControl) {
	robot = myRobot;
	humanControl = myHumanControl;

	m_stateVal = kInit;
	nextState = kInit;

  shooterRunSpeed = 0.0;
  usingShooterPID = true;
}

void SuperstructureController::Reset() {
	m_stateVal = kInit;
	nextState = kInit;
}

void SuperstructureController::Update(double currTimeSec, double deltaTimeSec) {
	switch(m_stateVal) {
	case (kInit):
		nextState = kIdle;
    robot->SetShooterMotorSpeed(0.0);
		break;
	case (kIdle):
		nextState = kIdle;
    
    //Shooter Behaviour
    if(humanControl->GetShooterRunDesired()){
      if(usingShooterPID){
        
      }
      else {
        robot->SetShooterMotorSpeed();
      }
    }
    else { 
      if(usingShooterPID){
      
      }
      else {
      
      }
    }

		break;
	default:
	  break;
	}
	m_stateVal = nextState;
}

