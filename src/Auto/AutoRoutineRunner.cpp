/*
 * AutoRoutineSetter.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#include <Auto/AutoRoutineRunner.h>

static Timer* autoTimer = new Timer();

void AutoRoutineRunner::SetAutoRoutine(AutoRoutine* new_auto_routine) {

  m_auto_routine = new_auto_routine;

}

void AutoRoutineRunner::Start() {
  autoTimer->Start();

  if (m_auto_routine != nullptr) {

    m_auto_routine->Run();
  }
}

void AutoRoutineRunner::Stop() {
  SmartDashboard::PutBoolean("M-auto_routine is", m_auto_routine != nullptr);

  if (m_auto_routine != nullptr) {
    m_auto_routine->Stop();

  }
  autoTimer->Stop();
  autoTimer->Reset();
}

Timer* AutoRoutineRunner::GetTimer() {
  return autoTimer;
}

AutoRoutineRunner::~AutoRoutineRunner() {
  // TODO Auto-generated destructor stub
}

