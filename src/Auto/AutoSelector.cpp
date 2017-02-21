/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include <Auto/AutoSelector.h>

AutoSelector::AutoSelector(RobotModel* kShooter, DriveController* kDrive) {
  autoRoutines = new vector<AutoRoutine*>();
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine(kDrive));
  RegisterAutonomous(new JustShootRoutine(kShooter));
  autoChooser = new AutoWidget();
}

void AutoSelector::ListOptions() {
  cout << "Made it to list options." << endl;

  autoChooser->AddDefault("Do nothing (Default)", 0);
  autoChooser->AddObject("Drive", 1);
  autoChooser->AddObject("Shoot", 2);
  SmartDashboard::PutData("Autonomous: ", autoChooser);

}

AutoRoutine* AutoSelector::Pick() {
  SmartDashboard::PutNumber("AutoChooser Value", autoChooser->GetSelected());
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

AutoSelector::~AutoSelector() {
  // TODO Auto-generated destructor stub
}

