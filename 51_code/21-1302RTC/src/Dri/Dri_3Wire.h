#ifndef __DRI_3WIRE_H__
#define __DRI_3WIRE_H__

#include "Com_Util.h"

#define CE P41
#define SCLK P37
#define IO P40

/**
 * @brief 向1302写入一个字节（发送一个字节的数据）
 * 
 * @param byte 要写入的字节
 */
void Dri_3Wire_WriteByte(u8 byte);

/**
 * @brief 从1302中读取一个字节的数据（接收一个字节的数据）
 * 
 * @return u8 接收的字节
 */
u8 Dri_3Wire_ReadByte();


#endif /* __DRI_3WIRE_H__ */