/*
 * RobotModel.h
 *
 *  Created on: Jan 7, 2017
 *      Author: mikechacko
 */

#ifndef SRC_ROBOTMODEL_H_
#define SRC_ROBOTMODEL_H_

#include "WPILib.h"
#include "ini.h"

class RobotModel {
public:
	enum Wheels {
		LeftWheels, RightWheels, AllWheels
	};

	void SetWheelSpeed(Wheels w, double speed); //sets the speed for a given wheel(s)
	float GetWheelSpeed(Wheels w); //returns the speed of a given wheel

	RobotModel();
	virtual ~RobotModel();

	void Reset(); //resets variables and objects

	void UpdateCurrent();  //initializes variables pertaining to current

	double GetVoltage(); //returns the voltage
	double GetTotalEnergy(); //returns the total energy of the PDP
	double GetTotalCurrent(); //returns the total current of the PDP
	double GetTotalPower(); //returns the total power of the PDP
	double GetCurrent(int channel); //returns the current of a given channel

	void ResetTimer(); //resets the timer
	double GetTime(); //returns the time

	//Superstructure systems
    void SetGearSuckerMotorSpeed(double speed); //sets the speed of the climber motor
    double GetGearSuckerMotorSpeed(); //gets the speed of the climber motor
	void SetClimberMotorSpeed(double speed); //sets the speed of the climber motor
	double GetClimberMotorSpeed(); //gets the speed of the climber motor
	void SetClimberLockServoSpeed(double speed);
	void RefreshIni();
	void ResetEncoders();

	//Speed controllers
	Spark *leftDriveMotorA, *leftDriveMotorB, *rightDriveMotorA,
			*rightDriveMotorB, *gearSuckerMotor;

	Talon *climberMotor;
	Ini *pini;

	Encoder *shooterEncoder;
	Encoder *leftDriveEncoder, *rightDriveEncoder;

	Servo *climberLockerServo;

	Timer *timer;
private:
	PowerDistributionPanel* pdp;

	double leftDriveACurrent, leftDriveBCurrent, rightDriveACurrent,
			rightDriveBCurrent, climberMotorCurrent, gearSuckerCurrent;
};

#endif /* SRC_ROBOTMODEL_H_ */
