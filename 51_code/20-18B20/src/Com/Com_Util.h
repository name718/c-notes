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

// 延时10us
void Delay10us(void);

// 延时60us
void Delay60us(void);

// 延时480us
void Delay480us(void);

void Delay50us(void);	//@11.0592MHz

#endif