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
    gearTilterPID->SetOutputRange(-0.7, 0.7);
    gearTilterPID->SetAbsoluteTolerance(1);
	gearTilterPID->SetPID(0.0, 0.0, 0.0);
	gearTilterPID->SetSetpoint(0);
	gearTilterPID->Disable();

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
            nextState = kTeleop;
            break;
        case (kTeleop):
			if(humanControl->GetGearTitlerIntakeDesired()){
				robot->SetGearIntakeSpeed(GEAR_WHEELS_MOTOR_SPEED);
			}
			else if(humanControl->GetGearTitlerOuttakeDesired()){
				robot->SetGearIntakeSpeed(-GEAR_WHEELS_MOTOR_SPEED);
			}
			else {
				robot->SetGearIntakeSpeed(0.0);
			}

        	if(humanControl->GetGearTitlerDownDesired()){
        		gearTilterPID->Enable();
        	}
        	else {
        		gearTilterPID->Disable();
        	}

            nextState = kTeleop;
            break;
    }  // end of switch

    m_stateVal = nextState;
}
GearController::~GearController() {
    // TODO Auto-generated destructor stub
}

