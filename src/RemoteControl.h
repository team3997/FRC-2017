/*
 * RemoteControl.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_REMOTECONTROL_H_
#define SRC_REMOTECONTROL_H_

class RemoteControl {
public:
  enum Joysticks {
    kDriverJoy, kOperatorJoy
  };
  enum Axes {
    kLX, kLY, kRX, kRY
  };

  virtual bool GetReverseDriveDesired() = 0;
  virtual bool GetArcadeDriveDesired() = 0;

  virtual void ReadControls() = 0;

  //Drive joystick accessors
  virtual double GetJoystickValue(Joysticks j, Axes a) = 0;

  virtual ~RemoteControl() {
    }
};

#endif /* SRC_REMOTECONTROL_H_ */
