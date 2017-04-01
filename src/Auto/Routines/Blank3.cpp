/*
 * Blank3.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank3.h"

Blank3::Blank3(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->gearController = gearController;
    this->lights = lights;
}

void Blank3::Prestart() {

}
void Blank3::Routine() {

}


Blank3::~Blank3() {
    // TODO Auto-generated destructor stub
}

