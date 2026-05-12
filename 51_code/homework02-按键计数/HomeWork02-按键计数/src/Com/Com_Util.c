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