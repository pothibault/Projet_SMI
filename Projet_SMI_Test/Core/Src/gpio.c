/*
 * gpio.c
 *
 *  Created on: 16 sept. 2025
 *      Author: aymane
 */

#include <stdint.h>
#include "gpio.h"


void GPIO_clockActive(){
	RCC->AHB1ENR |= (BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);
}

//void GPIO_ConfigurePin(GPIO_TypeDef *GPIOx,
//                       uint8_t pin,
//                       GPIOMode_t mode,
//                       GPIOSpeed_t speed,
//                       GPIOOType_t otype,
//                       GPIOPuPd_t pupd,
//                       uint8_t af)
//{
//    uint32_t pos2   = (uint32_t)pin * 2u;          // pour MODER / OSPEEDR / PUPDR
//    uint32_t pos1   = (uint32_t)pin;              // pour OTYPER
//
//    /* --- MODER : 2 bits par pin --- */
//    // masque 2 bits : (BIT0 | BIT1) d�cal� de pos2
//    uint32_t mask2  = (BIT0 | BIT1) << pos2;
//    GPIOx->MODER   &= ~mask2;                     // clear
//    GPIOx->MODER   |= ((uint32_t)mode << pos2);   // set (00,01,10,11)
//
//    /* --- OTYPER : 1 bit par pin --- */
//    uint32_t mask1  = (BIT0 << pos1);
//    GPIOx->OTYPER  &= ~mask1;                     // remet � 0
//    GPIOx->OTYPER  |= ((uint32_t)otype << pos1);  // 0 = PP, 1 = OD
//
//    /* --- OSPEEDR : 2 bits par pin --- */
//    GPIOx->OSPEEDR &= ~mask2;
//    GPIOx->OSPEEDR |= ((uint32_t)speed << pos2);  // 00..11
//
//    /* --- PUPDR : 2 bits par pin --- */
//    GPIOx->PUPDR   &= ~mask2;
//    GPIOx->PUPDR   |= ((uint32_t)pupd << pos2);   // 00..10
//
//    /* --- AFR : 4 bits par pin --- */
//    uint32_t afr_index = pin / 8u;                // AFR[0] ou AFR[1]
//    uint32_t afr_shift = (pin % 8u) * 4u;
//    uint32_t mask4     = (BIT0 | BIT1 | BIT2 | BIT3) << afr_shift;
//
//    GPIOx->AFR[afr_index] &= ~mask4;              // clear 4 bits
//    GPIOx->AFR[afr_index] |= ((uint32_t)af << afr_shift); // AF0..AF15
//}





void GPIO_init_pin_spi(){


    //MODER alternate POUR PC2 CSX
    GPIOC->MODER &= ~BIT5;
    GPIOC->MODER |=  BIT4;

    //MODER alternate POUR PF7 SCK
    GPIOF->MODER &= ~BIT14;
    GPIOF->MODER |=  BIT15;

    //MODER alternate POUR PF9 MOSI
    GPIOF->MODER &= ~BIT18;
    GPIOF->MODER |=  BIT19;

    //MODER alternate POUR PF8 MISO
    GPIOF->MODER &= ~BIT16;
    GPIOF->MODER |=  BIT17;

    //WRX/DC = PD13 WRX
    GPIOD->MODER &= ~BIT27;
    GPIOD->MODER |=  BIT26;


    //AFRL[31:28] pour PF7 SCK
    GPIOF->AFR[0] &= ~(BIT28 | BIT29 | BIT30 | BIT31);
    GPIOF->AFR[0] |=  (BIT28 | BIT30);

    //AFRH PF9 MOSI
    GPIOF->AFR[1] &= ~(BIT4 | BIT5 | BIT6 | BIT7);
    GPIOF->AFR[1] |=  (BIT4 | BIT6);

    //AFRH PF8 MISO
    GPIOF->AFR[1] &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    GPIOF->AFR[1] |=  (BIT0 | BIT2);
}


//void GPIO_init_pinUART(void)
//{
//	//horloge gpio c et d
//    RCC->AHB1ENR |= BIT2;
//    RCC->AHB1ENR |= BIT3;
//
//    //---PC12--- TX
//
//    //MODER alternate
//    GPIOC->MODER &= ~BIT24;
//    GPIOC->MODER |=  BIT25;
//
//    //AFRH Pour PC12
//    GPIOC->AFR[1] &= ~(BIT16 | BIT17 | BIT18 | BIT19);
//    GPIOC->AFR[1] |=  BIT19;
//
//    //---PD2--- RX
//
//    //MODER alternate
//    GPIOD->MODER &= ~BIT4;
//    GPIOD->MODER |=  BIT5;
//
//    //AFRL Pour PD2
//    GPIOD->AFR[0] &= ~(BIT8 | BIT9 | BIT10 | BIT11);
//    GPIOD->AFR[0] |=  BIT11;
//
//    GPIO_ConfigurePin(GPIOG, 13,
//                      GPIO_MODE_OUTPUT,
//                      GPIO_SPEED_LOW,
//                      GPIO_OTYPE_PP,
//                      GPIO_PUPD_NONE,
//                      0);
//    }
