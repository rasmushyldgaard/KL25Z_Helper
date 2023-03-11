/*
 * gpio_driver.c
 *
 *  Created on: 5. mar. 2023
 *      Author: rasmu
 */

#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "gpio_driver.h"


#define MASK(x) 		(1UL << (x))
#define True			(0x1)
#define False			(0x0)

uint8_t RED_LED_INITIALIZED = False;
uint8_t GREEN_LED_INITIALIZED = False;
uint8_t BLUE_LED_INITIALIZED = False;


void InitGPIO_OUT(unsigned char port, uint8_t pinNum)
{
	switch(port)
	{
	case 'A':
		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
		PORTA->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTA->PCR[pinNum] |= PORT_PCR_MUX(1);
		PTA->PDDR |= MASK(pinNum);
		PTA->PCOR = MASK(pinNum);
		break;
	case 'B':
		SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
		PORTB->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTB->PCR[pinNum] |= PORT_PCR_MUX(1);
		PTB->PDDR |= MASK(pinNum);
		PTB->PCOR = MASK(pinNum);
		break;
	case 'C':
		SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
		PORTC->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTC->PCR[pinNum] |= PORT_PCR_MUX(1);
		PTC->PDDR |= MASK(pinNum);
		PTC->PCOR = MASK(pinNum);
		break;
	case 'D':
		SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
		PORTD->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTD->PCR[pinNum] |= PORT_PCR_MUX(1);
		PTD->PDDR |= MASK(pinNum);
		PTD->PCOR = MASK(pinNum);
		break;
	default:
		perror("PORT is UNDEFINED!");
	}

}


void InitGPIO_IN(unsigned char port, uint8_t pinNum, uint8_t pe, uint8_t ps, uint8_t irq)
{
	switch(port)
	{
	case 'A':
		SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
		PORTA->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTA->PCR[pinNum] |= PORT_PCR_MUX(1) | PORT_PCR_MUX(pe) | PORT_PCR_MUX(ps) | PORT_PCR_IRQC(irq);
		PTA->PDDR &= ~MASK(pinNum);

	case 'B':
		SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
		PORTB->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTB->PCR[pinNum] |= (PORT_PCR_ISF_MASK | PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_IRQC(irq));
		PTB->PDDR &= ~MASK(pinNum);

	case 'C':
		SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
		PORTC->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTC->PCR[pinNum] |= PORT_PCR_MUX(1) | PORT_PCR_MUX(pe) | PORT_PCR_MUX(ps) | PORT_PCR_IRQC(irq);
		PTC->PDDR &= ~MASK(pinNum);

	case 'D':
		SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
		PORTD->PCR[pinNum] &= ~PORT_PCR_MUX_MASK;
		PORTD->PCR[pinNum] |= PORT_PCR_MUX(1) | PORT_PCR_MUX(pe) | PORT_PCR_MUX(ps) | PORT_PCR_IRQC(irq);
		PTD->PDDR &= ~MASK(pinNum);

	default:
		perror("PORT is UNDEFINED!");

	}

}


void SetRGB(uint8_t r, uint8_t g, uint8_t b)
{
	if ((RED_LED_INITIALIZED == False) | (GREEN_LED_INITIALIZED == False) | (BLUE_LED_INITIALIZED == False))
	{
		if ((r == 1) & (RED_LED_INITIALIZED == False))
		{
			InitGPIO_OUT('B', 18);
			RED_LED_INITIALIZED = True;
		}

		if ((g == 1) & (GREEN_LED_INITIALIZED == False))
		{
			InitGPIO_OUT('B', 19);
			GREEN_LED_INITIALIZED = True;
		}

		if ((b == 1) & (BLUE_LED_INITIALIZED == False))
		{
			InitGPIO_OUT('D', 1);
			BLUE_LED_INITIALIZED = True;
		}
	}

	/* Turn RED led on */
	if (r == 1)
		PTB->PCOR = MASK(18);
	else
		PTB->PSOR = MASK(18);

	/* Turn GREEN led on */
	if (g == 1)
		PTB->PCOR = MASK(19);
	else
		PTB->PSOR = MASK(19);

	/* Turn BLUE led on */
	if (b == 1)
		PTD->PCOR = MASK(1);
	else
		PTD->PSOR = MASK(1);
}

void TogglePin(unsigned char port, uint8_t pinNum, uint8_t status)
{
	switch(port)
	{
	case 'A':
		if (status == 1)
			PTA->PSOR = MASK(pinNum);
		else
			PTA->PCOR = MASK(pinNum);
		break;
	case 'B':
		if (status == 1)
			PTB->PSOR = MASK(pinNum);
		else
			PTB->PCOR = MASK(pinNum);
		break;
	case 'C':
		if (status == 1)
			PTC->PSOR = MASK(pinNum);
		else
			PTC->PCOR = MASK(pinNum);
		break;
	case 'D':
		if (status == 1)
			PTD->PSOR = MASK(pinNum);
		else
			PTD->PCOR = MASK(pinNum);
		break;
	default:
		perror("PORT is undefined");
		break;
	}

}

