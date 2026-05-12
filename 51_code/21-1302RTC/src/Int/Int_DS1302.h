#ifndef __INT_DS1302_H__
#define __INT_DS1302_H__

#include "Com_Util.h"
#include "Dri_3Wire.h"

// 定义相关寄存器的地址+写标识，如果读+1
#define SECOND_REG 0x80
#define MINUTE_REG 0x82
#define HOUR_REG 0x84
#define DATE_REG 0x86
#define MONTH_REG 0x88
#define DAY_REG 0x8A
#define YEAR_REG 0x8C
#define WP_REG 0x8E

// 定义表示日期的结构体
typedef struct 
{
    u8 year;
    u8 month;
    u8 day_week;
    u8 day_month;
    u8 hour;
    u8 minute;
    u8 second;
} Struct_Date;

/**
 * @brief DS1302初始化
 */
void Int_DS1302_Init();


/**
 * @brief 设置日期
 * 
 * @param date 表示日期的结构体变量
 */
void Int_DS1302_SetDate(Struct_Date date);

/**
 * @brief 获取当前的日期时间 
 * 
 * @return Struct_Date 日期时间的结构体
 */
Struct_Date Int_DS1302_GetDate();

#endif /* __INT_DS1302_H__ */