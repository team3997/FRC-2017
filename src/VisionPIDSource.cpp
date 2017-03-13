/*
 * VisionPIDSource.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: michael
 */

#include "VisionPIDSource.h"

VisionPIDSource::VisionPIDSource(VisionController *vision) {
	this->vision = vision;
}

double VisionPIDSource::PIDGet() {
	return vision->GetRightContour();
}
