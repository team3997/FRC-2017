/*
 * AutonomousRoutinePicker.h
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_AUTOSELECTOR_H_
#define SRC_AUTO_AUTOSELECTOR_H_


#include "Routines/DoNothingRoutine.h"
#include "Routines/DriveForwardRoutine.h"
#include "Routines/JustShootRoutine.h"
#include "Routines/CenterGear.h"
#include "Routines/LeftGear.h"
#include "Routines/RightGear.h"
#include "Routines/ShootHighGoal.h"
#include "../DriveController.h"
#include "../RobotModel.h"
#include "AutoWidget.h"
using namespace std;
using namespace frc;

class AutoSelector {
public:
	AutoSelector(RobotModel* robot, DriveController* kDrive);

	void ListOptions();
	AutoRoutine* Pick();
	void RegisterAutonomous(AutoRoutine* autonomous);
	AutoRoutine* GetAutoRoutine();
	AutoRoutine* GetDefaultRoutine();

	virtual ~AutoSelector();
private:
	AutoWidget *autoChooser;

	vector<AutoRoutine*>* autoRoutines;
	void SetAutoRoutineByIndex(int input);
	int selectedIndex = 0;
};

#endif /* SRC_AUTO_AUTOSELECTOR_H_ */
