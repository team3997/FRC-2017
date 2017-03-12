/*
 * DriveSetPoint.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_DRIVESETPOINTSTRAIGHTACTION_H_
#define SRC_AUTO_ACTION_DRIVESETPOINTSTRAIGHTACTION_H_

#include "../../RobotModel.h"
#include "../../DriveController.h"
#include "WPILib.h"
#include "Action.h"
class DriveSetPointStraightAction: public Action {
public:
	DriveSetPointStraightAction(RobotModel *robot, DriveController *driveController, double distance, double maxSpeed, double minTime, double timeout, bool wantMinTime);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	RobotModel *robot;
	bool reachedSetpoint, wantMinTime;

	double distance, maxSpeed, timeout, minTime;

	double P, I, D;
	int target_pass;
	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
