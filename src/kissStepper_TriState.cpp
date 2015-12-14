/******************************************************************************

    extend the great kissStepper Library
    for details see kissStepper_TriState.h

    written by stefan krueger (s-light),
        github@s-light.eu, http://s-light.eu, https://github.com/s-light/

    License: GNU Lesser General Public License (LGPL) V2.1

******************************************************************************/

/** Includes Core Arduino functionality **/
#if ARDUINO
    #if ARDUINO < 100
        #include <WProgram.h>
    #else
        #include <Arduino.h>
    #endif
#endif

#include <kissStepper.h>
#include "kissStepper_TriState.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// kissStepper_TriState
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void kissStepper_TriState::enable(void) {
    // Serial.println(F("  TriState-enable.  "));
    if (pinEnable != pinNotSet) {
        if (use_standby) {
            pinMode(pinEnable, INPUT);
            // digitalWrite(pinEnable, PINVAL_STANDBY);
        } else {
            pinMode(pinEnable, OUTPUT);
            digitalWrite(pinEnable, PINVAL_ENABLED);
        }
    }
    enabled = true;
}

void kissStepper_TriState::disable(void) {
    pinMode(pinEnable, OUTPUT);
    kissStepper::disable();
}

void kissStepper_TriState::useStandby(bool use_standby_new) {
    if (use_standby_new != use_standby) {
        use_standby = use_standby_new;
        if (enabled) {
            // enable so that pin state will be set to new configuration
            enable();
        }
    }
}

bool kissStepper_TriState::isUseStandby(void) {
    return use_standby;
}
