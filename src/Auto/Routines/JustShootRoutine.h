/*
 * JustShootRoutine.h
 *
 *  Created on: Feb 6, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ROUTINES_JUSTSHOOTROUTINE_H_
#define SRC_AUTO_ROUTINES_JUSTSHOOTROUTINE_H_

#include "../AutoRoutine.h"
#include "../../RobotModel.h"

class JustShootRoutine: public AutoRoutine {
public:
	JustShootRoutine(RobotModel* shooter);
	void Prestart();

protected:
	void Routine();

private:
	RobotModel* kShooter;
};

#endif /* SRC_AUTO_ROUTINES_JUSTSHOOTROUTINE_H_ */
