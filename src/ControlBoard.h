/*
 * ControlBoard.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_CONTROLBOARD_H_
#define SRC_CONTROLBOARD_H_

#include "WPILib.h"
#include "ButtonReader.h"
#include "RemoteControl.h"

class ControlBoard : public RemoteControl {
public:
  ControlBoard();
  ~ControlBoard() {};

  virtual void ReadControls();

  //Drive joystick accessors
  double GetJoystickValue(Joysticks j, Axes a);

  virtual bool GetReverseDriveDesired();
  virtual bool GetArcadeDriveDesired();

private:

  bool reverseDriveDesired, arcadeDriveDesired;

  double driverLeftJoyX, driverLeftJoyY, driverRightJoyX, driverRightJoyY;
  double operatorLeftJoyX, operatorLeftJoyY, operatorRightJoyX, operatorRightJoyY;

  Joystick *driverJoy, *operatorJoy;

  ButtonReader *driveDirectionButton;

  void ReadAllButtons();
};

#endif /* SRC_CONTROLBOARD_H_ */
