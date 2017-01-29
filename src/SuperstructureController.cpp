#include "SuperstructureController.h"
#include "Params.h"

SuperstructureController::SuperstructureController(RobotModel* myRobot, RemoteControl* myHumanControl) {
	robot = myRobot;
	humanControl = myHumanControl;

	m_stateVal = kInit;
	nextState = kInit;

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

	default:
	  break;
	}
	m_stateVal = nextState;
}

