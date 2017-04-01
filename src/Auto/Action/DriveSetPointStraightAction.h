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
#include "../../GearController.h"
#include "../../LightsController.h"
#include "WPILib.h"
#include "Action.h"

class DriveSetPointStraightAction: public Action {
public:
	DriveSetPointStraightAction(RobotModel *robot, DriveController *driveController,
			GearController *gearController, double distance, double maxSpeed, double timeout, bool waitForTimeout,
			LightsController* lights, bool ejectGear);
	bool IsFinished();
	void Update();
	void Done();
	void Start();

private:
	DriveController *driveController;
	RobotModel *robot;
	GearController *gearController;
	LightsController* lights;
	bool reachedSetpoint, waitForTimeout, ejectGear;

	double distance, maxSpeed, timeout;

	double P, I, D;
	int target_pass;
	double leftEncoderStartDistance, rightEncoderStartDistance;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
