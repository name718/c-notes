#include "Int_Key.h"

/**
 * @brief 判断SW1按键是否触发
 *
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW1Pressed()
{
    if (SW1 == 0)
    {
        Delayms(10);
        if (SW1 == 0)
        {
            while (SW1 == 0)
                ;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief 判断SW2按键是否触发
 *
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW2Pressed()
{
    if (SW2 == 0)
    {
        Delayms(10);
        if (SW2 == 0)
        {
            while (SW2 == 0)
                ;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief 判断SW3按键是否触发
 *
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW3Pressed()
{
    if (SW3 == 0)
    {
        Delayms(10);
        if (SW3 == 0)
        {
            while (SW3 == 0)
                ;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief 判断SW4按键是否触发
 *
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW4Pressed()
{
    if (SW4 == 0)
    {
        Delayms(10);
        if (SW4 == 0)
        {
            while (SW4 == 0)
                ;
            return 1;
        }
    }
    return 0;
}