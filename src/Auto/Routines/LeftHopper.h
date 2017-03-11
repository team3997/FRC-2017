/*
 * LeftHopper.h
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_LEFTHOPPER_H_
#define SRC_AUTO_ROUTINES_LEFTHOPPER_H_

#include "../AutoRoutine.h"
class LeftHopper : public AutoRoutine {
 public:
    LeftHopper(RobotModel *robot, DriveController* driveTrain);
    void Prestart();

   private:
    DriveController *driveTrain;
    RobotModel *robot;
   protected:
    void Routine();
};


#endif /* SRC_AUTO_ROUTINES_LEFTHOPPER_H_ */
