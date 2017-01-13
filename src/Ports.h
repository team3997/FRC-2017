#ifndef PORTS_H
#define PORTS_H

// ***************** PWM PORTS *****************
static const int LEFT_DRIVE_MOTOR_A_PWM_PORT            = 0;
static const int LEFT_DRIVE_MOTOR_B_PWM_PORT            = 1;
static const int RIGHT_DRIVE_MOTOR_A_PWM_PORT           = 2;
static const int RIGHT_DRIVE_MOTOR_B_PWM_PORT           = 3;

// ***************** PDP CHANNELS *****************

 static const int LEFT_DRIVE_MOTOR_A_PDP_CHAN           = 12;
 static const int LEFT_DRIVE_MOTOR_B_PDP_CHAN           = 13;
 static const int RIGHT_DRIVE_MOTOR_A_PDP_CHAN          = 14;
 static const int RIGHT_DRIVE_MOTOR_B_PDP_CHAN          = 15;

// ***************** DIGITAL I/O PORTS *****************

// ******************* ANALOG IN PORTS*******************

// ***************** MISC *****************

// ***************** SOLENOID PORTS *****************

// ***************** JOYSTICK USB PORTS *****************
//MAKE SURE JOYSTICKS ARE SET TO "D" position on back

static const bool USING_WIN_DRIVER_STATION              = true;
static const int DRIVER_JOY_USB_PORT                    = 0;
static const int OPERATOR_JOY_USB_PORT                  = 1;
// ***************** BUTTONS *****************

static const int F310_WIN_LEFT_X_AXIS                   = 0;
static const int F310_WIN_LEFT_Y_AXIS                   = 1;
static const int F310_WIN_RIGHT_X_AXIS                  = 2;
static const int F310_WIN_RIGHT_Y_AXIS                  = 3;

static const int F310_LINUX_LEFT_X_AXIS                 = 0;
static const int F310_LINUX_LEFT_Y_AXIS                 = 1;
static const int F310_LINUX_RIGHT_X_AXIS                = 2;
static const int F310_LINUX_RIGHT_Y_AXIS                = 3;

//Drive controller button ports and preferences

static const bool SQUARE_DRIVE_AXIS_INPUT               = true;
static const bool USE_ARCADE_DRIVE                      = true;

static const int DRIVE_DIRECTION_BUTTON_PORT            = 9;

#endif
