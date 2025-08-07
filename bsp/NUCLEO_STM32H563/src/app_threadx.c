#include "app_threadx.h"

#include "main.h"
#include "stm32h5xx_nucleo.h"

TX_THREAD ThreadOne;
TX_THREAD ThreadTwo;
TX_EVENT_FLAGS_GROUP EventFlag;

void ThreadOne_Entry(ULONG thread_input);
void ThreadTwo_Entry(ULONG thread_input);

UINT App_ThreadX_Init(VOID *memory_ptr)
{
    UINT ret = TX_SUCCESS;
    TX_BYTE_POOL *byte_pool = (TX_BYTE_POOL *)memory_ptr;
    CHAR *pointer;

    if (tx_byte_allocate(byte_pool, (VOID **)&pointer, 512, TX_NO_WAIT) != TX_SUCCESS)
    {
        return TX_POOL_ERROR;
    }
    if (tx_thread_create(&ThreadOne, "Thread One", ThreadOne_Entry, 0, pointer, 512, 10, 10, TX_NO_TIME_SLICE, TX_AUTO_START) != TX_SUCCESS)
    {
        return TX_THREAD_ERROR;
    }

    if (tx_byte_allocate(byte_pool, (VOID **)&pointer, 512, TX_NO_WAIT) != TX_SUCCESS)
    {
        return TX_POOL_ERROR;
    }

    if (tx_thread_create(&ThreadTwo, "Thread Two", ThreadTwo_Entry, 0, pointer, 512, 9, 9, TX_NO_TIME_SLICE, TX_AUTO_START) != TX_SUCCESS)
    {
        return TX_THREAD_ERROR;
    }

    return ret;
}


void ThreadOne_Entry(ULONG thread_input)
{
    (void)thread_input;
    while (1)
    {
        HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_PIN);
        tx_thread_sleep(100);
    }
}
void ThreadTwo_Entry(ULONG thread_input)
{
    (void)thread_input;
    while (1)
    {
        HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
        tx_thread_sleep(130);
    }
}
