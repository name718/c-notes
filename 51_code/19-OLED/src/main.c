#include "Com_Util.h"
#include "Int_OLED.h"

// 主函数
void main()
{
    // OLED初始化
    Int_OLED_Init();

    // 清屏
    Int_OLED_Clear();

    // 写入信息
    Int_OLED_DisplayString("How Are You?", 0, 0);
    Int_OLED_DisplayString("I`m Fine.", 0, 1);
    Int_OLED_DisplayNumber(1980, 5, 2);
    Int_OLED_DisplayNumber(-250, 5, 3);

    // 死循环
    while (1)
        ;
}
