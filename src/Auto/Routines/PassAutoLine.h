/*
 * PassAutoLine.h
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_PASSAUTOLINE_H_
#define SRC_AUTO_ROUTINES_PASSAUTOLINE_H_

#include "../AutoRoutine.h"
class PassAutoLine : public AutoRoutine {
 public:
    PassAutoLine(RobotModel *robot, DriveController* driveTrain);
    void Prestart();

   private:
    DriveController *driveTrain;
    RobotModel *robot;
   protected:
    void Routine();
};



#endif /* SRC_AUTO_ROUTINES_PASSAUTOLINE_H_ */
