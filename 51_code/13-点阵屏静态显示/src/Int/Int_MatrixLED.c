#include "Int_MatrixLED.h"

// 定义数组存储显示内容的像素信息
static u8 s_pixels[8] = {0, 0, 0, 0, 0, 0, 0, 0};


// 对点阵屏行扫描
static void Int_MatrixLED_Refresh()
{
    static u8 i = 0;

    // 清除上次显示
    P0 = 0xFF;

    // 595 SER引脚 第一行输入1，其他行输入0
    if (i == 0)
    {
        SER = 1;
    }
    else
    {
        SER = 0;
    }

    // 将SER输入的输入存入移位寄存器并让之前的数据后移 SCK上升沿
    SCK = 0;
    SCK = 1;

    // 将移位寄存器数据放入存储寄存器（对外输出） RCK上升沿
    RCK = 0;
    RCK = 1;

    // 设置P0引脚，该行的每列的信息
    P0 = ~s_pixels[i];

    i++;
    if (i == 8)
    {
        i = 0;
    }
}

/**
 * @brief 点阵屏初始化
 *
 */
void Int_MatrixLED_Init()
{
    // 关闭流水灯
    P34 = 0;
    // 关闭数码管
    P36 = 1;
    // 打开点阵屏
    P35 = 0;

    // 初始化Timer0
    Dri_Timer0_Init();

    // 给Timer0注册回调
    Dri_Timer0_RegisterCallback(Int_MatrixLED_Refresh);
}

/**
 * @brief 设置点阵屏显示内容的像素信息
 *
 * @param pixels 像素信息数组
 */
void Int_MatrixLED_SetPixels(u8 pixels[8])
{
    u8 i;
    for (i = 0; i < 8; i++)
    {
        s_pixels[i] = pixels[i];
    }
}