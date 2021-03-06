/*
  sense_control.h - sensing and controlling inputs and outputs
  Part of LasaurGrbl

  Copyright (c) 2011 Stefan Hechenberger

  LasaurGrbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LasaurGrbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#ifndef sense_control_h
#define sense_control_h

#include <stdbool.h>
#include "config.h"
#include "fastio.h"


void sense_init();

//For now at least X and Y limits are necessary for homing!
#define SENSE_X1_LIMIT (READ(X1_LIMIT_PIN))
#define SENSE_Y1_LIMIT (READ(Y1_LIMIT_PIN))

#ifndef X2_LIMIT_PIN
  #define SENSE_X2_LIMIT 0
#else
  #define SENSE_X2_LIMIT !(READ(X2_LIMIT_PIN))
#endif

#ifndef Y2_LIMIT_PIN
  #define SENSE_Y2_LIMIT 0
#else
  #define SENSE_Y2_LIMIT !(READ(Y2_LIMIT_PIN))
#endif

#ifndef Z1_LIMIT_PIN
  #define SENSE_Z1_LIMIT 0
#else
  #define SENSE_Z1_LIMIT !(READ(Z1_LIMIT_PIN))
#endif

#ifndef Z2_LIMIT_PIN
  #define SENSE_Z2_LIMIT 0
#else
  #define SENSE_Z2_LIMIT !(READ(Z2_LIMIT_PIN))
#endif

#ifndef POWER_PIN
  #define SENSE_POWER_OFF 0
#else
  #define SENSE_POWER_OFF !(READ(POWER_PIN))
#endif

//#define SENSE_CHILLER_OFF !((SENSE_PIN >> CHILLER_BIT) & 1)
#ifndef CHILLER_PIN
  #define SENSE_CHILLER_OFF 0
#else
  #define SENSE_CHILLER_OFF !(READ(CHILLER_PIN))
#endif

//#define SENSE_DOOR_OPEN !((SENSE_PIN >> DOOR_BIT) & 1)
#ifndef DOOR_PIN
  #define SENSE_DOOR_OPEN 0
#else
  #define SENSE_DOOR_OPEN !(READ(DOOR_PIN))
#endif


#define SENSE_LIMITS (SENSE_X1_LIMIT || SENSE_X2_LIMIT || SENSE_Y1_LIMIT || SENSE_Y2_LIMIT || SENSE_Z1_LIMIT || SENSE_Z2_LIMIT)
#define SENSE_ANY (SENSE_LIMITS || SENSE_POWER_OFF || SENSE_CHILLER_OFF || SENSE_DOOR_OPEN)

void control_init();

void control_laser_intensity(uint8_t intensity);  //0-255 is 0-100%

void control_air_assist(bool enable);
void control_aux1_assist(bool enable);


#ifdef AUX2_ASSIST_PIN
  void control_aux2_assist(bool enable);
#endif

// dis/enable if steppers can still
// move when a limit switch is triggering
void control_limits_overwrite(bool enable);


#endif
