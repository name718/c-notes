#include "Dri_3Wire.h"

/**
 * @brief 向1302写入一个字节（发送一个字节的数据）
 * 
 * @param byte 要写入的字节
 */
void Dri_3Wire_WriteByte(u8 byte)
{
    u8 i;

    SCLK = 0;
    // 循环逐比特发送，先发低位，再发高位
    for (i = 0; i < 8; i++)
    {
        IO = byte & 0x01;
        SCLK = 1;

        SCLK = 0;
        byte >>= 1;
    }
}

/**
 * @brief 从1302中读取一个字节的数据（接收一个字节的数据）
 * 
 * @return u8 接收的字节
 */
u8 Dri_3Wire_ReadByte()
{
    u8 byte = 0;
    u8 i;

    // 循环，逐bit接收，先收低位，再收高位
    for (i = 0; i < 8; i++)
    {
        if (IO)
        {
           byte |= (0x01 << i); 
        }

        SCLK = 1;
        SCLK = 0;
    }

    return byte;
}