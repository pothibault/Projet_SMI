/*
 * spi.c
 *
 *  Created on: 4 nov. 2025
 *      Author: aymane
 */


#include <stm32f4xx.h>
#include <stdint.h>
#include"spi.h"


void SPI_Module_Init(void){

	RCC->APB2ENR |= BIT20;
	SPI5->CR1    &= ~BIT6;	//arreter SPI

	SPI5->CR1 |= BIT2; // Master configuration

    SPI5->CR1 |= BIT5; //Baud rate control 101 : clk / 64
    SPI5->CR1 &= ~BIT4;//Baud rate control 101 : clk / 64
    SPI5->CR1 |= BIT3;//Baud rate control 101 : clk / 64

    SPI5->CR1 |= BIT9; // Software slave management enable
    SPI5->CR1 |= BIT8;
    SPI5->CR1 &= ~BIT1; // CPOL = 0
    SPI5->CR1 &= ~BIT0; // CPHA = 0

    SPI5->CR1 |= BIT6; // reactiver SPI
}
