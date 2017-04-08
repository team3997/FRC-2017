/*
 * VisionSetpointXAction.h
 *
 *  Created on: Mar 10, 2017
 *      Author: michael
 */

#ifndef SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_
#define SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_
#include "LightsController.h"
#include "Timer.h"
#include "Action.h"
#include "../../DriveController.h"
#include "../../VisionController.h"

class VisionSetpointXAction: public Action {
public:
	VisionSetpointXAction(VisionController *vision, DriveController *drive, RobotModel *robot, int setpoint, double maxSpeed, double timeout, bool waitForTimeout, LightsController* lights);

	bool IsFinished();
	void Update();
	void Done();
	void Start();

	virtual ~VisionSetpointXAction();

private:

	double P, I, D;
	bool waitForTimeout;
	int setpoint;
	double maxSpeed, timeout;
	double leftEncoderStartDistance, rightEncoderStartDistance;
	VisionController *vision;
	DriveController *driveController;
	RobotModel *robot;
	LightsController* lights;
};

#endif /* SRC_AUTO_ACTION_VISIONSETPOINTXACTION_H_ */
