
/******************************************************************************
This file is for configuring table-specifc values.
******************************************************************************/

#define CONFIG_X_STEPS_PER_MM 78.6 //microsteps/mm (no integers, e.g. use 80.0 instead of 80)
#define CONFIG_Y_STEPS_PER_MM 78.6 //microsteps/mm (no integers, e.g. use 80.0 instead of 80)
#define CONFIG_Z_STEPS_PER_MM 33.33333333 //microsteps/mm (no integers, e.g. use 80.0 instead of 80)

#define CONFIG_PULSE_MICROSECONDS 5
#define CONFIG_FEEDRATE 8000.0 // in millimeters per minute
#define CONFIG_SEEKRATE 8000.0
#define CONFIG_ACCELERATION 1800000.0 // mm/min^2, typically 1000000-8000000, divide by (60*60) to get mm/sec^2
#define CONFIG_JUNCTION_DEVIATION 0.006 // mm
#define CONFIG_X_ORIGIN_OFFSET 5.0  // mm, x-offset of table origin from physical home
#define CONFIG_Y_ORIGIN_OFFSET 5.0  // mm, y-offset of table origin from physical home
#define CONFIG_Z_ORIGIN_OFFSET 0.0   // mm, z-offset of table origin from physical home

#define CONFIG_INVERT_X_AXIS 0
#define CONFIG_INVERT_Y_AXIS 1  // 0 is regular, 1 inverts the y direction
#define CONFIG_INVERT_Z_AXIS 1  // 0 is regular, 1 inverts the y direction
