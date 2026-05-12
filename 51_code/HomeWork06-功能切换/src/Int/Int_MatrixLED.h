#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "Com_Util.h"
#include "Dri_Timer0.h"

#define SER P10
#define RCK P11
#define SCK P12

/**
 * @brief 点阵屏初始化
 * 
 */
void Int_MatrixLED_Init();

/**
 * @brief 点阵屏停止
 * 
 */
void Int_MatrixLED_Stop();


/**
 * @brief 设置点阵屏显示内容的像素信息
 * 
 * @param pixels 像素信息数组
 */
void Int_MatrixLED_SetPixels(u8 pixels[8]);


/**
 * @brief 像素信息向下滚动，最上面添加新行的内容
 * 
 * @param newline 新行的像素信息
 */
void Int_MatrixLED_ShiftPixels(u8 newline);

#endif /* __INT_MATRIXLED_H__ */