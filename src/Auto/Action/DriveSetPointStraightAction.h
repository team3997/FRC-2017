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
	DriveSetPointStraightAction(RobotModel *robot, DriveController *driveTrain, double distance, double maxSpeed, double timeout);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveTrain;
	RobotModel *robot;
	bool reachedSetpoint;

	double distance, maxSpeed, timeout;

	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
