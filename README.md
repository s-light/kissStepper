# kissStepper
Keep it Simple Stepper - a lightweight library for the Easy Driver, Big Easy Driver, and Allegro stepper motor drivers that use a Step/Dir interface

Written by Rylee Isitt. September 14, 2015

License: GNU Lesser General Public License (LGPL) V2.1

Despite the existence of several excellent libraries for driving stepper motors, I created this one to fullfill the following needs:
* LGPL instead of GPL, so that you can use it in your own project with few licensing restrictions (please read the LGPL V2.1 for details).
* Low memory and processing demands
* Consistent motor speed regardless of drive mode
* Consistent position index (measured in 1/16th steps), so even after changing drive modes, position 1000 will refer to the same location as before
* Automatic handling of MS1, MS2, and MS3 (microstep select) pins if desired
* Automatic handling of Enable pin if desired (set to 255 if you don't want to use this feature)
* Acceleration for driving heavier loads and reaching higher speeds before the motor stalls

Manifesto for Future Contributions:
* Main goal is to work with the Easy Driver and Big Easy Driver designed by Brian Schmalz.
* Secondary goal is to support Allegro stepper motor driver chips using a Step/Direction interface.
* This library is meant to be lightweight, well suited to applications where memory and clock cycles are limited.
* Care has been taken to avoid floating point numbers, expensive math operations, trig, etc. Please keep it that way.
* Avoid feature creep.
* Does your change fix a bug? Then great!
* Does your change add a brand new feature at the cost of slightly more memory/clock cycles needed? Then think twice.
* New features are fine if they are self-contained and won't be compiled in unless used in a project.
	* Compare the size and memory usage of a sketch before and after you add the feature to the library.
	* If you don't use the feature in your sketch, the sketch should not grow larger...
* Do not pollute the global namespace.
* Do not fill this library up with defines/macros. There is almost always a better way (eg, inline functions and constants).
* Use uintx_t/intx_t types, as they improve compatibility across different devices.
* Any changes to timing or acceleration code should be carefully tested
	* Measure frequency of STEP pin to make sure the output is an accurate and stable square wave
	* Use an oscilloscope if available
	* Or, time how long it takes (use micros()) for the motor to move a fixed distance then back-calculate RPM, accel, etc to make sure the timing matches the set values
	* Just listening to and watching the motor is also quite instructive...
