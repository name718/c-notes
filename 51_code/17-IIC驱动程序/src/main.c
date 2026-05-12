#include "Com_Util.h"
#include "Dri_IIC.h"
#include "Int_Key.h"

// 主函数
void main()
{
    // 发送起始信号
    // Dri_IIC_Start();

    // 发送一个字节数据（从设备的地址和读写标志） 0b 1010 1010
    // Dri_IIC_SendByte(0xAA);
    // Dri_IIC_ReceiveACK();

    // 死循环
    while (1)
    {
        if (Int_Key_IsSW1Pressed())
        {
            // 发送起始信号
            Dri_IIC_Start();

            // 发送一个字节数据（从设备的地址和读写标志） 0b 1010 1010
            Dri_IIC_SendByte(0xAA);
            Dri_IIC_ReceiveACK();
        }
    }
}
