/*****************************************************************************
This is where pin assignments for your CPU and driverboard are configured.
Below is my best guess at a Lasersaur Driveboard, using an ATMega328p,
as this was the lasersaur default.  Please be aware that this HAS NOT BEEN
TESTED, and YOU ASSUME ALL LIABILITY IF YOU TEST THIS CODE.
*****************************************************************************/

#ifdef CONTROL_BOARD
#error "control board already defined: CONTROL_BOARD=" CONTROL_BOARD
#endif

#ifndef lasersaur_driveboard
#define lasersaur_driveboard
#define CONTROL_BOARD "lasersaur_driveboard"

#include "../fastio.h"

#define POWER_PIN             2
#define CHILLER_PIN           3
//#define DOOR_PIN

#define AIR_ASSIST_PIN        4 //enabled/diabled by gcode m80/m81
#define AUX1_ASSIST_PIN       7 //enabled/disabled by gcode m82/m83
#define AUX2_ASSIST_PIN       5 //enabled/disabled by gcode m84/m85

//#define LIMITS_OVERWRITE_PIN  -1 //Some versions of lasersaur have hardware
                                   //cutoffs for door open, no power, etc.
                                   //These cutoffs can be disabled (then why
                                   //make them hardware?), and if you want the
                                   //firmware to disable them, set this to the
                                   //pin that is attached to the disable pin of
                                   //the cutoff hardware.  Outputs 0 to disable.

#define X1_LIMIT_PIN            14
#define X2_LIMIT_PIN            15
#define Y1_LIMIT_PIN            16
#define Y2_LIMIT_PIN            17
#define Z1_LIMIT_PIN            18
#define Z2_LIMIT_PIN            19

#define X_STEP_PIN              8
#define X_DIRECTION_PIN         11
//#define X_ENABLE_PIN          The lasersaur driveboard does not use enable pin

#define Y_STEP_PIN              9
#define Y_DIRECTION_PIN         12
//#define Y_ENABLE_PIN          The lasersaur driveboard does not use enable pin

//Note: It appears that the z "home" code is disabled in current lasersaur.
#define Z_STEP_PIN              10
#define Z_DIRECTION_PIN         13
//#define Z_ENABLE_PIN          The lasersaur driveboard does not use enable pin


#define LASER_OUTPUT_COMPARE      OCR0 //Timer register that drives PWM control
#define LASER_COMPARE_MODE        COM0A1 //This sets both the compare mode and
                                         //which pins are attached to the timer
                                         //as PWM.  It should be COMnx1, where
                                         //n and x match the PWM register.
//#define LASER_FIRE_PIN            5 //Pin for on/off laser control
#define LASER_PWM_PIN             6 //Pin for PWM laser control
#define LASER_TIMER_A             TCCR0A
#define LASER_TIMER_B             TCCR0B
#define PWM_LASER_CONTROL       1  //Allow the firmware to adjsut the laser
                                   //power via PWM.  This is the default.
                                   //Comment out this line to reduce laser
                                   //control to a simple on/off.
#define INVERT_LASER_LOGIC         //Is your laser pull-up or pull-down? Change
                                   //this to adjust.

#endif //include guards

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
