#ifndef SHOOTERCONTROLLER_H_ 
#define SHOOTERCONTROLLER_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ShooterMotorsPIDOutput.h"

class ShooterController {
public:
	ShooterController(RobotModel*, RemoteControl*);
	virtual ~ShooterController();

	void Reset();
	void Update(double currTimeSec, double deltaTimeSec);

	Timer *feederPulseTimer;
	enum ShooterState {
		kInitialize, kTeleop
	};
private:
	RobotModel *robot;
	RemoteControl *humanControl;

	bool feederPulseBool;
	double currentPulse, prevPulse;

	PIDController *shooterPID;

	ShooterMotorsPIDOutput *pidOutput;

	double shooterP, shooterI, shooterD;

	uint32_t m_stateVal;
	uint32_t nextState;
};

#endif
