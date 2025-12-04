#include "i2c.h"
#include "main.h"      // pour hi2c1
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

// Dans le projet RTOS, CubeMX configure déjà I2C1 (MX_I2C1_Init)
// donc ici on ne fait… rien ou presque
void I2C1_init(uint32_t pclk_hz, uint32_t speed_hz)
{
    (void)pclk_hz;
    (void)speed_hz;
    // Optionnel : vérifier que hi2c1 est bien initialisé
    // MX_I2C1_Init() est déjà appelé dans main() avant le démarrage du scheduler.
}

bool I2C1_write(uint8_t addr7, const uint8_t *data, uint8_t len)
{
    // HAL attend l’adresse sur 8 bits (addr7 << 1)
    if (HAL_I2C_Master_Transmit(&hi2c1, addr7 << 1,
                                (uint8_t*)data, len, 100) == HAL_OK)
    {
        return true;
    }
    return false;
}

bool I2C1_read(uint8_t addr7, uint8_t *data, uint8_t len)
{
    if (HAL_I2C_Master_Receive(&hi2c1, addr7 << 1,
                               data, len, 100) == HAL_OK)
    {
        return true;
    }
    return false;
}
