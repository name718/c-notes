#include <STDIO.H>
#include "Com_Util.h"
#include "Int_OLED.h"
#include "Int_18B20.h"
#include "Int_DS1302.h"

char *weeks[7] = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

// 主函数
void main()
{
    char tmp;
    Struct_Date curr_date;
    char first_line[17];
    char second_line[17];
    // 定义结构体变量
    Struct_Date start_date = {24, 10, 1, 28, 17, 22, 55};

    // 初始化OLED并清屏
    Int_OLED_Init();
    Int_OLED_Clear();

    // 初始化1302
    Int_DS1302_Init();

    // 设置起始的时间
    Int_DS1302_SetDate(start_date);

    // 死循环
    while (1)
    {
        // 获取温度信息
        tmp = Int_18B20_GetTempearture();
        // 获取时间信息
        curr_date = Int_DS1302_GetDate();

        // 显示第一行
        sprintf(first_line, "20%02d/%02d/%02d %s", (int)curr_date.year, (int)curr_date.month, (int)curr_date.day_month, weeks[curr_date.day_week-1]);
        Int_OLED_DisplayString(first_line, 0, 0);

        // 显示第二行
        sprintf(second_line, "%02d:%02d:%02d Tmp:%d", (int)curr_date.hour, (int)curr_date.minute, (int)curr_date.second, (int)tmp);
        Int_OLED_DisplayString(second_line, 0, 1);

    }
}
