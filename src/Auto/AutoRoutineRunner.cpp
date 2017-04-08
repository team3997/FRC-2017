/*
 * AutoRoutineSetter.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#include "AutoRoutineRunner.h"
#include <Timer.h>
static Timer* autoTimer = new Timer();

void AutoRoutineRunner::SetAutoRoutine(AutoRoutine* new_auto_routine) {
	autoStarted = false;
	m_auto_routine = new_auto_routine;
	routine_thread = nullptr;
}

void AutoRoutineRunner::Start() {
	if (routine_thread == nullptr) {
		routine_thread = new std::thread([&] {
			autoTimer->Start();
			autoStarted = true;
			SmartDashboard::PutString("ThreadSTATE", "startedThread");
			if (m_auto_routine != nullptr) {
				m_auto_routine->Run(); //start new thread which runs this function
			}
		});
	}
}

void AutoRoutineRunner::Stop() {
	//If no routine is running, there is nothing to stop.

	if (!autoStarted) {
		return;
	}
	if (m_auto_routine != nullptr) {
		m_auto_routine->Stop();

	}
	SmartDashboard::PutString("ThreadSTATE", "killedThread");
	routine_thread = nullptr;
	autoTimer->Stop();
}

Timer* AutoRoutineRunner::GetTimer() {
	return autoTimer;
}


AutoRoutineRunner::~AutoRoutineRunner() {
	// TODO Auto-generated destructor stub
}

