/*
 * GearController.h
 *
 *  Created on: Mar 23, 2017
 *      Author: kidco
 */

#ifndef SRC_GEARCONTROLLER_H_
#define SRC_GEARCONTROLLER_H_
#include "RobotModel.h"
#include "ControlBoard.h"
#include "WPILib.h"
class GearController {
 public:
    GearController(RobotModel* robot, RemoteControl* humanControl);

    void Update();

    virtual ~GearController();

 private:
    RobotModel* robot;
    RemoteControl* humanControl;
};

#endif /* SRC_GEARCONTROLLER_H_ */
