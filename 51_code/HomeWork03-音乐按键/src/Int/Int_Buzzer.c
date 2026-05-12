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


/**
 * @brief 发出500Hz提示音,更大
 * 
 * @param ms 声音持续多少毫秒
 */
void Int_Buzzer_BuzzLoud(u16 ms)
{
    while (ms)
    {
        P46 = 0;
        Delay100us(1);

        P46 = 1;
        Delay100us(19);

        ms-=2;
    }
}

/**
 * @brief 发出不同的音乐声音
 * 
 * @param ms    持续多少毫秒
 * @param type  音乐声音的类型 1~8 表示 do re mi ... do
 */
void Int_Buzzer_BuzzMusic(u16 ms, u8 type)
{
    u8 t = 0;
    u16 count;

    // 计算每次循环延时多少个10us, 根据音乐声音的类型计算
    switch (type)
    {
        case 1: t = 100000 / (400 * 2); break;
        case 2: t = 100000 / (450 * 2); break;
        case 3: t = 100000 / (506 * 2); break;
        case 4: t = 100000 / (540 * 2); break;
        case 5: t = 100000 / (600 * 2); break;
        case 6: t = 100000 / (675 * 2); break;
        case 7: t = 100000 / (759 * 2); break;
        case 8: t = 100000 / (800 * 2); break;
        default: t = 100;
    }

    // 计算需要循环多少次，根据声音持续时间和每次循环的延时计算
    count = ms * 100 / t;

    while (count)
    {
        P46 = ~P46;
        count--;
        Delay10us(t);
    }
}

