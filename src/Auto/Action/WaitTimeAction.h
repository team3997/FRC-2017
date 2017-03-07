/*
 * WaitTimeAction.h
 *
 *  Created on: Mar 7, 2017
 *      Author: kidco
 */

#ifndef SRC_AUTO_ACTION_WAITTIMEACTION_H_
#define SRC_AUTO_ACTION_WAITTIMEACTION_H_
#include "Action.h"
class WaitTimeAction : public Action {
 public:
    WaitTimeAction(double timeout);
    bool IsFinished();
    void Update();
    void Done();
    void Start();
 private:
    double timeout;
};

#endif /* SRC_AUTO_ACTION_WAITTIMEACTION_H_ */
