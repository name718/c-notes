#ifndef __DRI_IIC_H__
#define __DRI_IIC_H__

#include "Com_Util.h"
#define SCL P17
#define SDA P16

/**
 * @brief 发送起始信号
 * 
 */
void Dri_IIC_Start();

/**
 * @brief 发送一个字节的数据
 * 
 * @param byte 要发送的数据
 */
void Dri_IIC_SendByte(u8 byte);

/**
 * @brief 接收确认信号
 * 
 * @return bit 返回接收到确认信号
 */
bit Dri_IIC_ReceiveACK();

/**
 * @brief 接收一个字节的数据
 * 
 * @return u8 接收到的数据
 */
u8 Dri_IIC_ReceiveByte();

/**
 * @brief 发送确认信号
 * 
 * @param ack 确认信号
 */
void Dri_IIC_SendACK(bit ack);

/**
 * @brief 发送停止信号
 * 
 */
void Dri_IIC_Stop();

#endif /* __DRI_IIC_H__ */