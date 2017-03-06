#include "TriggerReader.h"

//Class TriggerReader
//Constructs a joystick and sets the port of the Trigger on the joystick, and reads the state of the Trigger
TriggerReader::TriggerReader(Joystick* joy, int trigger) {
	joystick = joy;
	triggerAxis = trigger;
	if (joystick->GetRawAxis(triggerAxis) > 0.8) {
		currState = true;
	} else {
		currState = false;
	}
	lastState = currState;
}

//Reads the value of the Trigger by setting the last state to the current state and updating the current state
void TriggerReader::ReadValue() {
	lastState = currState;
	if (joystick->GetRawAxis(triggerAxis) > 0.8) {
		currState = true;
	} else {
		currState = false;
	}
}

//Checks that the Trigger was not pressed previous to the current time
bool TriggerReader::WasJustPressed() {
	return (lastState == false && currState == true);
}

//Checks that the Trigger just changed state from pressed to released
bool TriggerReader::WasJustReleased() {
	return (lastState == true && currState == false);
}

//Checks if the state just changed either from pressed to released or released to pressed
bool TriggerReader::StateJustChanged() {
	return (lastState != currState);
}

//Checks if the Trigger is currently pressed
bool TriggerReader::IsDown() {
	return currState;
}

//TriggerReader destructor
TriggerReader::~TriggerReader() {
}

