/*
 * Action.h
 *
 *  Created on: Jan 14, 2017
 *      Author: peter
 */

#ifndef SRC_AUTO_ACTION_ACTION_H_
#define SRC_AUTO_ACTION_ACTION_H_

class Action {
//Base class for all autonomous actions to implement functions
public:

  virtual bool IsFinished() = 0;
  virtual void Update() = 0;
  virtual void Done() = 0;
  virtual void Start() = 0;

protected:

  double goal_time;
  double start_time;
  double x_drive;
  double y_drive;
};

#endif /* SRC_AUTO_ACTION_ACTION_H_ */
