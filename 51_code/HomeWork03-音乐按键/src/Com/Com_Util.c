#include "Com_Util.h"

// 延时函数，指定延时多少毫秒
void Delayms(u16 count)
{
    u8 data i, j;
    while (count)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
        count--;
    }
}

/**
 * @brief 延时函数，指定延时多少个100微秒
 *
 * @param count 指定多少个100微秒
 */
void Delay100us(u16 count)
{
    unsigned char data i;

    while (count)
    {
        _nop_();
        i = 43;
        while (--i)
            ;
        count--;
    }
}

/**
 * @brief 延时函数，指定延时多少个10微秒
 *
 * @param count 指定多少个100微秒
 */
void Delay10us(u32 count)
{
    unsigned char data i;

    while (count)
    {
        i = 2;
        while (--i)
            ;
        count--;
    }
}
