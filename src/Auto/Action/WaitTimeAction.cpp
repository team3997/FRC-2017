/*
 * WaitTimeAction.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: kidco
 */

#include "WaitTimeAction.h"
#include "WPILib.h"
WaitTimeAction::WaitTimeAction(double timeout) {
    this->timeout = timeout;
}

bool WaitTimeAction::IsFinished() {
    return Timer::GetFPGATimestamp() >= start_time + timeout;

}

void WaitTimeAction::Update() {

}
void WaitTimeAction::Done() {

}
void WaitTimeAction::Start() {
    start_time = Timer::GetFPGATimestamp();
}
