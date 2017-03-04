#ifndef TRIGGERREADER_H_
#define TRIGGERREADER_H_

#include "WPILib.h"

//This file outlines classes that read the states of buttons.
//ButtonReader reads the states of push buttons
class TriggerReader {
public:
    TriggerReader(Joystick *joy, int trigger);
    virtual ~TriggerReader();
    void ReadValue();
    bool IsDown();
    bool WasJustPressed();
    bool WasJustReleased();
    bool StateJustChanged();

private:
    Joystick *joystick;
    int triggerAxis;
    bool lastState;
    bool currState;
};

#endif
