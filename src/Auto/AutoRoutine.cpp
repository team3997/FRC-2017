/*
 * AutoRoutine.cpp
 *Base class for all autonomous routines to implement functions
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#include <Auto/AutoRoutineRunner.h>
#include "AutoRoutine.h"
#include "WPILib.h"
#include <DriverStation.h>

void AutoRoutine::Run() {
	m_active = true;
	Routine();

}

void AutoRoutine::Stop() {
	m_active = false;
}

bool AutoRoutine::IsActive() {
	return m_active;
}

void AutoRoutine::RunAction(Action* action) {
	action->Start();
	while ((IsActive()) && (!action->IsFinished()) && (AutoRoutineRunner::GetTimer()->Get() <= 15) && RobotState::IsAutonomous() && !RobotState::IsDisabled()) {
		action->Update();
	}
	action->Done();
}

//ACTIONS:
void AutoRoutine::DriveInterval(DriveController* kDrive, double seconds, double y, double x) {
	RunAction(new DriveIntervalAction(kDrive, seconds, y, x));
}

void AutoRoutine::Shoot(RobotModel* robot, double seconds, double speed) {
	RunAction(new ShootAction(robot, seconds, speed));
}

void AutoRoutine::DriveDistanceStraight(RobotModel* robot, DriveController* kDrive, double desired_distance, double maxSpeed, double minTime, double timeout, bool wantMinTime) {
  RunAction(new DriveSetPointStraightAction(robot, kDrive, desired_distance, maxSpeed, minTime, timeout, false));
}

void AutoRoutine::DriveDistanceRotate(RobotModel* robot, DriveController* kDrive, double desired_distance, double maxSpeed, double minTime, double timeout, bool wantMinTime) {
  RunAction(new DriveSetPointRotateAction(robot, kDrive, desired_distance, maxSpeed, minTime, timeout, false));
}
void AutoRoutine::WaitTime(double timeout) {
    RunAction(new WaitTimeAction(timeout));
}
