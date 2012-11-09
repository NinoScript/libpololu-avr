/*
 * main.cc
 *
 *  Created on: Nov 8, 2012
 *      Author: ninoscript
 */

#include <pololu/orangutan.h>

/* This port correponds to the "-W 0x20,-" command line option. */
#define special_output_port (*((volatile char *)0x20))

/* This port correponds to the "-R 0x22,-" command line option. */
#define special_input_port  (*((volatile char *)0x22))

/* Poll the specified string out the debug port. */
void debug_puts(const char *str) {
	const char *c;

	for(c = str; *c; c++) {
		special_output_port = *c;
	}
}

int main ()
{
	print("Hello!");
	debug_puts("debug hello");

	play("L16 ceg>c");

	while(1)
	{
		red_led(0);
		green_led(1);

		delay_ms(100);

		red_led(1);
		green_led(0);

		delay_ms(100);
	}

	return 0;
}


