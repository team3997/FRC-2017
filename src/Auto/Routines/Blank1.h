/*
 * Blank1.h
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ROUTINES_BLANK1_H_
#define SRC_AUTO_ROUTINES_BLANK1_H_
#include "../AutoRoutine.h"
#include "../../LightsController.h"
class Blank1 : public AutoRoutine {
 public:
    Blank1(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights);
    void Prestart();
    virtual ~Blank1();
 protected:
    void Routine();
 private:
    RobotModel* robot;
    DriveController* driveTrain;
    GearController* gearController;
    LightsController* lights;
};

#endif /* SRC_AUTO_ROUTINES_BLANK1_H_ */
