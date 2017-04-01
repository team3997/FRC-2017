/*
 * Blank1.cpp
 *
 *  Created on: Mar 31, 2017
 *      Author: kidco
 */

#include "Blank1.h"

Blank1::Blank1(RobotModel* robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->gearController = gearController;
    this->lights = lights;
}

void Blank1::Prestart() {

}
void Blank1::Routine() {

}


Blank1::~Blank1() {
    // TODO Auto-generated destructor stub
}

