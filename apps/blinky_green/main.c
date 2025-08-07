#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"
#include <stdio.h>
#include "appmain.h"

int App_Run(void)
{
    for(;;)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_PIN);
        HAL_Delay(500);
    }
}