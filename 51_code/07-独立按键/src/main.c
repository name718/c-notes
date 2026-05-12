#include "Com_Util.h"
#include "Int_Key.h"

// 主函数
void main()
{

    // 死循环
    while (1)
    {
        // 按键1
        if (Int_Key_IsSW1Pressed())
        {
            P00 = ~P00;
        }

        // 按键2
        if (Int_Key_IsSW2Pressed())
        {
            P01 = ~P01;
        }

        // 按键3
        if (Int_Key_IsSW3Pressed())
        {
            P02 = ~P02;
        }

        // 按键4
        if (Int_Key_IsSW4Pressed())
        {
            P03 = ~P03;
        }
    }
}
