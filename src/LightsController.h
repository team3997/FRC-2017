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

	enum ShooterState {
		kInitialize, kTeleop
	};
private:
	RemoteControl *humanControl;
	uint32_t m_stateVal;
	uint32_t nextState;
	DigitalOutput *pin1;
	DigitalOutput *pin2;
	bool HIGH = true;
	bool LOW = false;
};

#endif /* SRC_LIGHTSCONTROLLER_H_ */
