#include <STDIO.H>
#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"

// 主函数
void main()
{
    char temp;
    float temp1;
    char temp1_str[17];

    // 初始化OLED并清屏
    Int_OLED_Init();
    Int_OLED_Clear();

    // 死循环
    while (1)
    {
        // 发去测温命令
        temp = Int_18B20_GetTempearture();
        temp1 = Int_18B20_GetTempeartureFloat();

        // 将温度信息显示在OLED
        Int_OLED_DisplayString("Tempearture: ", 0, 0);
        
        // temp整数
        Int_OLED_DisplayNumber(temp, 0, 1);

        // 小数
        sprintf(temp1_str, "%.4f", temp1);
        Int_OLED_DisplayString(temp1_str, 0, 2);
    }
}
