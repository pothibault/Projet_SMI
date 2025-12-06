/*
 * gpio.h
 *
 *  Created on: 16 sept. 2025
 *      Author: aymane
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stm32f4xx.h>
#include <stdint.h>
#include "macros_utiles.h"


//typedef enum {
//    GPIO_MODE_INPUT    = 0,
//    GPIO_MODE_OUTPUT   = 1,
//    GPIO_MODE_AF       = 2,
//    GPIO_MODE_ANALOG   = 3
//} GPIOMode_t;
//
//typedef enum {
//    GPIO_OTYPE_PP = 0,
//    GPIO_OTYPE_OD = 1
//} GPIOOType_t;
//
//typedef enum {
//    GPIO_PUPD_NONE = 0,
//    GPIO_PUPD_UP   = 1,
//    GPIO_PUPD_DOWN = 2
//} GPIOPuPd_t;
//
//typedef enum {
//    GPIO_SPEED_LOW       = 0,
//    GPIO_SPEED_MEDIUM    = 1,
//    GPIO_SPEED_HIGH      = 2,
//    GPIO_SPEED_VERY_HIGH = 3
//} GPIOSpeed_t;


void GPIO_clockActive();

//void GPIO_ConfigurePin(GPIO_TypeDef *GPIOx,
//                       uint8_t pin,
//                       GPIOMode_t mode,
//                       GPIOSpeed_t speed,
//                       GPIOOType_t otype,
//                       GPIOPuPd_t pupd,
//                       uint8_t af);

void SDRAM_GPIO_Init(void);

void GPIO_init_pin_spi();
void GPIO_init_pinUART(void);

#endif /* GPIO_H_ */
