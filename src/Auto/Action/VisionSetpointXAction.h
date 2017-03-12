/*
 * VisionSetpointXAction.h
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#ifndef SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_
#define SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_

#include "Timer.h"
#include "Action.h"
#include "../../DriveController.h"
#include "../../VisionController.h"

class VisionSetpointXAction: public Action {
public:
	VisionSetpointXAction(VisionController *vision, DriveController *drive, int setpoint, double maxSpeed, double timeout);

	bool IsFinished();
	void Update();
	void Done();
	void Start();

	virtual ~VisionSetpointXAction();

private:
	int setpoint;
	double maxSpeed, timeout;
	VisionController *vision;
	DriveController *drive;
};

#endif /* SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_ */
