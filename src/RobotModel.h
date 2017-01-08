/*
 * RobotModel.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_ROBOTMODEL_H_
#define SRC_ROBOTMODEL_H_

#include "WPILib.h"
#include "Ports.h"

class RobotModel {
public:
  enum Wheels {
    kLeftWheels, kRightWheels, kAllWheels
  };

  RobotModel();
  virtual ~RobotModel();

  void SetWheelSpeed(Wheels w, double speed); //sets the speed for a given wheel(s)
  float GetWheelSpeed(Wheels w); //returns the speed of a given wheel

  double GetVoltage(); //returns the voltage
  double GetTotalEnergy(); //returns the total energy of the PDP
  double GetTotalCurrent(); //returns the total current of the PDP
  double GetTotalPower(); //returns the total power of the PDP
  double GetCurrent(int channel); //returns the current of a given channel
  double GetCompressorCurrent(); //returns the current of the compressor
  double GetRIOCurrent(); //returns the current of the roboRIO

  double GetLeftEncoderVal(); //returns the distance of the left encoder
  double GetRightEncoderVal(); //returns the distance of the right encoder
  void ResetDriveEncoders(); //resets both the left and the right encoders

  Talon *leftDriveMotorA, *leftDriveMotorB, *rightDriveMotorA,
      *rightDriveMotorB;
private:
  PowerDistributionPanel* pdp;
  Encoder *leftEncoder, *rightEncoder;

};

#endif /* SRC_ROBOTMODEL_H_ */
