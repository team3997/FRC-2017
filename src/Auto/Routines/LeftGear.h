/*
 * LeftGear.h
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_LEFTGEAR_H_
#define SRC_AUTO_ROUTINES_LEFTGEAR_H_
#include "../AutoRoutine.h"
class LeftGear : public AutoRoutine {
 public:
    LeftGear(RobotModel *robot, DriveController* driveTrain);
    void Prestart();

 private:
    DriveController *driveTrain;
    RobotModel *robot;
 protected:
    void Routine();
};

#endif /* SRC_AUTO_ROUTINES_LEFTGEAR_H_ */
