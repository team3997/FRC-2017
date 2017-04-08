/*
 * AnalogPIDSource.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: kidco
 */

#include <AnalogPIDSource.h>

AnalogPIDSource::AnalogPIDSource(Potentiometer* analogInput) {
    this->analogInput = analogInput;
}

double AnalogPIDSource::PIDGet() {
    switch (analogInput->GetPIDSourceType()) {
      case PIDSourceType::kDisplacement:
        return analogInput->Get();
      case PIDSourceType::kRate:
        return 0.0;
      default:
        return 0.0;
    }
}

