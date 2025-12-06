/*
 * affichage.h
 *
 *  Created on: 5 nov. 2025
 *      Author: aymane
 */

#ifndef AFFICHAGE_H_
#define AFFICHAGE_H_

#include <stm32f4xx.h>
#include <stdint.h>
#include"spi.h"
#include"delai.h"
#include"gpio.h"
#include"lcd_driver.h"
#include <stddef.h>  // pour NULL


void AFFICHAGE_InitLcd();
void AFFICHAGE_reception(char* liste, int* j_index_liste);

void AFFICHAGE_TraiterChar(char c, uint16_t* x, uint16_t* y, uint16_t* text_color, uint16_t* bg_color);
void AFFICHAGE_TraiterToutMot(char valeur[], uint16_t* x, uint16_t* y, uint16_t* text_color, uint16_t* bg_color);

// Function to display humidity as a graphical bar
void Affichage_DisplayHumidityBar(uint16_t humidity, uint16_t x, uint16_t y, uint16_t width, uint16_t height);


uint16_t ConvertHexRGB_to_RGB565(char* liste);
#endif /* AFFICHAGE_H_ */
