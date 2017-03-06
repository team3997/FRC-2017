/*
 * Auto.h
 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTO_H_
#define SRC_AUTO_AUTO_H_
#include <Auto/AutoRoutineRunner.h>
#include <Auto/AutoSelector.h>
#include "AutoRoutine.h"
#include "../DriveController.h"
#include "../RobotModel.h"

class Auto {
public:
	Auto(DriveController* kDrive, RobotModel* kShooter);bool ReturnBool();
	AutoRoutine* autoRoutine;
	void Reset();
	void ListOptions();
	void Start();
	void Stop();
	AutoSelector* selector;
	AutoRoutineRunner* autoRoutineRunner;
	virtual ~Auto();
private:
	DriveController* kDrive;
	RobotModel* kShooter;
};

#endif /* SRC_AUTO_AUTO_H_ */
