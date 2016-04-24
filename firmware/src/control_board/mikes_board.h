
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
                                   //the cutoff hardware. Outputs 0 to disable.



#define X_STEP_PIN              26  //E Axis
#define X_DIRECTION_PIN         28
#define X_ENABLE_PIN            24

#define Y_STEP_PIN              36  //Q Axis
#define Y_DIRECTION_PIN         34
#define Y_ENABLE_PIN            30
#define X1_LIMIT_PIN            3   //x1_limit
#define Y1_LIMIT_PIN            14  //y2_limit

#define LASER_OUTPUT_COMPARE      OCR4AL //Timer register that drives PWM control
#define LASER_COMPARE_MODE        COM4A1 //This sets both the compare mode and
                                         //which pins are attached to the timer
                                         //as PWM.  It should be COMnx1, where
                                         //n and x match the PWM register.
#define LASER_FIRE_PIN            5 //Pin for on/off laser control
//#define LASER_PWM_PIN             6 //Pin for PWM laser control
#define LASER_TIMER_A             TCCR4A
#define LASER_TIMER_B             TCCR4B
//#define PWM_LASER_CONTROL       1  //Allow the firmware to adjsut the laser
                                   //power via PWM.  This is the default.
                                   //Comment out this line to reduce laser
                                   //control to a simple on/off.
#define INVERT_LASER_LOGIC         //Is your laser pull-up or pull-down? Change
                                   //this to adjust.
#endif //include guard


/******************************************************************************
Memory tweaks and configuration
******************************************************************************/
// The number of linear motions that can be in the plan at any give time
// (The block buffer is make of block_t, currently about 72 bytes.  So memory
//  use of this parameter is BLOCK_BUFFER_SIZE * 72)
#define BLOCK_BUFFER_SIZE 16  // do not make bigger than uint8_t

//Size of the serial protocol buffer (in bytes)
#define RX_BUFFER_SIZE 255
#define TX_BUFFER_SIZE 128
