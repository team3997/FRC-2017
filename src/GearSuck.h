/*
 * GearSuck.h
 *
 *  Created on: Mar 11, 2017
 *      Author: peter
 */

#ifndef SRC_GEARSUCK_H_
#define SRC_GEARSUCK_H_
#include "RobotModel.h"
#include "ControlBoard.h"
#include "Params.h"
class GearSuck {
 public:
    GearSuck(RobotModel* robot, RemoteControl* humanControl);
    void Reset();
    void Update();

    enum GearState {
        kInitialize,
        kTeleop
    };

 private:
    RobotModel* robot;
    RemoteControl* humanControl;
    uint32_t m_stateVal;
    uint32_t nextState;
};

#endif /* SRC_GEARSUCK_H_ */
