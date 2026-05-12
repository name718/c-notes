#include "Dri_IIC.h"

/**
 * @brief 发送起始信号
 *
 */
void Dri_IIC_Start()
{
    // 确保是空闲状态
    SCL = 1;
    SDA = 1;

    // 将SDA拉低，发送起始信号
    SDA = 0;

    // 拉低时钟，方便下一步操作
    SCL = 0;
}

/**
 * @brief 发送一个字节的数据
 *
 * @param byte 要发送的数据
 */
void Dri_IIC_SendByte(u8 byte)
{
    /*
        第一次发送（最高位）：  (byte & 0b10000000) == 0 ? 0 : 1
        第二次发送（次高位）：  (byte & 0b01000000) == 0 ? 0 : 1
        第三次发送（第三高位）：  (byte & 0b0010000) == 0 ? 0 : 1
        ...
        最后一次发送(最低位)：(byte & 0b0000001) == 0 ? 0 : 1
    */
    u8 i;
    for (i = 0; i < 8; i++)
    {
        SDA = (byte & (0x80 >> i)) == 0 ? 0 : 1;
        SCL = 1;
        SCL = 0;
    }
}

/**
 * @brief 接收确认信号
 *
 * @return bit 返回接收到确认信号
 */
bit Dri_IIC_ReceiveACK()
{
    bit ack;

    // 主设备释放SDA（将其拉高）
    SDA = 1;

    // 主设备读取SDA
    SCL = 1;
    ack = SDA;

    // 拉低SCL
    SCL = 0;

    return ack;
}

/**
 * @brief 接收一个字节的数据
 *
 * @return u8 接收到的数据
 */
u8 Dri_IIC_ReceiveByte()
{
    /*
        第一次： xxxxxxxx  | SDA(a) =  xxxxxxxa
        第二次： xxxxxxa0  | SDA(b) =  xxxxxxab
        第三次： xxxxxab0  | SDA(c) =  xxxxxabc
        ...
        第八次：abcdefg0  | SDA(h) =  abcdefgh
    */

    u8 byte = 0; // 保存接收到一个字节的数据
    u8 i;

    // 主设备释放SDA（拉高）
    SDA = 1;

    // 逐比特接收数据，共接收8次，先接收高位
    for (i = 0; i < 8; i++)
    {
        SCL = 1;

        // 先byte左移1位
        byte <<= 1;
        // 将SDA放在byte目前的最低位上
        byte |= SDA;

        SCL = 0;
    }

    // 返回
    return byte;
}

/**
 * @brief 发送确认信号
 *
 * @param ack 确认信号
 */
void Dir_IIC_SendACK(bit ack)
{
    SDA = ack;
    SCL = 1;
    SCL = 0;
}

/**
 * @brief 发送停止信号
 *
 */
void Dri_IIC_Stop()
{
    SDA = 0;
    SCL = 1;
    SDA = 1;
}