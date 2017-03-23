/*
 * LightsController.h
 *
 *  Created on: Mar 15, 2017
 *      Author: michael
 */

#ifndef SRC_LIGHTSCONTROLLER_H_
#define SRC_LIGHTSCONTROLLER_H_

#include "WPILib.h"
#include "RemoteControl.h"
#include "Ports.h"

class LightsController {
public:
	LightsController(RemoteControl *myHumanControl);
	virtual ~LightsController();

	void Reset();
	void Update(bool enabled);

	void SetDisabledRoutine();
	void SetEnabledRoutine();
	void SetShoutRoutine();
	void PIDFail();
	void PIDWorking();
	void PIDLockedOn();
	void GearIntake();
	void Climbing();

	enum LightsState {
		kInitialize, kTeleop
	};


private:
	DigitalOutput *pin1;
	DigitalOutput *pin2;
	DigitalOutput *pin3;
	DigitalOutput *pin4;

	RemoteControl *humanControl;
	uint32_t m_stateVal;
	uint32_t nextState;

	bool HIGH = true;
	bool LOW = false;
};

#endif /* SRC_LIGHTSCONTROLLER_H_ */
