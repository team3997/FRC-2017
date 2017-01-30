#ifndef SHOOTERMOTORSPIDOUTPUT_H_
#define SHOOTERMOTORSPIDOUTPUT_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class ShooterMotorsPIDOutput : PIDOutput{
public:
	ShooterMotorsPIDOutput(Spark kOutputMotor1, Spark kOutputMotor2);
	~ShooterMotorsPIDOutput() {};

	void pidWrite(double output);

	double getPIDLoopOutput();
private:
};

#endif
