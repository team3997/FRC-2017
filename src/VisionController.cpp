/*
 * VisionController.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: michael
 */

#include "VisionController.h"
#include "WPILib.h"

VisionController::VisionController() {
	is_enabled = false;
}

VisionController::~VisionController() {
}

void VisionController::Reset() {

}

void VisionController::Update() {
	SmartDashboard::PutBoolean("VISION_isProcessing", is_enabled);
	left_contour = SmartDashboard::GetNumber("VISION_leftContour", 0.0);
	right_contour = SmartDashboard::GetNumber("VISION_rightContour", 0.0);
}

void VisionController::Enable() {
	is_enabled = true;
}

void VisionController::Disable() {
	is_enabled = false;
}

bool VisionController::isEnabled() {
	return is_enabled;
}

double VisionController::GetLeftContour() {
	return left_contour;
}

double VisionController::GetRightContour() {
	return right_contour;
}
