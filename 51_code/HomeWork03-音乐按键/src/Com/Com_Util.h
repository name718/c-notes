#ifndef __COM_UTIL_H__
#define __COM_UTIL_H__

#include <STC89C5xRC.H>
#include <INTRINS.H>

// 类型别名
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

/**
 * @brief 延时函数，指定延时多少毫秒
 *
 * @param count 指定多少毫秒
 */
void Delayms(u16 count);


/**
 * @brief 延时函数，指定延时多少个100微秒
 * 
 * @param count 指定多少个100微秒
 */
void Delay100us(u16 count);

/**
 * @brief 延时函数，指定延时多少个10微秒
 * 
 * @param count 指定多少个100微秒
 */
void Delay10us(u32 count);

#endif