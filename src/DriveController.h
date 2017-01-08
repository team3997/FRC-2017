/*
 * DriveController.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_DRIVECONTROLLER_H_
#define SRC_DRIVECONTROLLER_H_

#include "RobotModel.h"
#include "RemoteControl.h"

class DriveController {
public:
  DriveController(RobotModel*, RemoteControl*);

  void Update(double currTimeSec, double deltaTimeSec);
  void RefreshIni();
  void Reset();
  void QuickTurn(double myRight);
  void ArcadeDrive(double myX, double myY);
  void TankDrive(double myLeft, double myRight);

  virtual ~DriveController();

  enum DriveState {
    kInitialize, kTeleopDrive
  };

private:
  RobotModel *robot;
  RemoteControl *humanControl;

  RobotDrive *driveTrain;

  uint32_t m_stateVal;
  uint32_t nextState;
};

#endif /* SRC_DRIVECONTROLLER_H_ */
