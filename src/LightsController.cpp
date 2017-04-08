/*
 * LightsController.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: michael
 */

#include "LightsController.h"
#include "SmartDashboard/SmartDashboard.h"
#include "DigitalOutput.h"

LightsController::LightsController(RemoteControl *myHumanControl) {
    humanControl = myHumanControl;

	pin1 = new DigitalOutput(LIGHTS_DIO_PORTS[0]);
	pin2 = new DigitalOutput(LIGHTS_DIO_PORTS[1]);
	pin3 = new DigitalOutput(LIGHTS_DIO_PORTS[2]);
    pin4 = new DigitalOutput(LIGHTS_DIO_PORTS[3]);

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
		break;
	case (kTeleop):
        /*
		//Climber Behaviour
		if (enabled) {
			if (humanControl->GetLightsActiveDesired()) {
				SetShoutRoutine();
			} else {
				SetEnabledRoutine();
			}
		} else {
			SetDisabledRoutine();
		}*/

		nextState = kTeleop;
		break;
	}

	m_stateVal = nextState;
}

void LightsController::SetDisabledRoutine() {
	pin1->Set(LOW);
	pin2->Set(LOW);
	pin3->Set(LOW);
	pin4->Set(LOW);
}

void LightsController::SetEnabledRoutine() {
	pin1->Set(HIGH);
	pin2->Set(LOW);
    pin3->Set(LOW);
    pin4->Set(LOW);
}

void LightsController::SetShoutRoutine() {
	pin1->Set(HIGH);
	pin2->Set(HIGH);
    pin3->Set(LOW);
    pin4->Set(HIGH);
}

void LightsController::Brake2() {
    pin1->Set(HIGH);
    pin2->Set(LOW);
    pin3->Set(HIGH);
    pin4->Set(LOW);
}

void LightsController::Brake1() {
    pin1->Set(HIGH);
    pin2->Set(LOW);
    pin3->Set(LOW);
    pin4->Set(HIGH);
}


void LightsController::GearOuttake() {
    pin1->Set(HIGH);
    pin2->Set(LOW);
    pin3->Set(HIGH);
    pin4->Set(HIGH);
}

void LightsController::GearIntake() {
    pin1->Set(LOW);
    pin2->Set(HIGH);
    pin3->Set(HIGH);
    pin4->Set(LOW);
}

void LightsController::Climbing() {
    pin1->Set(LOW);
    pin2->Set(HIGH);
    pin3->Set(HIGH);
    pin4->Set(HIGH);
}
