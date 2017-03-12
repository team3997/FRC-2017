/*
 * WheelsPIDOutput.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: michael
 */

#include "WheelsPIDOutput.h"

WheelsPIDOutput::WheelsPIDOutput(RobotModel *robot, RobotModel::Wheels wheels){
	this->robot = robot;
	this->wheels = wheels;
}

void WheelsPIDOutput::PIDWrite(double output){
	loopOutput = output;
	robot->SetWheelSpeed(wheels, output);
}

double WheelsPIDOutput::GetPIDLoopOutput() {
	return loopOutput;
}
