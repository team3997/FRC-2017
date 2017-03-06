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

}

void AutoRoutineRunner::Start() {
  autoTimer->Start();
  autoStarted = true;
  if (m_auto_routine != nullptr) {

    m_auto_routine->Run();
  }
}

void AutoRoutineRunner::Stop() {
  //If no routine is running, there is nothing to stop.
  if(!autoStarted) {
    return;
  }
  if (m_auto_routine != nullptr) {
    m_auto_routine->Stop();

  }
  autoTimer->Stop();
  autoTimer->Reset();
  autoTimer->Stop();
}

Timer* AutoRoutineRunner::GetTimer() {
  return autoTimer;
}

AutoRoutineRunner::~AutoRoutineRunner() {
  // TODO Auto-generated destructor stub
}

