/*
 * DriveForwardRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_
#define SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_

#include "../AutoRoutine.h"
#include "../../LightsController.h"

class DriveForwardRoutine: public AutoRoutine {
public:
	DriveForwardRoutine(RobotModel *robot, DriveController* kDrive, LightsController* lights);
	void Prestart();

protected:
	void Routine();

private:
	DriveController* kDrive;
	RobotModel *robot;
	LightsController* lights;
};

#endif /* SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_ */
