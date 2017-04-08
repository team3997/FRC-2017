#ifndef PARAMS_H
#define PARAMS_H
#include "WPILib.h"

//Params.h: Preferences for the robot
static bool SQUARE_DRIVE_AXIS_INPUT                    = true;
static const bool USE_ARCADE_DRIVE                     = true;

static double GLOBAL_DRIVE_SPEED_MULTIPLIER            = 1.0;
static const double HARDSET_DRIVE_SPEED_MAX			   = 0.9;

static const double CLIMBER_HARDSET_MOTOR_SPEED        = 1.0;

//GEAR HOLDER PARAMS
static const double GEAR_WHEELS_RESTING_MOTOR_SPEED    = 0.0;
static const double GEAR_WHEELS_ACTIVE_MOTOR_SPEED     = 0.75;
static const double GEAR_TILTER_MAX_MOTOR_SPEED        = 0.4;
static const double GEAR_POT_UP_POSITION               = 0.284;
static const double GEAR_POT_DOWN_POSITION             = 0.320;

//DRIVE PID PARAMS

static const double DRIVE_Y_PID_VALUES[]               = {1.0, 0.0, 0.0}; // P, I, D
static const double DRIVE_Y_PID_SCALE_VALUES[] 		   = {0.125, 1.0, 1.0}; //P, I, D

static const int DRIVE_Y_PID_TOLERANCE                 = 0.5;
static const int DRIVE_Y_PID_SAMPLES_AVERAGE           = 1;

static const double DRIVE_X_PID_VALUES[]               = {0.0, 0.0, 0.0}; // P, I, D
static const double DRIVE_X_PID_SCALE_VALUES[] 		   = {1.0, 1.0, 1.0}; //P, I, D

static const int DRIVE_X_PID_TOLERANCE                 = 10;
static const int DRIVE_X_PID_SAMPLES_AVERAGE           = 10;


//PINI UPDATES
/*static double PINI_P;
static double PINI_D;
static double PINI_I;*/

//[DEBUGGING]

//[DRIVE_PID]
static const double drive_p = 0.4;
static const double drive_i = 0.0;
static const double drive_d = 0.05;

//[GEAR_PID]
static const double gear_p = 6.5;
static const double gear_i = 0.000;
static const double gear_d = 0.0;
static const double gear_f = 0.1;

//[GEAR_DOWN_PID]
static const double gear_down_p = 0.0;
static const double gear_down_i = 0.0;
static const double gear_down_d = 0.0;

//[CAMERA]
static const double h_low = 0;
static const double h_high = 180;
static const double s_low = 0;
static const double s_high = 255;
static const double v_low = 0;
static const double v_high = 255;

//[PINI]
static const double PINI_P = 160.0;
static const double PINI_I = 9000.0;
static const double PINI_D = 700.0;


#endif
