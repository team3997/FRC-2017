/*
 * DriveForwardRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_
#define SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_

#include "../AutoRoutine.h"

class DriveForwardRoutine: public AutoRoutine {
public:
  DriveForwardRoutine(DriveController* kDrive);
  void Prestart();

protected:
  void Routine();

private:
  DriveController* kDrive;
};

#endif /* SRC_AUTO_ROUTINES_DRIVEFORWARDROUTINE_H_ */
