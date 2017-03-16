/*
 * LightsController.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: michael
 */

#include "LightsController.h"

LightsController::LightsController(RemoteControl *myHumanControl) {
	myHumanControl = humanControl;

	pin1 = new DigitalOutput(LIGHTS_DIO_PORTS[0]);
	pin2 = new DigitalOutput(LIGHTS_DIO_PORTS[1]);
}

LightsController::~LightsController() {

}

void LightsController::Reset() {
	m_stateVal = kInitialize;
}

void LightsController::Update(bool enabled) {
	switch (m_stateVal) {
	case (kInitialize):
		nextState = kTeleop;
		break;
	case (kTeleop):
		//Climber Behaviour
		if(enabled){
            if (humanControl->GetLightsActiveDesired()) {
            	SetShoutRoutine();
            }
            else {
            	SetEnabledRoutine();
            }
		}
		else {
			SetDisabledRoutine();
		}

		nextState = kTeleop;
		break;
	}

	m_stateVal = nextState;
}

void LightsController::SetDisabledRoutine(){
	pin1->Set(LOW);
	pin2->Set(LOW);
}

void LightsController::SetEnabledRoutine(){
	pin1->Set(HIGH);
	pin2->Set(LOW);
}

void LightsController::SetShoutRoutine(){
	pin1->Set(HIGH);
	pin2->Set(HIGH);
}

