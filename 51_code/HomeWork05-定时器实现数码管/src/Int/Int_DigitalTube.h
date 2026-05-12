#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__

#include "Com_Util.h"
#include "Dri_Timer0.h"

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


#endif