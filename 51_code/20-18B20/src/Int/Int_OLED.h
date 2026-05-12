#ifndef __INT_OLED_H__
#define __INT_OLED_H__

#include "Com_Util.h"
#include "Dri_IIC.h"

// 设备地址 0111100 + 写标志 0
#define OLED_ADDR 0x78


/**
 * @brief OLED初始化
 * 
 */
void Int_OLED_Init();

/**
 * @brief 清屏
 * 
 */
void Int_OLED_Clear();

/**
 * @brief 在指定位置显示指定的字符串
 * 
 * @param str 字符串 
 * @param x   x坐标位置
 * @param y   y坐标位置
 */
void Int_OLED_DisplayString(u8 *str, u8 x, u8 y);

/**
 * @brief 在指定位置显示指定的数字
 * 
 * @param num   数字
 * @param x     x坐标位置
 * @param y     y坐标位置
 */     
void Int_OLED_DisplayNumber(long num, u8 x, u8 y);

#endif /* __INT_OLED_H__ */