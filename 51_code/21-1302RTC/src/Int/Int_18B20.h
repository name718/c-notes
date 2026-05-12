#ifndef __INT_18B20_H__
#define __INT_18B20_H__

#include "Dri_1Wire.h"

/**
 * @brief 获取测量的温度
 * 
 * @return char 测量的温度
 */
char Int_18B20_GetTempearture();


/**
 * @brief 获取测量的温度
 *
 * @return char 测量的温度(浮点数)
 */
float Int_18B20_GetTempeartureFloat();

#endif /* __INT_18B20_H__ */