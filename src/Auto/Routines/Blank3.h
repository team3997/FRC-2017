/*
 * Blank3.h
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_BLANK3_H_
#define SRC_AUTO_ROUTINES_BLANK3_H_
#include "../AutoRoutine.h"
#include "../../LightsController.h"

class Blank3 : public AutoRoutine {
 public:
    Blank3(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights);
    void Prestart();
    virtual ~Blank3();
 protected:
    void Routine();
 private:
    RobotModel* robot;
    DriveController* driveTrain;
    GearController* gearController;
    LightsController* lights;
};

#endif /* SRC_AUTO_ROUTINES_BLANK3_H_ */
