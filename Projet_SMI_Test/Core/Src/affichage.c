/*
 * affichage.c
 *
 *  Created on: 5 nov. 2025
 *      Author: aymane
 */



#include"affichage.h"
#include"delai.h"
#include"gpio.h"
#include"spi.h"
#include "lcd_driver.h"

#include <math.h>

#define M_PI 3.14159265358979323846

#define SLEEP_TIME 5000 // Temps d'attente avant de passer en mode veille (en ms)

// Variables de contr�le
uint32_t lastTouchTime = 0; // Derni�re fois o� l'�cran a �t� touch�
uint16_t isScreenOn = 0;    // 1 si l'�cran est allum�, 0 si �teint


void AFFICHAGE_InitLcd(){
    	GPIO_clockActive();
    	//systick_init_1us();
    	GPIO_init_pin_spi();
    	SPI_Module_Init();
    	LCD_InitSerialInterface();
}


//void AFFICHAGE_reception(char* liste, int* j_index_liste){
//    if (tete_ecriture != tete_lecture) {
//        liste[*j_index_liste] = fifo_d_zb[tete_lecture];
//        (*j_index_liste)++;
//
//        tete_lecture++;
//        if (tete_lecture >= taille_fifo) {
//            tete_lecture = 0;
//        }
//    }
//}


void AFFICHAGE_TraiterChar(char c, uint16_t* x, uint16_t* y, uint16_t* text_color, uint16_t* bg_color)
{
    if (c == '\n' || c == 0x0A) {
        *y += 25;
        return;
    }
    else if (c == '\r' || c == 0x0D) {
        *x = 20;
        *y = 30;
        return;
    }

    LCD_WriteChar((uint8_t)c, *text_color, *bg_color, *x, *y);
    *x += CHAR_WIDTH_16;
}

void AFFICHAGE_TraiterToutMot(char valeur[], uint16_t* x, uint16_t* y, uint16_t* text_color, uint16_t* bg_color){
	for (int i = 0; valeur[i] != '\0'; i++){
		AFFICHAGE_TraiterChar(valeur[i], &x, &y, &text_color, &bg_color);
	}
}


// Display humidity as a horizontal bar (e.g., filled bar)
void Affichage_DisplayHumidityBar(uint16_t humidity, uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
    uint16_t barColor = 0x0cf7;  // Couleur verte pour la barre
    uint16_t backColor = 0xFFFFFF; // Fond blanc

    uint16_t barWidth = (width * humidity) / 100;  // Calcul de la largeur en fonction de l'humidit�

    // Dessiner le fond de la barre
    LCD_SetAddress(x, y, x + width, y + height);
        LCD_CopyColorToFrameBuffer(backColor);
        LCD_TransmitFrameBuffer_Personnaliser();

    // Dessiner la partie de la barre remplie (selon l'humidit�)
    LCD_SetAddress(x, y, x + barWidth, y + height);
        LCD_CopyColorToFrameBuffer(barColor);
        LCD_TransmitFrameBuffer_Personnaliser();
}



void LCD_InitControl() {
    AFFICHAGE_InitLcd();
    isScreenOn = 1; // L'�cran est initialement allum�
}


void LCD_DisplayControl() {
    uint32_t currentTime = HAL_GetTick();

    // V�rifier si le temps d'inactivit� est �coul�
    if ((currentTime - lastTouchTime) > SLEEP_TIME) {
        if (isScreenOn) {
            // �teindre l'�cran
            LCD_TransmitFrameBuffer_Personnaliser();  // Vous pouvez avoir une fonction qui �teint r�ellement l'�cran
            isScreenOn = 0; // Passer l'�cran en mode veille
        }
    } else {
        if (!isScreenOn) {
            // Allumer l'�cran si touch�
            LCD_InitControl();  // R�initialiser l'�cran si n�cessaire
        }
    }
}

