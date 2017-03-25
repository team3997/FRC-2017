/*
 * GearController.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: kidco
 */

#include "GearController.h"

GearController::GearController(RobotModel* robot, RemoteControl* humanControl) {
    this->robot = robot;
    this->humanControl = humanControl;
    robot->gearPot->SetPIDSourceType(PIDSourceType::kDisplacement);
    gearOutput = new AnalogPIDOutput(robot);
    gearPID = new PIDController(0.0, 0.0, 0.0, robot->gearPot, gearOutput);
    gearPID->SetOutputRange(-1.0, 1.0);
    gearPID->SetAbsoluteTolerance(0.25);
    gearPID->Disable();

    m_stateVal = kInitialize;
    nextState = kInitialize;

}
void GearController::Update() {
    switch (m_stateVal) {
        case (kInitialize):
            prevBackState = false;
            gearPID->Disable();
            nextState = kTeleopDrive;
            break;
        case (kTeleopDrive):
            currBackState = true;
                if (prevBackState == false && currBackState == true) {
                    gearPID->SetOutputRange(-0.8, 0.8);
                    gearPID->SetPID(0.125, 0.0, 0.0);
                    gearPID->SetSetpoint(0);

                    gearPID->Enable();
            }

            nextState = kTeleopDrive;
            break;
    }  // end of switch

    m_stateVal = nextState;
}
GearController::~GearController() {
    // TODO Auto-generated destructor stub
}

