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

        	if(humanControl->GetGearTitlerDownDesired()){ //UP
        		if (wasDown) {
        			gearTilterPID->Reset();
        		}
        		gearTilterPID->SetPID(
        				robot->pini->getf("GEAR_PID", "gear_p", 0.0),
						robot->pini->getf("GEAR_PID", "gear_i", 0.0),
						robot->pini->getf("GEAR_PID", "gear_d", 0.0),
						robot->pini->getf("GEAR_PID", "gear_f", 0.0));
        		gearTilterPID->SetOutputRange(-1.0, 1.0);
        		gearTilterPID->SetSetpoint(GEAR_POT_UP_POSITION);
        		wasDown = false;
        		wasUp = true;
        		gearTilterPID->Enable();
        	}
        	else if(!humanControl->GetGearTitlerDownDesired()){ //DOWN
        		/*if (wasUp) {
        			gearTilterPID->Reset();
        		}
        		gearTilterPID->SetPID(
        				robot->pini->getf("GEAR_DOWN_PID", "gear_down_p", 0.0),
						robot->pini->getf("GEAR_DOWN_PID", "gear_down_i", 0.0),
						robot->pini->getf("GEAR_DOWN_PID", "gear_down_d", 0.0));
        		gearTilterPID->SetOutputRange(-0.5, 0.5);
        		gearTilterPID->SetSetpoint(GEAR_POT_DOWN_POSITION);
        		*/
        		wasDown = true;
        		wasUp = false;
        		gearTilterPID->Disable();
        		if(robot->gearPot->Get() <= 0.294) {
        			robot->SetGearTilterSpeed(0.1);
        		}
        	}
        	else {
        		wasDown = true;
        		wasUp = false;
        		gearTilterPID->Reset();
        		gearTilterPID->Disable();
        	}

        	SmartDashboard::PutBoolean("GEAR_pid_enabled", gearTilterPID->IsEnabled());
        	SmartDashboard::PutBoolean("GEAR_pid_p", robot->pini->getf("GEAR_PID", "gear_p", 0.0));

            nextState = kTeleop;
            break;
    }  // end of switch

    m_stateVal = nextState;
}
GearController::~GearController() {
    // TODO Auto-generated destructor stub
}

