/*
 * LeftGear.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: peter
 */

#include "LeftGear.h"

LeftGear::LeftGear(VisionController *vision, RobotModel *robot, DriveController* driveTrain, GearController* gearController, LightsController* lights) {
    this->robot = robot;
    this->driveTrain = driveTrain;
    this->vision = vision;
    this->lights = lights;

}

void LeftGear::Prestart() {

}

void LeftGear::Routine() {
   DriveDistanceStraight(robot, driveTrain, 93.96, 0.5, 3.3, true, lights);
   DriveDistanceRotate(robot, driveTrain, 73, 0.6, 1.5, true, lights);
  // DriveDistanceStraight(robot, driveTrain, 2, 1.0, 1, false);
   DriveDistanceStraight(robot, driveTrain, 30, 0.4, 5, false, lights);
}
// 15in 129v
