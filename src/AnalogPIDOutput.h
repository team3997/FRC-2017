/*
 * AnalogPIDOutput.h
 *
 *  Created on: Mar 25, 2017
 *      Author: kidco
 */

#ifndef SRC_ANALOGPIDOUTPUT_H_
#define SRC_ANALOGPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class AnalogPIDOutput : public PIDOutput {
 public:
    AnalogPIDOutput(RobotModel* robot);
    void PIDWrite(double output);

 private:
    RobotModel* robot;
};

#endif /* SRC_ANALOGPIDOUTPUT_H_ */
