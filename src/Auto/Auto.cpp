/*
 * Auto.cpp

 *
 *  Created on: Jan 28, 2017
 *      Author: peter
 */
#include "Timer.h"
#include "Auto.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Auto::Auto(VisionController *vision, DriveController* kDrive, RobotModel* robot, LightsController* lights) {
	this->kDrive = kDrive;
	this->robot = robot;
	this->lights = lights;
	selector = new AutoSelector(vision, robot, kDrive, lights);
	autoRoutineRunner = new AutoRoutineRunner();
	autoRoutine = selector->GetDefaultRoutine();
}

void Auto::ListOptions() {
	selector->ListOptions();
}

void Auto::Start() {
	//Get the dashboard selection and set the auto routine
	autoRoutine = selector->Pick();
	autoRoutineRunner->SetAutoRoutine(autoRoutine);

	//run the prestart for the function
	autoRoutine->Prestart();
	//Run the set autoroutine
	autoRoutineRunner->Start();
	//stop(); //!! Check if this is necessar!(*teleop)y!!
}

void Auto::Stop() {
	autoRoutineRunner->Stop();
	autoRoutine->m_active = false;

}
Auto::~Auto() {
	// TODO Auto-generated destructor stub
}

