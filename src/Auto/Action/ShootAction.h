/*
 * ShootAction.h
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_SHOOTACTION_H_
#define SRC_AUTO_ACTION_SHOOTACTION_H_
#include "Action.h"
#include "Timer.h"
#include "../../RobotModel.h"
class ShootAction: public Action {
public:
	ShootAction(RobotModel* shooter, double seconds, double speed);bool IsFinished();
	void Update();
	void Done();
	void Start();
	virtual ~ShootAction();
protected:

private:
	double kSpeed;
	RobotModel* kShooter;
};

#endif /* SRC_AUTO_ACTION_SHOOTACTION_H_ */
