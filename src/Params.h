#ifndef PARAMS_H
#define PARAMS_H
#include "WPILib.h"
//Params.h: Preferences for the robot

static bool SQUARE_DRIVE_AXIS_INPUT                    = true;
static const bool USE_ARCADE_DRIVE                     = true;

static const double SHOOTER_HARDSET_MOTOR_SPEED        = 1.0;
static const bool SHOOTER_USE_PID                      = false;
static double FEEDER_HARDSET_MOTOR_SPEED               = 1.0;

static double GLOBAL_DRIVE_SPEED_MULTIPLIER            = 1.0;

static const double CLIMBER_HARDSET_MOTOR_SPEED        = 1.0;

//PID PAARAMS
static const double SHOOTER_PID_SETPOINT               = 3300.0;
static const double SHOOTER_THRESHOLD_FOR_FEEDER       = 2800.0;
static const double SHOOTER_PID_VALUES[]               = {0.0, 0.0, 0.0}; // P, I, D


#endif
