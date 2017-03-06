/*
 * AutoRoutineSetter.h
 *
 *  Created on: Jan 29, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOROUTINERUNNER_H_
#define SRC_AUTO_AUTOROUTINERUNNER_H_

#include "AutoRoutine.h"

class AutoRoutineRunner {
public:

  //void function NOT constructor
  void SetAutoRoutine(AutoRoutine* new_auto_routine);
  void Start();
  void Stop();
  void Run();
  static Timer* GetTimer();
  virtual ~AutoRoutineRunner();

private:
  AutoRoutine* m_auto_routine;
  bool autoStarted;
};

#endif /* SRC_AUTO_AUTOROUTINERUNNER_H_ */
