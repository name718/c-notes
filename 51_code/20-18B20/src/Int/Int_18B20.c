#include "Int_18B20.h"

/**
 * @brief 获取测量的温度
 *
 * @return char 测量的温度
 */
char Int_18B20_GetTempearture()
{
    u8 ls_byte;
    u8 ms_byte;

    // 1. 让18B20测温 ---------------------------------------------------------
    // 初始化
    Dri_1Wire_Init();
    // ROM命令：跳过
    Dri_1Wire_WiteByte(0xCC);
    // 发送测温命令，让18b20将测温结果存入暂存器
    Dri_1Wire_WiteByte(0x44);

    // 2. 读取18B20温度暂存器中的值（上次的测温结果）-------------------------------
    // 初始化
    Dri_1Wire_Init();
    // ROM命令：跳过
    Dri_1Wire_WiteByte(0xCC);
    // 发送读暂存器命令，读取测温结果
    Dri_1Wire_WiteByte(0xBE);

    // 接收数据
    ls_byte = Dri_1Wire_ReadByte();
    ms_byte = Dri_1Wire_ReadByte();

    // 处理温度信息
    return (ms_byte << 4) | (ls_byte >> 4);
}


/**
 * @brief 获取测量的温度
 *
 * @return char 测量的温度(浮点数)
 */
float Int_18B20_GetTempeartureFloat()
{
    u8 ls_byte;
    u8 ms_byte;

    // 1. 让18B20测温 ---------------------------------------------------------
    // 初始化
    Dri_1Wire_Init();
    // ROM命令：跳过
    Dri_1Wire_WiteByte(0xCC);
    // 发送测温命令，让18b20将测温结果存入暂存器
    Dri_1Wire_WiteByte(0x44);

    // 2. 读取18B20温度暂存器中的值（上次的测温结果）-------------------------------
    // 初始化
    Dri_1Wire_Init();
    // ROM命令：跳过
    Dri_1Wire_WiteByte(0xCC);
    // 发送读暂存器命令，读取测温结果
    Dri_1Wire_WiteByte(0xBE);

    // 接收数据
    ls_byte = Dri_1Wire_ReadByte();
    ms_byte = Dri_1Wire_ReadByte();

    // 处理温度信息
    return ((ms_byte << 4) | (ls_byte >> 4)) + (ls_byte & 0x0F) * 0.0625; 
}