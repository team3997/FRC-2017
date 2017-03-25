/*
 * AnalogPIDOutput.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: kidco
 */

#include <AnalogPIDOutput.h>

AnalogPIDOutput::AnalogPIDOutput(RobotModel* robot) {
    this->robot = robot;
}
void AnalogPIDOutput::PIDWrite(double output) {
    robot->SetGearTilterSpeed(output);
}
