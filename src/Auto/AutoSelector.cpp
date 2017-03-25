/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutoSelector.h"

AutoSelector::AutoSelector(VisionController *vision, RobotModel* robot, DriveController* kDrive) {

  autoRoutines = new vector<AutoRoutine*>();
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine(robot, kDrive));
  RegisterAutonomous(new CenterGear(vision, robot, kDrive));
  RegisterAutonomous(new LeftGear(vision, robot, kDrive));
  RegisterAutonomous(new RightGear(vision, robot, kDrive));
  RegisterAutonomous(new PassAutoLine(robot, kDrive));
  RegisterAutonomous(new LeftHopper(robot, kDrive));
  RegisterAutonomous(new BoilerFirstHopper(robot, kDrive));

  autoChooser = new AutoWidget();
}

void AutoSelector::ListOptions() {
  autoChooser->AddDefault("Do nothing (Default)", 0);
  autoChooser->AddObject("Drive (1s)", 1);
  autoChooser->AddObject("CenterField Gear", 2);
  autoChooser->AddObject("LeftField Gear", 3);
  autoChooser->AddObject("RightField Gear", 4);
  autoChooser->AddObject("Pass AutoLine", 5);
  autoChooser->AddObject("Left Hopper", 6);
  autoChooser->AddObject("BoilerStraightHoppers", 7);

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

