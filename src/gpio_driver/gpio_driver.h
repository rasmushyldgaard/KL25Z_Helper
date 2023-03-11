/*
 * gpio_driver.h
 *
 *  Created on: 5. mar. 2023
 *      Author: rasmu
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

void InitGPIO_OUT(unsigned char port, uint8_t pinNum);
void InitGPIO_IN(unsigned char port, uint8_t pinNum, uint8_t pe, uint8_t ps, uint8_t irq);
void SetRGB(uint8_t r, uint8_t g, uint8_t b);
void TogglePin(unsigned char port, uint8_t pinNum, uint8_t status);


#endif /* GPIO_DRIVER_H_ */
