/*
 * pit_driver.h
 *
 *  Created on: 5. mar. 2023
 *      Author: rasmu
 */

#ifndef PIT_DRIVER_H_
#define PIT_DRIVER_H_

uint8_t Init_PIT(uint8_t chn);
void Control_PIT(uint8_t chn, uint8_t enable);

#endif /* PIT_DRIVER_H_ */
