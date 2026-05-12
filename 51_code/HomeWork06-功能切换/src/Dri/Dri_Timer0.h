#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include <STDIO.H>
#include "Com_Util.h"

// 定义Timer0最多可注册回调函数的数量
#define MAX_CALLBACK_COUNT 4

// 给函数指针类型取别名
typedef void (*Timer0_Callback)(void);

/**
 * @brief 定时器0初始化
 */
void Dri_Timer0_Init();

/**
 * @brief 注册定时器0的回调函数
 * 
 * @param cb 回调函数的地址
 * @return 1表示注册成功，0表示注册失败
 */
bit Dri_Timer0_RegisterCallback(Timer0_Callback cb);

/**
 * @brief 解除指定的定时器0的回调函数
 * 
 * @param cb 要解除回调函数的地址
 * @return 1表示解除注册成功，0表示解除注册失败
 */
bit Dri_Timer0_DeregisterCallback(Timer0_Callback cb);

#endif /* __DRI_TIMER0_H__ */