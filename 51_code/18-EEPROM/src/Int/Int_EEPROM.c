#include "Int_EEPROM.h"

// 将数据写入到一个页中
static bit Int_EEPROM_WriteIntoPage(u8 address, u8 *bytes, u8 len)
{
    u8 i;
    bit ack = 0;

    // 发送起始信号
    Dri_IIC_Start();

    // 发送从设备地址和写标识并接收应答信号
    Dri_IIC_SendByte(DEV_ADDR);
    ack |= Dri_IIC_ReceiveACK();

    // 发送EEPROM内部的字地址(存储单元的地址)并接收应答信号
    Dri_IIC_SendByte(address);
    ack |= Dri_IIC_ReceiveACK();

    // 循环，逐个字节发送
    for (i = 0; i < len; i++)
    {
        Dri_IIC_SendByte(bytes[i]);
        ack |= Dri_IIC_ReceiveACK();
    }

    // 发送结束信号
    Dri_IIC_Stop();

    return ack;
}

/**
 * @brief 写入指定位置指定长度的多个字节数据
 *
 * @param address EEPROM内部的字地址
 * @param bytes   要写入的多个字节（字符数组）
 * @param len     要写入的字节数
 * @return bit    0表示所有步骤都逐设备都接收到ACK确认信号； 1表示某一步接收到了NACK信号
 */
bit Int_EEPROM_WriteBytes(u8 address, u8 *bytes, u8 len)
{
    bit ack = 0;
    u8 page_remain;

    while (len > 0)
    {
        // 计算当前页所剩的存储单元个数
        page_remain = PAGE_SIZE - address % PAGE_SIZE;

        // 判断当前页空间是否足够
        if (len > page_remain) // 当前页空间不够，需要分多个页写入 ----------
        {
            // 先写入当前页
            ack |= Int_EEPROM_WriteIntoPage(address, bytes, page_remain);
            // 地址后移
            address += page_remain;
            // bytes指针后移
            bytes += page_remain;
            // len减去已经写入的个数
            len -= page_remain;

            // 延时3ms，EEPROM的写周期
            Delayms(3);
        }
        else // 当前页空间足够，只需写入到一页中 ------------------------------
        {
            ack |= Int_EEPROM_WriteIntoPage(address, bytes, len);
            len = 0;
        }
    }

    return ack;
}

/**
 * @brief 读取指定位置指定长度的字节数据
 *
 * @param address EEPROM内部的字地址
 * @param bytes   要读取到字节逐个放入该地址
 * @param len     要读取的长度
 * @return bit    0表示所有步骤都逐设备都接收到ACK确认信号； 1表示某一步接收到了NACK信号
 */
bit Int_EEPROM_ReadBytes(u8 address, u8 *bytes, u8 len)
{
    bit ack = 0;
    u8 i;

    // 伪写，设置EEPROM的地址寄存器 ------------------------------------------
    // 起始信号
    Dri_IIC_Start();

    // 发送从设备地址和写标志位并接收应答信号
    Dri_IIC_SendByte(DEV_ADDR);
    ack |= Dri_IIC_ReceiveACK();

    // 发送要读取的位置地址(EEPROM的内部地址)并接收应答信号
    Dri_IIC_SendByte(address);
    ack |= Dri_IIC_ReceiveACK();

    // 正式读 ---------------------------------------------------------------
    // 起始信号
    Dri_IIC_Start();

    // 发送从设备地址和读标志位并接收应答信号
    Dri_IIC_SendByte(DEV_ADDR + 1);
    ack |= Dri_IIC_ReceiveACK();

    // 循环，逐字节接收数据
    for (i = 0; i < len; i++)
    {
        // 接收一个字节数据
        bytes[i] = Dri_IIC_ReceiveByte();
        // 发送应答信号, 其他是1，最后一次是1
        Dri_IIC_SendACK(i == (len - 1) ? 1 : 0);
    }

    // 发送停止信号
    Dri_IIC_Stop();

    return ack;
}