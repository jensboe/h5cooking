#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"
#include <stdio.h>
#include "appmain.h"

int app_main(void)
{
    for(;;)
    {
        HAL_GPIO_TogglePin(LED3_GPIO_PORT, LED3_PIN);
        HAL_Delay(500);
    }
}