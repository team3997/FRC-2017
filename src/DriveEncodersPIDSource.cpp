#include "DriveEncodersPIDSource.h"
#include "WPILib.h"

DriveEncodersPIDSource::DriveEncodersPIDSource(Encoder *leftEncoder, Encoder *rightEncoder) {
	this->leftEncoder = leftEncoder;
	this->rightEncoder = rightEncoder;
}
double DriveEncodersPIDSource::PIDGet() {
  if (leftEncoder->StatusIsFatal()) return 0.0;
  if (rightEncoder->StatusIsFatal()) return 0.0;
  switch (GetPIDSourceType()) {
    case PIDSourceType::kDisplacement:
      return GetAverageDistance();
    case PIDSourceType::kRate:
      return 0.0;
    default:
      return 0.0;
  }
}

double DriveEncodersPIDSource::GetAverageDistance() {
	return ((leftEncoder->GetDistance()) + (rightEncoder->GetDistance())) / 2.0;
}

