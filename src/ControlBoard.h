/*
 * ControlBoard.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_CONTROLBOARD_H_
#define SRC_CONTROLBOARD_H_

#include "WPILib.h"
#include "ButtonReader.h"
#include "TriggerReader.h"
#include "RemoteControl.h"

class ControlBoard: public RemoteControl {
public:
	ControlBoard();
	~ControlBoard() {
	};

	virtual void ReadControls();

	//Drive joystick accessors
	double GetJoystickValue(Joysticks j, Axes a);

	bool GetReverseDriveDesired();
	bool GetArcadeDriveDesired();
	bool GetClimberDesired();
	bool GetClimberReverseDesired();
	bool GetClimberLockDesired();
	bool GetSlowDriveTier1Desired();
	bool GetSlowDriveTier2Desired();
	bool GetDriveBackDesired();
	bool GetDriveBackOtherDesired();
	bool GetGearTitlerDownDesired();
	bool GetGearTitlerOuttakeDesired();
	bool GetGearTitlerIntakeDesired();
	bool GetLightsActiveDesired();
	bool GetShoutRoutineDesired();
private:

	//booleans for desired states of robot

	bool climberReverseDesired, reverseDriveDesired, arcadeDriveDesired, climberDesired,
		climberLockDesired, slowDriveTier1Desired, slowDriveTier2Desired, lightsActiveDesired,
		driveBackDesired, driveBackOtherDesired, gearTilterDownDesired, gearTilterOuttakeDesired, gearTilterIntakeDesired, shoutRoutineDesired;

	double driverLeftJoyX, driverLeftJoyY, driverRightJoyX, driverRightJoyY;
	double operatorLeftJoyX, operatorLeftJoyY, operatorRightJoyX, operatorRightJoyY;

	Joystick *driverJoy, *operatorJoy;


	ButtonReader *climberReverseButton, *driveDirectionButton, *climberRunButton,
		*climberLockButton, *driveBackButton, *driveBackOtherButton,
		*gearTilterOuttakeButton, *gearTilterIntakeButton, *shoutRoutineButton;;

	TriggerReader *slowDriveTier1Button, *slowDriveTier2Button, *gearTilterDownButton, *lightsActiveButton;

	void ReadAllButtons();
};

#endif /* SRC_CONTROLBOARD_H_ */
