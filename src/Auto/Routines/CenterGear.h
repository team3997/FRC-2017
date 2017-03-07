/*
 * CenterGear.h
 *
 *  Created on: Mar 4, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_CENTERGEAR_H_
#define SRC_AUTO_ROUTINES_CENTERGEAR_H_

#include "../AutoRoutine.h"

class CenterGear : public AutoRoutine {
 public:
  CenterGear(RobotModel *robot, DriveController* driveTrain);
  virtual ~CenterGear();
  void Prestart();
 private:
  DriveController *driveTrain;
  RobotModel *robot;
 protected:
  void Routine();
};


#endif /* SRC_AUTO_ROUTINES_CENTERGEAR_H_ */
