/*
 * ClimberController.h
 *
 *  Created on: Feb 10, 2017
 *      Author: peter
 */

#ifndef SRC_CLIMBERCONTROLLER_H_
#define SRC_CLIMBERCONTROLLER_H_

#include "WPILib.h"
#include "Ports.h"
#include "RobotModel.h"
#include "ControlBoard.h"

class ClimberController {
public:
  ClimberController(RobotModel* myRobot, RemoteControl* myHumanControl);
  void Reset();
  void Update();
  
  enum ClimberState {
    kInitialize, kTeleop	
  };

  virtual ~ClimberController();
private:
  RobotModel* robot;
  RemoteControl* humanControl;
  uint32_t m_stateVal;
  uint32_t nextState;

};

#endif /* SRC_CLIMBERCONTROLLER_H_ */
