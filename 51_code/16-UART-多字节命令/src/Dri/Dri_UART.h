#ifndef __DRI_UART_H__
#define __DRI_UART_H__

#include "Com_Util.h"

/**
 * @brief UART 初始化
 * 
 */
void Dri_UART_Init();

/**
 * @brief 接收单个字节数据
 * 
 * @param ch 将接收到的单字节数据存入该地址
 * @return bit 1表示接收成功 0表示接收失败
 */
bit Dri_UART_ReceiveChar(char *ch);


/**
 * @brief 接收多个字节数据（多字节指令），换行作为指令结束符
 * 
 * @param str 将接收到的多个字节的数据存入该字符串中
 * @return bit 1表示接收成功 0表示接收失败
 */
bit Dri_UART_ReceiveStr(char *str);

/**
 * @brief 发送单个字节数据
 * 
 * @param ch 要发送的数据
 */
void Dri_UART_TransmitChar(char ch);

/**
 * @brief 发送多个字节的数据
 * 
 * @param str 要发送的字符串
 */
void Dri_UART_TransmitStr(char *str);



#endif /* __DRI_UART_H__ */