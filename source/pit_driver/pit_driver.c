/*
 * pit_driver.c
 *
 *  Created on: 5. mar. 2023
 *      Author: rasmu
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "pit_driver.h"


#define MASK(x) 		(1UL << (x))
#define ARR_EMPTY		(0xF)
#define ARR_FULL		(0x0)
#define LOAD_VAL		(209714)
#define True			(0x1)
#define False			(0x0)

uint8_t chnArr_Config[2] = { ARR_EMPTY, ARR_EMPTY };


uint8_t Init_PIT(uint8_t chn)
{
	uint8_t arrLen = sizeof(chnArr_Config) / sizeof(chnArr_Config[0]);

	for (int i = 0; i < arrLen; i++)
	{
		if (chnArr_Config[i] == ARR_EMPTY)
		{
			chnArr_Config[i] = chn;
		}
		else
		{
			return ARR_FULL;
		}
	}

	/*	PIT Module Clock  */
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;

	/*	PIT Module Control Register  */
	PIT->MCR &=  ~PIT_MCR_MDIS_MASK;		// write 0 to enable PIT, 1 to disable
	PIT->MCR &= ~PIT_MCR_FRZ_MASK;			// write 0 to allow PIT in dbg mode, 1 to stop PIT

	/*  PIT Load Value  */
	PIT->CHANNEL[chn].LDVAL = LOAD_VAL;		// formula is LDVAL = T * 10485760 - 1

	/*	Time Control Register  */
	PIT->CHANNEL[chn].TCTRL |= PIT_TCTRL_TIE_MASK;		// enable interrupts on chn
	PIT->CHANNEL[chn].TCTRL &= ~PIT_TCTRL_CHN_MASK;		// disable chaining of timers

	/*  NVIC Setup  */
	NVIC_SetPriority(PIT_IRQn, 1);			// set priority for PIT_IRQ in NVIC
	NVIC_ClearPendingIRQ(PIT_IRQn);			// clear any pending requests in NVIC
	NVIC_EnableIRQ(PIT_IRQn);				// enable PIT_IRQ in NVIC

	return 1;
}


void Control_PIT(uint8_t chn, uint8_t enable)
{
	if (enable == 1)
		PIT->CHANNEL[chn].TCTRL |= PIT_TCTRL_TEN_MASK;
	else
		PIT->CHANNEL[chn].TCTRL &=  ~PIT_TCTRL_TEN_MASK;
}
