/*
 * VisionSetpointXAction.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#include "Auto/Action/VisionSetpointXAction.h"

VisionSetpointXAction::VisionSetpointXAction(VisionController *vision, DriveController *drive, int setpoint, double maxSpeed, double timeout) {
	// TODO Auto-generated constructor stub
	this->timeout = timeout;
}

bool VisionSetpointXAction::IsFinished() {
	return (Timer::GetFPGATimestamp() >= start_time + timeout);
}

void VisionSetpointXAction::Update() {
}

void VisionSetpointXAction::Done() {
}

void VisionSetpointXAction::Start() {
	start_time = Timer::GetFPGATimestamp();
}

VisionSetpointXAction::~VisionSetpointXAction() {
	// TODO Auto-generated destructor stub
}

