#ifndef SHOOTERCONTROLLER_H_ 
#define SHOOTERCONTROLLER_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class ShooterController{
  public:
    ShooterController(RobotModel*, RemoteControl*);
    virtual ~ShooterController();

    enum ShooterState {
      kInitialize, kTeleop
    };
  private:
    RobotModel *robot;
    RemoteControl *humanControl;

    PIDController *shooterPID;

    PIDSourceType pidType;

    PIDOutput;

    double p, i, d;

    uint32_t m_stateVal;
    uint32_t nextState;
};

#endif
