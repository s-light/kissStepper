/******************************************************************************

    extend the great kissStepper Library with an special Tri-State pin feature
    for TRINAMIC TMC2100 Stepper Driver (for Example: Watterott SilentStepStick)

    currently only the enable pin is supported.
    config pins could be done with some more reworking..

    written by stefan krueger (s-light),
        github@s-light.eu, http://s-light.eu, https://github.com/s-light/

    License: GNU Lesser General Public License (LGPL) V2.1

******************************************************************************/

#ifndef SRC_KISSSTEPPER_TRISTATE_H_
#define SRC_KISSSTEPPER_TRISTATE_H_

#include <kissStepper.h>

class kissStepper_TriState: public kissStepper {
    public:
        kissStepper_TriState(
            kissPinAssignments pinAssignments,
            kissMicrostepConfig microstepConfig
        ) :
            kissStepper(
                pinAssignments,
                microstepConfig
            )
        {}

        virtual void enable(void);
        virtual void disable(void);
        virtual void useStandby(bool use_standby_new);
        virtual bool isUseStandby(void);

    protected:
        static const uint8_t PINVAL_STANDBY = LOW;
        bool use_standby;
};  // kissStepper_TriState

#endif  // SRC_KISSSTEPPER_TRISTATE_H_
