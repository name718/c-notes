#include "Int_FlowLed.h"

/**
 * @brief 流水灯刷新
 *
 */
static void Int_FlowLed_Refresh()
{
    static u8 count = 100;
    static u8 temp = 0x01; // 0b 0000 0001

    // 每一轮的开始LED处理， 100ms一轮，开始的时候count是100
    if (count == 100)
    {
        P0 = ~temp;
        temp <<= 1;
        // 如果移没了(00000000)，从头再来
        if (temp == 0x00)
        {
            temp = 0x01;
        }
    }

    count--;
    if (count == 0)
    {
        count = 100;
    }
}

/**
 * @brief 流水灯初始化
 *
 */
void Int_FlowLed_Init()
{
    // 打开流水灯开关
    P34 = 1;
    // 给Timer0注册回调
    Dri_Timer0_RegisterCallback(Int_FlowLed_Refresh);
}

/**
 * @brief 流水灯停止
 * 
 */
void Int_FlowLed_Stop()
{
    // 关闭流水灯开关
    P34 = 0;
    // 接触Timer0回调函数的注册
    Dri_Timer0_DeregisterCallback(Int_FlowLed_Refresh);
}


