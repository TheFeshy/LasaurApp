/*
  CGrbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "laser.h"

//// laser control
// Setup Timer0 for a 488.28125Hz "phase correct PWM" wave (assuming a 16Mhz clock)
// Timer0 can pwm either PD5 (OC0B) or PD6 (OC0A), we use PD6
// TCCR0A and TCCR0B are the registers to setup Timer0
// see chapter "8-bit Timer/Counter0 with PWM" in Atmga328 specs
// OCR0A sets the duty cycle 0-255 corresponding to 0-100%
// also see: http://arduino.cc/en/Tutorial/SecretsOfArduinoPWM
void laser_init(){
  #ifdef LASER_FIRE_PIN
    SET_OUTPUT(LASER_FIRE_PIN);
  #endif
  // TCCR0A = _BV(COM0A1) | _BV(WGM00);   // phase correct PWM mode
  // TCCR0A = _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);  // fast PWM mode
  #ifdef LASER_PWM_PIN
    LASER_TIMER_A = _BV(LASER_COMPARE_MODE) | _BV(WGM40);   // phase correct PWM mode
    LASER_TIMER_B = _BV(CS01) | _BV(CS00);    // 64 => 489Hz
    SET_OUTPUT(LASER_PWM_PIN);
  #endif
  control_laser_intensity(0); //Set PWM at 0% duty cycle
}


// prescaler: PWMfreq = 16000/(2*256*prescaler)
// TCCR0B = _BV(CS00);                // 1 => 31.3kHz
// TCCR0B = _BV(CS01);                // 8 => 3.9kHz
// TCCR0B = _BV(CS01) | _BV(CS00);    // 64 => 489Hz
// TCCR0B = _BV(CS02);                // 256 => 122Hz
// TCCR0B = _BV(CS02) | _BV(CS00);    // 1024 => 31Hz
// NOTES:
// PPI = PWMfreq/(feedrate/25.4/60)
void control_laser_intensity_PWM(uint8_t intensity) {
  /////////////////////////////////////////////////////////////////////////////
  // This is the section to control laser output by PWM.  There is also
  // a simpler "on/off" control method below.
    //TODO: Check for laser invert logic here, or our intensities will be
    //semi-backwards (pulse frequency will increase but duty cycle decrease)
  LASER_OUTPUT_COMPARE = intensity;
  // depending on intensity adapt PWM freq
  // assuming: TCCR0A = _BV(COM0A1) | _BV(WGM00);  // phase correct PWM mode
  if (intensity > 40) {
    // set PWM freq to 3.9kHz
    LASER_TIMER_B = _BV(CS01);
  } else if (intensity > 10) {
    // set PWM freq to 489Hz
    LASER_TIMER_B = _BV(CS01) | _BV(CS00);
  } else {
    // set PWM freq to 122Hz
    LASER_TIMER_B = _BV(CS02);
  }
}

void control_laser_intensity_BINARY(uint8_t intensity) {
  #ifdef INVERT_LASER_LOGIC
    #define LASER_LOGIC_XOR true
  #else
    #define LASER_LOGIC_XOR false
  #endif
  if (intensity) {
    WRITE(LASER_FIRE_PIN, true ^ LASER_LOGIC_XOR);
  }
  else {
    WRITE(LASER_FIRE_PIN, false ^ LASER_LOGIC_XOR);
  }
}

void control_laser_intensity(uint8_t intensity) {
  #ifdef LASER_FIRE_PIN
    control_laser_intensity_BINARY(intensity);
  #endif
  #ifdef LASER_PWM_PIN
    control_laser_intensity_PWM(intensity);
  #endif
}
