//
//  robot-wrapper.h
//  Concurso AIE
//
//  Created by Cristián Arenas Ulloa on 11/3/12.
//  Copyright (c) 2012 Cristián Arenas Ulloa. All rights reserved.
//

#ifndef __Concurso_AIE__robot_wrapper__
#define __Concurso_AIE__robot_wrapper__

#ifndef AVRTARGET
#define AVRTARGET 1
#endif

#if(AVRTARGET)
	// The 3pi include file must be at the beginning of any program that
	// uses the Pololu AVR library and 3pi.
	#include <pololu/3pi.h>

	// This include file allows data to be stored in program space.  The
	// ATmega168 has 16k of program space compared to 1k of RAM, so large
	// pieces of static data should be stored in program space.
	#include <avr/pgmspace.h>

	#include "bargraph.h"
	#include "maze-solve.h"
#else
	#include <iostream>
	#define PROGMEM
#endif

class Robot {
	Robot () {};
public:
	void init();
};

#endif /* defined(__Concurso_AIE__robot_wrapper__) */
