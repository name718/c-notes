#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "Com_Util.h"

/**
 * @brief 发出500Hz提示音
 * 
 * @param ms 声音持续多少毫秒
 */
void Int_Buzzer_Buzz(u16 ms);

/**
 * @brief 发出500Hz提示音,更大
 * 
 * @param ms 声音持续多少毫秒
 */
void Int_Buzzer_BuzzLoud(u16 ms);


/**
 * @brief 发出不同的音乐声音
 * 
 * @param ms    持续多少毫秒
 * @param type  音乐声音的类型 1~8 表示 do re mi ... do
 */
void Int_Buzzer_BuzzMusic(u16 ms, u8 type);

#endif