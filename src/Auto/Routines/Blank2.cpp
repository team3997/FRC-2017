/*
 * Blank2.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank2.h"

Blank2::Blank2(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->gearController = gearController;
    this->lights = lights;
}

void Blank2::Prestart() {

}
void Blank2::Routine() {

}


Blank2::~Blank2() {
    // TODO Auto-generated destructor stub
}

