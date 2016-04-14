
#ifdef CONTROL_BOARD
#error "control board already defined: CONTROL_BOARD=" CONTROL_BOARD
#endif

#ifndef ramps_1_4
#define ramps_1_4
#define CONTROL_BOARD "RAMPS_1_4"

#include "../fastio.h"

/*****************************************************************************
These are the standard RAMPS pins from their documentation.
They are included here for reference.  The settings used by lasersaur
are below.
******************************************************************************
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

//#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN             9

#define PS_ON_PIN          12
//#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN        8
#define TEMP_0_PIN         13   // ANALOG NUMBERING
#define TEMP_1_PIN         14   // ANALOG NUMBERING
*/

/******************************************************************************
Below are the pin definitions used by lasersaur.
******************************************************************************/
//#define POWER_PIN     //No default on RAMPS
//#define CHILLER_PIN   //No default on RAMPS
//#define DOOR_PIN      //No default on RAMPS
//#define AIR_ASSIST_PIN          //enabled/diabled by gcode m80/m81
//#define AUX1_ASSIST_PIN         //enabled/disabled by gcode m82/m83
//#define AUX2_ASSIST_PIN         //enabled/disabled by gcode m84/m85
//#define LIMITS_OVERWRITE_PIN  -1 //Some versions of lasersaur have hardware
                                   //cutoffs for door open, no power, etc.
                                   //These cutoffs can be disabled (then why
                                   //make them hardware?), and if you want the
                                   //firmware to disable them, set this to the
                                   //pin that is attached to the disable pin of
/* Mike's changes!                                   //the cutoff hardware. Outputs 0 to disable.
#define X1_LIMIT_PIN            3  //This pin MUST be defined, and is the X
                                   //minimum (home stop)
//#define X2_LIMIT_PIN            2
#define Y1_LIMIT_PIN            14 //This pin MUST be defined, and is the Y
                                   //minimum (home stop)
//#define Y2_LIMIT_PIN            15
//#define Z1_LIMIT_PIN            18
//#define Z2_LIMIT_PIN            19

/ These are the RAMPS 1.4 defaults.
TODO:D make a "mike's board" that imports these correct values, then changes
them to match what he has!

#define X_STEP_PIN              54
#define X_DIRECTION_PIN         55
#define X_ENABLE_PIN            38

#define Y_STEP_PIN              60
#define Y_DIRECTION_PIN         61
#define Y_ENABLE_PIN            56

//Note: It appears that the z "home" code is disabled in current lasersaur.
//#define Z_STEP_PIN              46
//#define Z_DIRECTION_PIN         48
//#define Z_ENABLE_PIN            62
*/

#define X_STEP_PIN              26
#define X_DIRECTION_PIN         28
#define X_ENABLE_PIN            24

#define Y_STEP_PIN              36
#define Y_DIRECTION_PIN         34
#define Y_ENABLE_PIN            30
#define X1_LIMIT_PIN            3
#define Y1_LIMIT_PIN            14

#endif //include guard
