#include <STRING.H>
#include "Com_Util.h"
#include "Dri_UART.h"

// 主函数
void main()
{
    // 定义字符数组保存多字节指令
    char cmd[10];

    // 初始化UART串口
    Dri_UART_Init();

    // 死循环
    while (1)
    {
        // 如果接收到数据
        if (Dri_UART_ReceiveStr(cmd))
        {
            if (strcmp(cmd, "on") == 0)
            {
                P0 = 0x00;
                Dri_UART_TransmitStr("OK:LED is On!");
            }
            else if (strcmp(cmd, "off") == 0)
            {
                P0 = 0xFF;
                Dri_UART_TransmitStr("OK:LED is Off!");
            }
            else
            {
                P07 = ~P07;
                Dri_UART_TransmitStr("Error:Unknow Command!");
            }
        }
    }
}
