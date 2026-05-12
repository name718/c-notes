#include "Dri_1Wire.h"

/**
 * @brief 初始化
 *
 * @return bit 从设备的回应信号
 */
bit Dri_1Wire_Init()
{
    bit result;

    // 主设备发送复位脉冲，拉低DQ，至少持续480us
    DQ = 0;
    Delay480us();

    // 主设备释放DQ，并等待60us
    DQ = 1;
    Delay60us();

    // 主设备读取从设备的存在脉冲
    result = DQ;

    // 延时至少420us，此处延时480us 也可以 （60 + 420 = 480）
    Delay480us();

    return result;
}

/**
 * @brief 向从设备写入一个字节的数据
 *
 * @param byte 要写入的字节
 */
void Dri_1Wire_WiteByte(u8 byte)
{
    u8 i;

    // 循环，逐bit发送，先发低位再发高位
    for (i = 0; i < 8; i++)
    {
        // 先拉低DQ
        DQ = 0;

        // 在15us之内向DQ发送当前bit，此处选择延时10us
        Delay10us();
        DQ = byte & 0x01; // byte将最低位赋值给DQ
        byte >>= 1;       // byte右移1位

        // 发送1bit的持续时间是 60~120us， 此处延时60us
        Delay60us();

        // 发送完1bit数据，将DQ拉高
        DQ = 1;
    }
}

/**
 * @brief 读取一个字节的数据
 *
 * @return u8 读取到字节
 */
u8 Dri_1Wire_ReadByte()
{
    u8 byte = 0;
    u8 i;
    u8 b = 0;

    // 逐bit接收，先接收低位，再接收高位
    for (i = 0; i < 8; i++)
    {
        // 主设备拉低DQ，至少持续1us
        DQ = 0;
        // 主设备释放DQ，交给从设备
        DQ = 1;

        // 主设备等待15us，从设备会在15us之内向DQ发送数据, 这里延时10us
        Delay10us();
        b = DQ;
        b <<= i;
        byte |= b;

        // 接收的过程持续60~120us
        Delay60us();

        // 读取完1个bit，拉高DQ
        DQ = 1;
    }

    return byte;
}