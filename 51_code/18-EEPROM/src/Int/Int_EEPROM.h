#ifndef __INT_EEPROM_H__
#define __INT_EEPROM_H__

#include "Com_Util.h"
#include "Dri_IIC.h"

#define DEV_ADDR 0xA0      // 0b10100000  默认是写，+1表示读
#define PAGE_SIZE 16       // 每个Page有多个字

/**
 * @brief 写入指定位置指定长度的多个字节数据
 * 
 * @param address EEPROM内部的字地址
 * @param bytes   要写入的多个字节（字符数组）  
 * @param len     要写入的字节数
 * @return bit    0表示所有步骤都逐设备都接收到ACK确认信号； 1表示某一步接收到了NACK信号
 */
bit Int_EEPROM_WriteBytes(u8 address, u8 *bytes, u8 len);


/**
 * @brief 读取指定位置指定长度的字节数据
 * 
 * @param address EEPROM内部的字地址
 * @param bytes   要读取到字节逐个放入该地址
 * @param len     要读取的长度
 * @return bit    0表示所有步骤都逐设备都接收到ACK确认信号； 1表示某一步接收到了NACK信号
 */
bit Int_EEPROM_ReadBytes(u8 address, u8 *bytes, u8 len);


#endif /* __INT_EEPROM_H__ */