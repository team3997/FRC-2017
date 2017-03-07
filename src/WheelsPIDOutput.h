/*
 * WheelsPIDOutput.h
 *
 *  Created on: Mar 7, 2017
 *      Author: michael
 */

#ifndef SRC_WHEELSPIDOUTPUT_H_
#define SRC_WHEELSPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class WheelsPIDOutput : public PIDOutput {
public:
	WheelsPIDOutput(RobotModel *robot, RobotModel::Wheels wheels);

	//Override PIDWrite
	void PIDWrite(double output);

	double GetPIDLoopOutput();

	double loopOutput;
private:

	RobotModel *robot;
	RobotModel::Wheels wheels;

};

#endif /* SRC_WHEELSPIDOUTPUT_H_ */
