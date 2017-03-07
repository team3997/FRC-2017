#include "DriveRotateMotorsPIDOutput.h"
#include "WPILib.h"

DriveRotateMotorsPIDOutput::DriveRotateMotorsPIDOutput(RobotDrive *drive) {
    this->drive = drive;
}

//Override
void DriveRotateMotorsPIDOutput::PIDWrite(double output) {
    drive->ArcadeDrive(0.0, output, false);
}
