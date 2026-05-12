#include "Int_Buzzer.h"

/**
 * @brief 发出500Hz提示音
 *
 * @param ms 声音持续多少毫秒
 */
void Int_Buzzer_Buzz(u16 ms)
{
    while (ms)
    {
        P46 = ~P46;
        ms--;
        Delayms(1);
    }
}