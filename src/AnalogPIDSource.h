/*
 * AnalogPIDSource.h
 *
 *  Created on: Mar 25, 2017
 *      Author: kidco
 */

#ifndef SRC_ANALOGPIDSOURCE_H_
#define SRC_ANALOGPIDSOURCE_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class AnalogPIDSource : public PIDSource {
    AnalogPIDSource(Potentiometer* analogInput);
    double PIDGet() override;

private:
    Potentiometer* analogInput;

};

#endif /* SRC_ANALOGPIDSOURCE_H_ */
