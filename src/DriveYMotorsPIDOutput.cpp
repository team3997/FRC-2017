#include "DriveYMotorsPIDOutput.h"
#include "WPILib.h"

DriveYMotorsPIDOutput::DriveYMotorsPIDOutput(RobotDrive *drive) {
    this->drive = drive;
}

//Override
void DriveYMotorsPIDOutput::PIDWrite(double output) {
    drive->ArcadeDrive(output, 0.0, false);
}
