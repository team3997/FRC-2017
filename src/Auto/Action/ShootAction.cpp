/*
 * ShootAction.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#include "ShootAction.h"
#include "Timer.h"

ShootAction::ShootAction(RobotModel* robot, double seconds, double speed) {
	goal_time = seconds;
	this->kSpeed = speed;
	this->robot = robot;
}
bool ShootAction::IsFinished() {
	return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void ShootAction::Update() {
	robot->SetShooterMotorsSpeed(kSpeed);
}

void ShootAction::Done() {
	robot->SetShooterMotorsSpeed(0.0);
}

void ShootAction::Start() {
	start_time = Timer::GetFPGATimestamp();
}
ShootAction::~ShootAction() {
	// TODO Auto-generated destructor stub
}

