#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__

#include "Com_Util.h"

/**
 * @brief 数码管初始化
 */
void Int_DigitalTube_Init();

/**
 * @brief 将指定的整数设置到数码管显示缓存中（digital_buffer数组）
 * 
 * @param number 
 */
void Int_DigitalTube_setBuffer(u32 number);

/**
 * @brief 数码管指定位置指定数字
 *
 * @param pos     位置，使用数字0~7分别表示从左边数第1到到第8个
 * @param code    数字的段选信息
 */
void Int_DigitalTube_Single(u8 pos, u8 number_code);

/**
 * @brief 刷新数码管
 *
 */
void Int_DigitalTube_Refresh();

#endif