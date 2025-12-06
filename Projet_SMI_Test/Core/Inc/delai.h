/*
 * delai.h
 *
 *  Created on: 20 sept. 2025
 *      Author: aymane
 */

#ifndef DELAI_H_
#define DELAI_H_

#include <stdint.h>

void MonSysTick_Handler(void);
void systick_init_1us(void);
uint32_t micros(void);
void delay_us(uint32_t us);
int delay_mesure(uint32_t us);


#endif /* DELAI_H_ */
