/*
 * sw_debounce.c
 *
 *  Created on: 4. mar. 2023
 *      Author: rasmushyldgaard
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "pit_driver/pit_driver.h"
#include "sw_debounce.h"


#define MASK(x) 		(1UL << (x))
#define PIT_CHANNEL		(0)
#define PIT_TRIGGER		(1)
#define True			(1)
#define False			(0)

unsigned long int BTN = 0;
uint32_t GPIO_PDIR = 0;
uint8_t PIT_INITIALIZED = False;


uint8_t SW_Debounce(uint32_t gpio_PDIR, unsigned long int btn)
{
	GPIO_PDIR = gpio_PDIR;
	BTN = btn;

	if (PIT_INITIALIZED != True)
	{
		if (Init_PIT(PIT_CHANNEL) != True)
			PIT_INITIALIZED = True;
		else
		{
			return 0;
		}
	}

	if (gpio_PDIR & MASK(btn))
	{
		Control_PIT(PIT_CHANNEL, PIT_TRIGGER);
	}

	return True;
}


/*void PIT_IRQHandler(void)
{
	// determine which channel triggered interrupt
	if (PIT->CHANNEL[PIT_CHANNEL].TFLG & PIT_TFLG_TIF_MASK)
	{
		if(!(GPIO_PDIR & MASK(BTN)))
		{
			count++;
			if (count > 4)
			{
				count = 0;
			}
			PIT->CHANNEL[PIT_CHANNEL].TCTRL &= ~PIT_TCTRL_TEN_MASK;
			PIT->CHANNEL[PIT_CHANNEL].TFLG &= PIT_TFLG_TIF_MASK;
		}
		else
		{
			PIT->CHANNEL[PIT_CHANNEL].TFLG &= PIT_TFLG_TIF_MASK;
		}
	}

}*/


