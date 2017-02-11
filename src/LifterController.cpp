/*
 * LifterController.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: peter
 */

#include <LifterController.h>
#include "Timer.h"
LifterController::LifterController(RobotModel* myRobot,
    RemoteControl* myHumanControl) {
  robot = myRobot;
  humanControl = myHumanControl;

  m_stateVal = kInitialize;
  nextState = kInitialize;
}
void LifterController::Reset() {
  m_stateVal = kInitialize;
}
void LifterController::Update() {
  switch (m_stateVal) {
  case (kInitialize):
    nextState = kTeleop;
    break;
  case (kTeleop):
    //Lifter Behaviour
    StartLifter();

    nextState = kTeleop;
    break;
  }

  m_stateVal = nextState;
}

void LifterController::StartLifter() {
  if (humanControl->GetLiftDesired()) {
    robot->liftMotor->SetSpeed(0.5);
  }
  robot->liftMotor->SetSpeed(0.0);
}

LifterController::~LifterController() {
  // TODO Auto-generated destructor stub
}

