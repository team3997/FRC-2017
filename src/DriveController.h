#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "DashboardLogger.h"

class PivotCommand;

class DriveController {
public:
	DriveController(RobotModel *myRobot, RemoteControl *myHumanControl);
	virtual ~DriveController();

	void Stop();
	void Update(double currTimeSec, double deltaTimeSec);
	void Reset();
	void ArcadeDrive(double myX, double myY, bool teleOp);
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
