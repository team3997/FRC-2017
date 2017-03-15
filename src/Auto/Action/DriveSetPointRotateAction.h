/*
 * DriveSetPoint.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_DRIVESETPOINTROTATEACTION_H_
#define SRC_AUTO_ACTION_DRIVESETPOINTROTATEACTION_H_

#include "../../RobotModel.h"
#include "../../DriveController.h"
#include "WPILib.h"
#include "Action.h"
class DriveSetPointRotateAction: public Action {
public:
	DriveSetPointRotateAction(RobotModel *robot, DriveController *driveController, double distance, double maxSpeed, double timeout, bool waitForTimeout);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	RobotModel *robot;
	bool reachedSetpoint, waitForTimeout;

	double distance, maxSpeed, timeout;

	double P, I, D;

	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
