#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "Com_Util.h"

#define SW1 P42
#define SW2 P43
#define SW3 P32
#define SW4 P33

/**
 * @brief 判断SW1按键是否触发
 * 
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW1Pressed();


/**
 * @brief 判断SW2按键是否触发
 * 
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW2Pressed();

/**
 * @brief 判断SW3按键是否触发
 * 
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW3Pressed();

/**
 * @brief 判断SW4按键是否触发
 * 
 * @return 1表示触发，0表示未触发
 */
bit Int_Key_IsSW4Pressed();

#endif