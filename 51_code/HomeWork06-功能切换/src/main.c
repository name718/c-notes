#include "Com_Util.h"
#include "Dri_Timer0.h"
#include "Int_FlowLed.h"
#include "Int_DigitalTube.h"
#include "Int_MatrixLED.h"
#include "Int_Key.h"

// 主函数
void main()
{
    // 定义点阵屏的显示内容
    u8 led_pixels[8] = {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};

    // 初始化Timer0
    Dri_Timer0_Init();

    // 设置数码管的显示内容
    Int_DigitalTube_setBuffer(20241023);
    // 设置点阵屏的显示内容
    Int_MatrixLED_SetPixels(led_pixels);

    // 死循环
    while (1)
    {
        // 如果按键 SW1 触发， 启动流水灯
        if (Int_Key_IsSW1Pressed())
        {
            Int_DigitalTube_Stop();
            Int_MatrixLED_Stop();
            Int_FlowLed_Init();
        }

        // 如果按键 SW2 触发， 启动数码管
        if (Int_Key_IsSW2Pressed())
        {
            Int_FlowLed_Stop();
            Int_MatrixLED_Stop();
            Int_DigitalTube_Init();
        }

        // 如果按键 SW3 触发， 启动点阵屏
        if (Int_Key_IsSW3Pressed())
        {
            Int_FlowLed_Stop();
            Int_DigitalTube_Stop();
            Int_MatrixLED_Init();
        }
    }
}
