/*
 * GearSuck.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#include <GearSuck.h>

GearSuck::GearSuck(RobotModel* robot, RemoteControl* humanControl) {
   this->robot = robot;
   this->humanControl = humanControl;
   m_stateVal = kInitialize;
   nextState = kInitialize;
}
void GearSuck::Reset() {
   m_stateVal = kInitialize;
}
void GearSuck::Update() {
   switch (m_stateVal) {
   case (kInitialize):
       nextState = kTeleop;
       break;
   case (kTeleop):
       //Climber Behaviour
       if (humanControl->GetClimberReverseDesired()) {
           robot->SetClimberMotorSpeed(-GEAR_HARDSET_MOTOR_SPEED);
       } else if (humanControl->GetClimberDesired()) {
           robot->SetClimberMotorSpeed(GEAR_HARDSET_MOTOR_SPEED);
       } else {
           robot->SetGearMotorSpeed(0.0);
       }

       nextState = kTeleop;
       break;
   }

   m_stateVal = nextState;
}

