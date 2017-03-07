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
	void SetShooterMotorsSpeed(double speed); //sets the speed of the shooter motors
	double GetShooterMotorASpeed(); //returns the speed of the shooter motor A
	double GetShooterMotorBSpeed(); //returns the speed of the shooter motor B
	void SetFeederMotorSpeed(double speed); //sets the speed of the feeder motor
	double GetFeederMotorSpeed(); //gets the speed of the feeder motor

	void SetClimberMotorSpeed(double speed); //sets the speed of the climber motor
	double GetClimberMotorSpeed(); //gets the speed of the climber motor
	void RefreshIni();
	void ResetEncoders();

	//Speed controllers
	Spark *leftDriveMotorA, *leftDriveMotorB, *rightDriveMotorA,
			*rightDriveMotorB;
	VictorSP *shooterMotorA, *shooterMotorB;
	Talon *climberMotor, *feederMotor;
	Ini *pini;

	Encoder *shooterEncoder;
	Encoder *leftDriveEncoder, *rightDriveEncoder;

	Timer *timer;
private:
	PowerDistributionPanel* pdp;

	double leftDriveACurrent, leftDriveBCurrent, rightDriveACurrent,
			rightDriveBCurrent, shooterMotorACurrent, shooterMotorBCurrent,
			climberMotorCurrent;
};

#endif /* SRC_ROBOTMODEL_H_ */
