#include "Com_Util.h"
#include "Dri_UART.h"

// 主函数
void main()
{
    // 定义字符保存接收的数据
    char ch;

    // 初始化UART串口
    Dri_UART_Init();

    // 死循环
    while (1)
    {
        // 如果接收到数据
        if (Dri_UART_ReceiveChar(&ch))
        {
            if (ch == 'A')
            {
                P0 = 0x00;
                Dri_UART_TransmitChar('O');
                Dri_UART_TransmitChar('N');
            }
            else if (ch == 'B')
            {
                P0 = 0xFF;
                Dri_UART_TransmitChar('O');
                Dri_UART_TransmitChar('F');
                Dri_UART_TransmitChar('F');
            }
            else
            {
                P07 = ~P07;
                Dri_UART_TransmitChar('E');
                Dri_UART_TransmitChar('r');
                Dri_UART_TransmitChar('r');
                Dri_UART_TransmitChar('o');
                Dri_UART_TransmitChar('r');
            }
        }
    }
}
