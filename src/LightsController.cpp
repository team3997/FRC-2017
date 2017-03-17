/*
 * LightsController.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: michael
 */

#include "LightsController.h"

LightsController::LightsController(RemoteControl *myHumanControl) {
    humanControl = myHumanControl;

	pin1 = new DigitalOutput(LIGHTS_DIO_PORTS[0]);
	pin2 = new DigitalOutput(LIGHTS_DIO_PORTS[1]);

	m_stateVal = kInitialize;
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
		SmartDashboard::PutString("LIGHTS_debug", "init reached");
		break;
	case (kTeleop):

		//Climber Behaviour
		if (enabled) {
			if (humanControl->GetLightsActiveDesired()) {
				SetShoutRoutine();
			} else {
				SetEnabledRoutine();
				SmartDashboard::PutString("LIGHTS_debug_2", "enabled reached");
			}
		} else {
			SetDisabledRoutine();
			SmartDashboard::PutString("LIGHTS_debug_3", "disabled reached");
		}

		nextState = kTeleop;
		break;
	}

	m_stateVal = nextState;
}

void LightsController::SetDisabledRoutine() {
	pin1->Set(LOW);
	pin2->Set(LOW);
}

void LightsController::SetEnabledRoutine() {
	pin1->Set(HIGH);
	pin2->Set(LOW);
}

void LightsController::SetShoutRoutine() {
	pin1->Set(HIGH);
	pin2->Set(HIGH);
}

