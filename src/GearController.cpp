/*
 * GearController.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: kidco
 */

#include "GearController.h"
#include "Params.h"

GearController::GearController(RobotModel* robot, RemoteControl* humanControl) {
    this->robot = robot;
    this->humanControl = humanControl;
    robot->gearPot->SetPIDSourceType(PIDSourceType::kDisplacement);
    gearTilterPIDOutput = new AnalogPIDOutput(robot);
    gearTilterPID = new PIDController(0.0, 0.0, 0.0, robot->gearPot, gearTilterPIDOutput);
    gearTilterPID->SetInputRange(-1.0, 1.0);
    gearTilterPID->SetOutputRange(-GEAR_TILTER_MAX_MOTOR_SPEED, GEAR_TILTER_MAX_MOTOR_SPEED);
    gearTilterPID->SetAbsoluteTolerance(0.01);
	gearTilterPID->SetPID(0.0, 0.0, 0.0);
	gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
	gearTilterPID->Disable();
	wasDown = true;
	wasUp = false;
    m_stateVal = kInitialize;
    nextState = kInitialize;
}

void GearController::Reset() {
	m_stateVal = kInitialize;
}

void GearController::Update() {
    switch (m_stateVal) {
        case (kInitialize):
        	gearTilterPID->Disable();
        	wasDown = true;
			gearTilterPID->SetPID(gear_p, gear_i, gear_d, gear_f);
			gearTilterPID->SetOutputRange(-1.0, 0.7);
			gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
            nextState = kTeleop;
            break;
        case (kTeleop):
			if(humanControl->GetGearTitlerIntakeDesired()){
				robot->SetGearIntakeSpeed(GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			}
			else if(humanControl->GetGearTitlerOuttakeDesired()){
				robot->SetGearIntakeSpeed(-GEAR_WHEELS_ACTIVE_MOTOR_SPEED);
			}
			else {
				robot->SetGearIntakeSpeed(GEAR_WHEELS_RESTING_MOTOR_SPEED);
			}

        	if (humanControl->GetGearTitlerDownDesired()){ //UP
        		GearPIDUp();
        	} else { //DOWN
        		GearPIDDown();
        	}

            nextState = kTeleop;
            break;
    }  // end of switch

    m_stateVal = nextState;
}

void GearController::GearPIDUp(){
	if (wasDown) {
		gearTilterPID->Reset();
	}
	wasDown = false;
	wasUp = true;
	gearTilterPID->Enable();
}

void GearController::GearPIDDown(){
	wasDown = true;
	wasUp = false;
	gearTilterPID->Disable();
	if(robot->gearPot->Get() <= 0.32) {
		robot->SetGearTilterSpeed(0.4);
	}
}

GearController::~GearController() {
    // TODO Auto-generated destructor stub
}

