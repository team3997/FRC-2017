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
    LeftGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain);
    void Prestart();

 private:
    DriveController *driveTrain;
    RobotModel *robot;
    VisionController *vision;
 protected:
    void Routine();
};

#endif /* SRC_AUTO_ROUTINES_LEFTGEAR_H_ */
