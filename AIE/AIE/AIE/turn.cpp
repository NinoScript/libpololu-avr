/*
 * Code to perform various types of turns.  The delays here had to be
 * calibrated for the 3pi's motors.
 */

#include "robot-wrapper.h"

// Turns according to the parameter dir, which should be 'L', 'R', 'S'
// (straight), or 'B' (back).
void turn(char dir)
{
#if(AVRTARGET)
	switch(dir)
	{
	case 'L':
		// Turn left.
		set_motors(-80,80);
		delay_ms(200);
		break;
	case 'R':
		// Turn right.
		set_motors(80,-80);
		delay_ms(200);
		break;
	case 'B':
		// Turn around.
		set_motors(80,-80);
		delay_ms(400);
		break;
	case 'S':
		// Don't do anything!
		break;
	}
#endif
}

// Local Variables: **
// mode: C **
// c-basic-offset: 4 **
// tab-width: 4 **
// indent-tabs-mode: t **
// end: **
