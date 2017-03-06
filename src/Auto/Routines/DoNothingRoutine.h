/*
 * DoNothingRoutine.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_
#define SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_

#include "../AutoRoutine.h"

class DoNothingRoutine: public AutoRoutine {
public:
  void Routine();

protected:
  void Prestart();

};

#endif /* SRC_AUTO_ROUTINES_DONOTHINGROUTINE_H_ */
