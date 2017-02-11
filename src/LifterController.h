/*
 * LifterController.h
 *
 *  Created on: Feb 10, 2017
 *      Author: peter
 */

#ifndef SRC_LIFTERCONTROLLER_H_
#define SRC_LIFTERCONTROLLER_H_

#include "WPILib.h"
#include "Ports.h"
#include "RobotModel.h"
#include "ControlBoard.h"

class LifterController {
public:
  LifterController(RobotModel* myRobot, RemoteControl* myHumanControl);
  void Reset();
  void Update();
  void StartLifter();
  
  enum LifterState {
    kInitialize, kTeleop	
  };

  virtual ~LifterController();
private:
  RobotModel* robot;
  RemoteControl* humanControl;
  uint32_t m_stateVal;
  uint32_t nextState;

};

#endif /* SRC_LIFTERCONTROLLER_H_ */
