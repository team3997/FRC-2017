#include "JustShootRoutine.h"

JustShootRoutine::JustShootRoutine(RobotModel* robot) {
	this->robot = robot;
}

void JustShootRoutine::Prestart() {
	// TODO Auto-generated constructor stub

}

void JustShootRoutine::Routine() {
	ShootAction(robot, 5.0, .8);
}
