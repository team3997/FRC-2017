/*
 * ShootHighGoal.h
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_SHOOTHIGHGOAL_H_
#define SRC_AUTO_ROUTINES_SHOOTHIGHGOAL_H_
#include "../AutoRoutine.h"
class ShootHighGoal : public AutoRoutine {
 public:
    ShootHighGoal(RobotModel *robot, DriveController* driveTrain);
    void Prestart();

 private:
    DriveController *driveTrain;
    RobotModel *robot;
 protected:
    void Routine();
};

#endif /* SRC_AUTO_ROUTINES_ShootHighGoal_H_ */
