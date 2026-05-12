#include "Int_DigitalTube.h"

// 定义数组，保存每个数字的段选信息
static u8 s_number_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

// 定义数组，8个元素，对应数码管8个位置； 每个元素存储数字的段选信息
static u8 s_digital_buffer[8];


/**
 * @brief 数码管指定位置指定数字
 *
 * @param pos     位置，使用数字0~7分别表示从左边数第1到到第8个
 * @param code    数字的段选信息
 */
static void Int_DigitalTube_Single(u8 pos, u8 number_code)
{
    // 1. 位选 -------------------------------
    // 1.1 pos 左移3位,  与P15、P14、P13 对齐
    pos <<= 3;
    // 1.2 将P1的P15、P14、P13三位置0，其他位保持不变， P1 & 0b11000111
    P1 &= 0xC7;
    // 1.3 将pos上的三位有效数, 赋值到 P15、P14、P13 位置上
    P1 |= pos;

    // 2. 段选 --------------------------------
    P0 = number_code;
}

/**
 * @brief 刷新数码管
 *
 */
static void Int_DigitalTube_Refresh()
{
    static u8 i = 0;
    Int_DigitalTube_Single(i, s_digital_buffer[i]);
    i++;
    if (i == 8)
    {
        i = 0;
    }
}


/**
 * @brief 数码管初始化
 */
void Int_DigitalTube_Init()
{
    // 打开数码管开关
    P36 = 0;
    // 关闭流水灯
    P34 = 0;

    // 初始化Timer0
    Dri_Timer0_Init();

    // 注册回调
    Dri_Timer0_RegisterCallback(Int_DigitalTube_Refresh);
}

/**
 * @brief 将指定的整数设置到数码管显示缓存中（s_digital_buffer数组）
 *
 * @param number
 */
void Int_DigitalTube_setBuffer(u32 number)
{
    u8 i;

    // 1. 清空之前的显示内容
    for (i = 0; i < 8; i++)
    {
        s_digital_buffer[i] = 0x00;
    }

    // 2. 依次取出number中每位上的数，将其段选信息存储数组；最低位存入最后一个元素
    for (i = 7;; i--)
    {
        // 取出当前位上的数,将其段选信息存入数组指定位置
        s_digital_buffer[i] = s_number_codes[number % 10];
        // 处理number，去掉最低位
        number /= 10;
        // 如果number变为0，说明数字已经取完，停止循环
        if (number == 0 || i == 0)
        {
            break;
        }
    }
}

