#ifndef DRIVEENCODERSPIDSOURCE_H_
#define DRIVEENCODERSPIDSOURCE_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"

class DriveEncodersPIDSource: public PIDSource {
public:
	DriveEncodersPIDSource(Encoder *leftEncoder, Encoder *rightEncoder);
	double GetAverageDistance();
	double PIDGet() override;

private:
	Encoder *leftEncoder, *rightEncoder;

};

#endif
