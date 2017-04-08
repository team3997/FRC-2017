/*
 * AutonomousRoutinePicker->cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "AutoSelector.h"

AutoSelector::AutoSelector(VisionController *vision, RobotModel* robot, DriveController* kDrive, GearController* gearController, LightsController* lights) {

  autoRoutines = new vector<AutoRoutine*>();
  RegisterAutonomous(new DoNothingRoutine());
  RegisterAutonomous(new DriveForwardRoutine(robot, kDrive, gearController, lights));
  RegisterAutonomous(new CenterGear(vision, robot, kDrive, gearController, lights));
  RegisterAutonomous(new LeftGear(vision, robot, kDrive, gearController, lights));
  RegisterAutonomous(new RightGear(vision, robot, kDrive, gearController, lights));
  RegisterAutonomous(new PassAutoLine(robot, kDrive, gearController, lights));
  RegisterAutonomous(new BoilerFirstHopper(robot, kDrive, gearController, lights));
  RegisterAutonomous(new Blank1(robot, kDrive, gearController, lights));
  RegisterAutonomous(new Blank2(robot, kDrive, gearController, lights));
  RegisterAutonomous(new Blank3(robot, kDrive, gearController, lights));

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
  autoChooser->AddObject("Blank 1", 7);
  autoChooser->AddObject("Blank 2", 8);
  autoChooser->AddObject("Blank 3", 9);


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

