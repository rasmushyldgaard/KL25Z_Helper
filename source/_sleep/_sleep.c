/*
 * sleeper.c
 *
 *  Created on: 11. mar. 2023
 *      Author: rasmu
 */


void _sleep(unsigned int delay)
{
	/*	500k ticks ~= 85 ms	*/
	/* ie. delay = 3.000.000 ticks ~= 500 ms */
	while(delay--)
		;
}

