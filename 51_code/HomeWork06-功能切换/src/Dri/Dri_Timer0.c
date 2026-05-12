#include "Dri_Timer0.h"

// 定义函数指针数组，每个元素都是 Timer0_Callback 类型
static Timer0_Callback s_timer0_callbacks[MAX_CALLBACK_COUNT] = {NULL, NULL, NULL, NULL};

/**
 * @brief 定时器0初始化
 */
void Dri_Timer0_Init()
{
    // 1. 打开总开关和定时器0的开关
    EA = 1;
    ET0 = 1;

    // 2. 设置脉冲来源、工作模式、GATE
    TMOD &= 0xF0;
    TMOD |= 0x01; // GATE=0, C/T=0, M1、M0 = 01  16位脉冲计数器（不会自动重装载）

    // 3. 计算脉冲计数器的初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 4. 设置定时器0的优先级（使用默认）
    // 5. 开始计数
    TR0 = 1;
}

/**
 * @brief 注册定时器0的回调函数
 *
 * @param cb 回调函数的地址
 * @return 1表示注册成功，0表示注册失败
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback cb)
{
    u8 i;

    // 如果回调函数已经注册过，直接返回0
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            return 0;
        }
    }

    // 将回调函数添加到第一个不是NULL的位置
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == NULL)
        {
            s_timer0_callbacks[i] = cb;
            return 1;
        }
    }

    return 0;
}

/**
 * @brief 解除指定的定时器0的回调函数
 *
 * @param cb 要解除回调函数的地址
 * @return 1表示解除注册成功，0表示解除注册失败
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback cb)
{
    u8 i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] == cb)
        {
            s_timer0_callbacks[i] = NULL;
            return 1;
        }
    }

    return 0;
}

// 定义Timer0的中断服务程序
void Timer0_Handler() interrupt 1
{
    u8 i;

    // 重置脉冲计数器的初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;

    // 依次调用回调函数
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0_callbacks[i] != NULL)
        {
            s_timer0_callbacks[i]();
        }
    }
}
