#ifndef __DRI_1WIRE_H__
#define __DRI_1WIRE_H__

#include "Com_Util.h"

#define DQ P44

/**
 * @brief 初始化
 * 
 * @return bit 从设备的回应信号
 */
bit Dri_1Wire_Init();

/**
 * @brief 向从设备写入一个字节的数据
 * 
 * @param byte 要写入的字节
 */
void Dri_1Wire_WiteByte(u8 byte);

/**
 * @brief 读取一个字节的数据
 * 
 * @return u8 读取到字节
 */
u8 Dri_1Wire_ReadByte();


#endif /* __DRI_1WIRE_H__ */