/*
 * led_blinker.c
 * 	Date: 11-03-2023
 * 	Author: rasmushyldgaard
 *
 * 	Simple LED blinker with color swapping program
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include "gpio_driver/gpio_driver.h"
#include "_sleep/_sleep.h"

#define DELAY	(6000000)	// roughly 1 sec delay

enum color
{
	BLACK = 0,		// SetRGB(0,0,0)
	WHITE = 1,		// SetRGB(1,1,1)
	RED = 2,		// SetRGB(1,0,0)
	GREEN = 3,		// SetRGB(0,1,0)
	BLUE = 4,		// SetRGB(0,0,1)
	YELLOW = 5,		// SetRGB(1,1,0)
	CYAN = 6,		// SetRGB(0,1,1)
	MAGENTA = 7		// SetRGB(1,0,1)

} typedef _color;

void LED_ColorSwap(_color color);

int main(void) {

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	const _color colors [] =
	{
		BLACK,
		WHITE,
		RED,
		GREEN,
		BLUE,
		YELLOW,
		CYAN,
		MAGENTA
	};


	while(1)
	{
		for(size_t i = 0; i < sizeof(colors)/sizeof(*colors); i++)
		{
			LED_ColorSwap(colors[i]);
			_sleep(DELAY);
		}
	}

	return 0;
}

void LED_ColorSwap(_color color)
{
	switch(color)
	{
	case BLACK:
		SetRGB(0, 0, 0);
		break;
	case WHITE:
		SetRGB(1, 1, 1);
		break;
	case RED:
		SetRGB(1, 0, 0);
		break;
	case GREEN:
		SetRGB(0, 1, 0);
		break;
	case BLUE:
		SetRGB(0, 0, 1);
		break;
	case YELLOW:
		SetRGB(1, 1, 0);
		break;
	case CYAN:
		SetRGB(0, 1, 1);
		break;
	case MAGENTA:
		SetRGB(1, 0, 1);
		break;
	default:
		perror("COLOR is undefined");
		break;
	}
}
