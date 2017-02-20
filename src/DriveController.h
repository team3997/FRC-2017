#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

#include "RobotModel.h"
#include "RemoteControl.h"

class PivotCommand;

class DriveController {
public:
  DriveController(RobotModel*, RemoteControl*);
  virtual ~DriveController();

  void Update(double currTimeSec, double deltaTimeSec);
  void Reset();
  void ArcadeDrive(double myX, double myY);
  void TankDrive(double myLeft, double myRight);

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

#endif
