/*
 * AutonomousRoutinePicker.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOSELECTOR_H_
#define SRC_AUTO_AUTOSELECTOR_H_

#include <Auto/AutoSelector.h>
#include "Routines/DoNothingRoutine.h"
#include "Routines/DriveForwardRoutine.h"
#include "Routines/JustShootRoutine.h"
#include "../DriveController.h"
#include "../RobotModel.h"
#include "AutoWidget.h"
using namespace std;
using namespace frc;

class AutoSelector {
public:
  AutoSelector(RobotModel* kShooter, DriveController* kDrive);

  void ListOptions();
  AutoRoutine* Pick();
  void RegisterAutonomous(AutoRoutine* autonomous);
  AutoRoutine* GetAutoRoutine();

  virtual ~AutoSelector();
private:
  AutoWidget *autoChooser;

  vector<AutoRoutine*>* autoRoutines;
  void SetAutoRoutineByIndex(int input);
  int selectedIndex = 0;
};

#endif /* SRC_AUTO_AUTOSELECTOR_H_ */
