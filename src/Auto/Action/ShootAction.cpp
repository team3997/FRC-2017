/*
 * ShootAction.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: peter
 */

#include "ShootAction.h"
#include "Timer.h"

ShootAction::ShootAction(RobotModel* kShooter, double seconds, double speed) {
  goal_time = seconds;
  this->kSpeed = speed;
  this->kShooter = kShooter;
}
bool ShootAction::IsFinished() {
  return (Timer::GetFPGATimestamp() >= start_time + goal_time);
}

void ShootAction::Update() {
  kShooter->SetShooterMotorsSpeed(kSpeed);
}

void ShootAction::Done() {
  kShooter->SetShooterMotorsSpeed(0.0);
}

void ShootAction::Start() {
  start_time = Timer::GetFPGATimestamp();
}
ShootAction::~ShootAction() {
  // TODO Auto-generated destructor stub
}

