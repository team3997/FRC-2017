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
	while ((IsActive()) && (!action->IsFinished())
			&& (AutoRoutineRunner::GetTimer()->Get() <= 15)
			&& RobotState::IsAutonomous() && !RobotState::IsDisabled()) {
		action->Update();
	}
	action->Done();
}

void AutoRoutine::DriveInterval(DriveController* kDrive, double seconds,
		double y, double x) {
	RunAction(new DriveIntervalAction(kDrive, seconds, y, x));
}

void AutoRoutine::Shoot(RobotModel* kShooter, double seconds, double speed) {
	RunAction(new ShootAction(kShooter, seconds, speed));
}

