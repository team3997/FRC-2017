/*
 * AutoRoutine.h
 * Base class for all autonomous actions to implement functions
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINE_H_
#define SRC_AUTO_AUTOROUTINE_H_

#include "WPILib.h"
#include <iostream>
#include "Action/Action.h"
#include "Action/DriveIntervalAction.h"
#include "Action/ShootAction.h"

class AutoRoutine {

public:
	bool m_active = false;bool *teleop;
	virtual void Prestart() = 0;bool IsActive();
	void Run();
	void Stop();
	void RunAction(Action* action);
	void DriveInterval(DriveController* kDrive, double seconds, double y,
			double x);
	void Shoot(RobotModel* kShooter, double seconds, double speed);

protected:
	virtual void Routine(void) = 0;
private:
	DriverStation* driverStation;
};

#endif /* SRC_AUTO_AUTOROUTINE_H_ */
