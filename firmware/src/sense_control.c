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

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdlib.h>
#include "sense_control.h"
#include "stepper.h"
#include "planner.h"
#include "fastio.h"
#include "laser.h"



void sense_init() {
  //// chiller, door, (power)
  //SENSE_DDR &= ~(SENSE_MASK);  // set as input pins
  #ifdef DOOR_PIN
    SET_INPUT(DOOR_PIN)
  #endif
  #ifdef POWER_PIN
    SET_INPUT(POWER_PIN)
  #endif
  #ifdef CHILLER_PIN
    SET_INPUT(CHILLER_PIN)
  #endif

  SET_INPUT(X1_LIMIT_PIN);
  SET_INPUT(Y1_LIMIT_PIN);
  #ifdef X2_LIMIT_PIN
    SET_INPUT(X2_LIMIT_PIN);
  #endif
  #ifdef Y2_LIMIT_PIN
    SET_INPUT(Y2_LIMIT_PIN);
  #endif
  #ifdef Z1_LIMIT_PIN
    SET_INPUT(Z1_LIMIT_PIN);
  #endif
  #ifdef Z2_LIMIT_PIN
    SET_INPUT(Z2_LIMIT_PIN);
  #endif

}


void control_init() {
  laser_init();
  //// air and aux assist control
  #ifdef AIR_ASSIST_PIN
  SET_OUTPUT(AIR_ASSIST_PIN);
  control_air_assist(false);
  #endif
  #ifdef AUX1_ASSIST_PIN
  SET_OUTPUT(AUX1_ASSIST_PIN);
  control_aux1_assist(false);
  #endif
  #ifdef AUX2_ASSIST_PIN
  SET_OUTPUT(AUX2_ASSIST_PIN);
  control_aux2_assist(false);
  #endif
  #ifdef LIMITS_OVERWRITE_PIN
  SET_OUTPUT(LIMITS_OVERWRITE_PIN);
  control_limits_overwrite(true);
  #endif
}


#ifdef AIR_ASSIST_PIN
  void control_air_assist(bool enable) {
    WRITE(AIR_ASSIST_PIN, enable);
  }
#endif

#ifdef AUX1_ASSIST_PIN
  void control_aux1_assist(bool enable) {
    WRITE(AUX1_ASSIST_PIN, enable);
  }
#endif

#ifdef AUX2_ASSIST_PIN
  void control_aux2_assist(bool enable) {
    WRITE(AUX2_ASSIST_PIN, enable);
  }
#endif

#ifdef LIMITS_OVERWRITE_PIN
  void control_limits_overwrite(bool enable) {
    WRITE(LIMITS_OVERWRITE_PIN, ~enable);
  }
#endif
