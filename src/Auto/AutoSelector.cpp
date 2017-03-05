/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutoSelector.h"

AutoSelector::AutoSelector(RobotModel* kShooter, DriveController* kDrive) {
  autoRoutines = new vector<AutoRoutine*>();
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine(kDrive));
  RegisterAutonomous(new JustShootRoutine(kShooter));
  RegisterAutonomous(new CenterGear(kDrive));
  autoChooser = new AutoWidget();
}

void AutoSelector::ListOptions() {
  autoChooser->AddDefault("Do nothing (Default)", 0);
  autoChooser->AddObject("Drive (1s)", 1);
  autoChooser->AddObject("Shoot", 2);
  autoChooser->AddObject("CenterField Gear", 3);
  SmartDashboard::PutData("Autonomous: ", autoChooser);
}

AutoRoutine* AutoSelector::Pick() {
  SetAutoRoutineByIndex(autoChooser->GetSelected());
  return GetAutoRoutine();
}

void AutoSelector::RegisterAutonomous(AutoRoutine* autonomous) {
  autoRoutines->push_back(autonomous);
}

AutoRoutine* AutoSelector::GetAutoRoutine() {
  return autoRoutines->at(selectedIndex);
}

void AutoSelector::SetAutoRoutineByIndex(int input) {
  if (input < 0 || input >= autoRoutines->size()) {
    input = 0;
  }
  selectedIndex = input;
}

AutoRoutine* AutoSelector::GetDefaultRoutine() {
	return autoRoutines->at(0);
}

AutoSelector::~AutoSelector() {
}

