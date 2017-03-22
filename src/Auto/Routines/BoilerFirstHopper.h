/*
 * BoilerFirstHopper.h
 *
 *  Created on: Mar 18, 2017
 *      Author: mikec
 */

#ifndef SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_
#define SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_

#include "../AutoRoutine.h"

class BoilerFirstHopper : public AutoRoutine {
public:
 BoilerFirstHopper(RobotModel *robot, DriveController* driveTrain);
 void Prestart();

private:
 DriveController *driveTrain;
 RobotModel *robot;
protected:
 void Routine();
};

#endif /* SRC_AUTO_ROUTINES_BOILERFIRSTHOPPER_H_ */
