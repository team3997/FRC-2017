/*
 * AutoRoutine.h
 * Base class for all autonomous actions to implement functions
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINE_H_
#define SRC_AUTO_AUTOROUTINE_H_

#include <Auto/Action/DriveSetPointStraightAction.h>
#include "WPILib.h"
#include <iostream>
#include "Action/Action.h"
#include "Action/DriveIntervalAction.h"
#include "Action/ShootAction.h"

class AutoRoutine {

public:

  bool m_active = false;
  bool *teleop;
  virtual void Prestart() = 0;
  bool IsActive();
  void Run();
  void Stop();
  void RunAction(Action* action);

  //ACTIONS:
  void DriveInterval(DriveController* kDrive, double seconds, double y, double x);
  void Shoot(RobotModel *robot, double seconds, double speed);
  void DriveDistanceStraight(RobotModel *robot, DriveController* kDrive, double desired_distance, double maxSpeed, double timeout);

protected:
	virtual void Routine(void) = 0;
private:
	DriverStation* driverStation;
};

#endif /* SRC_AUTO_AUTOROUTINE_H_ */
