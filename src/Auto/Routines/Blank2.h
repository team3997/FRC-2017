/*
 * Blank2.h
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_BLANK2_H_
#define SRC_AUTO_ROUTINES_BLANK2_H_
#include "../AutoRoutine.h"
#include "../../LightsController.h"

class Blank2 : public AutoRoutine {
 public:
    Blank2(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights);
    void Prestart();
    virtual ~Blank2();
 protected:
    void Routine();
 private:
    RobotModel* robot;
    DriveController* driveTrain;
    GearController* gearController;
    LightsController* lights;
};

#endif /* SRC_AUTO_ROUTINES_Blank2_H_ */
