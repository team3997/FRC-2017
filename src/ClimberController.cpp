/*
 * ClimberController.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: peter
 */

#include "ClimberController.h"
#include "Timer.h"
#include "Params.h"

ClimberController::ClimberController(RobotModel* myRobot,
    RemoteControl* myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;

  m_stateVal = kInitialize;
  nextState = kInitialize;
}
void ClimberController::Reset() {
  m_stateVal = kInitialize;
}
void ClimberController::Update() {
  switch (m_stateVal) {
  case (kInitialize):
    nextState = kTeleop;
    break;
  case (kTeleop):
    //Climber Behaviour
	if (humanControl->GetClimberDesired()) {
      robot->SetClimberMotorSpeed(CLIMBER_HARDSET_MOTOR_SPEED);
	}
	else {
	  robot->climberMotor->SetSpeed(0.0);
	}

    nextState = kTeleop;
    break;
  }

  m_stateVal = nextState;
}

ClimberController::~ClimberController() {
  // TODO Auto-generated destructor stub
}

