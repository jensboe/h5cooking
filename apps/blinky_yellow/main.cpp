#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"
#include <stdio.h>
#include "main.hpp"

int App_Run(void)
{
    for(;;)
    {
        HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
        HAL_Delay(500);
    }
}