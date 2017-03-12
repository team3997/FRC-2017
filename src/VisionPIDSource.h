/*
 * VisionPIDSource.h
 *
 *  Created on: Mar 8, 2017
 *      Author: michael
 */

#ifndef SRC_VISIONPIDSOURCE_H_
#define SRC_VISIONPIDSOURCE_H_

#include "WPILib.h"
#include "VisionController.h"

class VisionPIDSource : public PIDSource {
public:
	VisionPIDSource(VisionController *vision);
	double PIDGet() override;
private:
	VisionController *vision;
};

#endif /* SRC_VISIONPIDSOURCE_H_ */
