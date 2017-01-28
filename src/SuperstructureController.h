#ifndef SUPERSTRUCTURECONTROLLER_H_
#define SUPERSTRUCTURECONTROLLER_H_

#include "RobotModel.h"
#include "RemoteControl.h"

class SuperstructureController {
public:
	SuperstructureController(RobotModel* myRobot, RemoteControl* myHumanControl);
	~SuperstructureController() {};
	void Reset();
	void Update(double currTimeSec, double deltaTimeSec);

	enum SuperstructureState {
		kInit, kIdle
	};

private:
	RobotModel* robot;
	RemoteControl* humanControl;

	uint32_t m_stateVal;
	uint32_t nextState;
 
  //motor speeds
	double shooterRunSpeed;
};

#endif
