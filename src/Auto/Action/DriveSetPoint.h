/*
 * DriveSetPoint.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_DRIVESETPOINT_H_
#define SRC_AUTO_ACTION_DRIVESETPOINT_H_

#include "../../RobotModel.h"
#include "../../DriveController.h"
#include "WPILib.h"
#include "Action.h"
class DriveSetPoint : public Action {
 public:
  DriveSetPoint(DriveController *driveTrain);
  bool IsFinished();
  void Update();
  void Done();
  void Start();

 private:
  DriveController* driveTrain;
};

#endif /* SRC_AUTO_ACTION_DRIVESETPOINT_H_ */
