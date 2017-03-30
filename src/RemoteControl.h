/*
 * RemoteControl.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_REMOTECONTROL_H_
#define SRC_REMOTECONTROL_H_

class RemoteControl {
public:
	enum Joysticks {
		kDriverJoy, kOperatorJoy
	};
	enum Axes {
		kLX, kLY, kRX, kRY
	};

	virtual bool GetReverseDriveDesired() = 0;
	virtual bool GetArcadeDriveDesired() = 0;
	virtual bool GetClimberDesired() = 0;
	virtual bool GetClimberReverseDesired() = 0;
	virtual bool GetClimberLockDesired() = 0;
	virtual bool GetSlowDriveTier1Desired() = 0;
	virtual bool GetSlowDriveTier2Desired() = 0;
	virtual bool GetDriveBackDesired() = 0;
	virtual bool GetDriveBackOtherDesired() = 0;
    virtual bool GetLightsActiveDesired() = 0;
    virtual bool GetShoutRoutineDesired() = 0;
	virtual bool GetGearTitlerDownDesired() = 0;
	virtual bool GetGearTitlerOuttakeDesired() = 0;
	virtual bool GetGearTitlerIntakeDesired() = 0;
	virtual void ReadControls() = 0;

	//Drive joystick accessors
	virtual double GetJoystickValue(Joysticks j, Axes a) = 0;

	virtual ~RemoteControl() {
	}
};

#endif /* SRC_REMOTECONTROL_H_ */
