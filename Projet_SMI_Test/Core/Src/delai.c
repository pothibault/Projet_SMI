/*
 * delai_us.c
 *
 *  Created on: 20 sept. 2025
 *      Author: aymane
 */

#include <stdint.h>
extern uint32_t SystemCoreClock;

// Adresse des registres SysTick
#define SYSTICK_BASE   0xE000E010UL
#define SYST_CSR       (*(volatile uint32_t *)(SYSTICK_BASE + 0x00))
#define SYST_RVR       (*(volatile uint32_t *)(SYSTICK_BASE + 0x04))
#define SYST_CVR       (*(volatile uint32_t *)(SYSTICK_BASE + 0x08))

// Bits de contr�le
#define STK_CTRL_ENABLE    (1u << 0)
#define STK_CTRL_TICKINT   (1u << 1)
#define STK_CTRL_CLKSOURCE (1u << 2)

// Variable microsecondes
static volatile uint32_t s_micros = 0;

// Initialisation du SysTick pour interruption chaque 1 �s
void systick_init_1us(void){
	SYST_CSR = 0;
	SYST_RVR = (SystemCoreClock / 1000000u) - 1u; // Reload every 1 �s
	SYST_CVR = 0;
	SYST_CSR = STK_CTRL_ENABLE | STK_CTRL_CLKSOURCE | STK_CTRL_TICKINT;
}

// Handler appele toutes les 1 �s
void MonSysTick_Handler(void)
{
	s_micros++;
}

// R�cup�ration du temps en �s
uint32_t micros(void){
	return s_micros;
}

// Attente active en �s
void delay_us(uint32_t us){
    uint32_t start = s_micros;
    while ((uint32_t)(s_micros - start) < us) {
        __asm volatile ("nop");
    }

}

int delay_mesure(uint32_t us){
    uint32_t start = s_micros;
    while ((uint32_t)(s_micros - start) < us) {
        // attente active sans bloquer
    }
    return 1;
}
