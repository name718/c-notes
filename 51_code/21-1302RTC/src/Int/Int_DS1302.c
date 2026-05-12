#include "Int_DS1302.h"

// 设置寄存器的值,写入
static void Int_DS1302_SetRegValue(addr, u8 value)
{
    // 打开读写使能
    CE = 1;

    // 写入控制字节
    Dri_3Wire_WriteByte(addr);
    // 写入数据字节
    Dri_3Wire_WriteByte(value);

    // 关闭读写使能
    CE = 0;
}

// 读取寄存器的值,返回读取的寄存器值
static u8 Int_DS1302_GetRegValue(addr)
{
    u8 value;

    // 打开读写使能
    CE = 1;

    // 写入控制字节
    Dri_3Wire_WriteByte(addr);
    // 读取数据字节
    value = Dri_3Wire_ReadByte();

    // 关闭读写使能
    CE = 0;

    return value;
}

/**
 * @brief DS1302初始化
 */
void Int_DS1302_Init()
{
    CE = 0;
    SCLK = 0;
    IO = 0;
}

/**
 * @brief 设置日期
 *
 * @param date 表示日期的结构体变量
 */
void Int_DS1302_SetDate(Struct_Date date)
{
    // 关闭写保护
    Int_DS1302_SetRegValue(WP_REG, 0x00);

    // 将秒信号写入寄存器
    Int_DS1302_SetRegValue(SECOND_REG, ((date.second / 10) << 4) | (date.second % 10));
    // 将分钟信号写入寄存器
    Int_DS1302_SetRegValue(MINUTE_REG, ((date.minute / 10) << 4) | (date.minute % 10));
    // 将小时信号写入寄存器
    Int_DS1302_SetRegValue(HOUR_REG, ((date.hour / 10) << 4) | (date.hour % 10));
    // 将每月几号信号写入寄存器
    Int_DS1302_SetRegValue(DATE_REG, ((date.day_month / 10) << 4) | (date.day_month % 10));
    // 将星期几信号写入寄存器
    Int_DS1302_SetRegValue(DAY_REG, date.day_week);
    // 将月信息写入寄存器
    Int_DS1302_SetRegValue(MONTH_REG, ((date.month / 10) << 4) | (date.month % 10));
    // 将年信息写入寄存器
    Int_DS1302_SetRegValue(YEAR_REG, ((date.year / 10) << 4) | (date.year % 10));

    // 打开写保护
    Int_DS1302_SetRegValue(WP_REG, 0x80);
}

/**
 * @brief 获取当前的日期时间
 *
 * @return Struct_Date 日期时间的结构体
 */
Struct_Date Int_DS1302_GetDate()
{
    // 定义结构体变量
    Struct_Date date;
    u8 temp;

    // 年
    temp = Int_DS1302_GetRegValue(YEAR_REG + 1);
    date.year = (temp >> 4) * 10 + (temp & 0x0F);

    // 月
    temp = Int_DS1302_GetRegValue(MONTH_REG + 1);
    date.month = (temp >> 4) * 10 + (temp & 0x0F);

    // 日（每月第几天）
    temp = Int_DS1302_GetRegValue(DATE_REG + 1);
    date.day_month = (temp >> 4) * 10 + (temp & 0x0F);

    // 星期几
    temp = Int_DS1302_GetRegValue(DAY_REG + 1);
    date.day_week = temp;

    // 时
    temp = Int_DS1302_GetRegValue(HOUR_REG + 1);
    date.hour = (temp >> 4) * 10 + (temp & 0x0F);

    // 分钟
    temp = Int_DS1302_GetRegValue(MINUTE_REG + 1);
    date.minute = (temp >> 4) * 10 + (temp & 0x0F);

    // 秒
    temp = Int_DS1302_GetRegValue(SECOND_REG + 1);
    date.second = (temp >> 4) * 10 + (temp & 0x0F);

    return date;
}
