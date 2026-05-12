#include <STC89C5xRC.H>
#include <INTRINS.H>

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

// 定义数组，保存每个数字的段选信息
u8 number_codes[10] = {
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
u8 digital_buffer[8];

/**
 * @brief 延时函数，指定延时多少毫秒
 *
 * @param count 指定多少毫秒
 */
void Delayms(u16 count);

/**
 * @brief 将指定的整数设置到数码管显示缓存中（digital_buffer数组）
 * 
 * @param number 
 */
void DigitalTube_setBuffer(u32 number);

/**
 * @brief 数码管指定位置指定数字
 *
 * @param pos     位置，使用数字0~7分别表示从左边数第1到到第8个
 * @param code    数字的段选信息
 */
void DigitalTube_Single(u8 pos, u8 number_code);

/**
 * @brief 刷新数码管
 *
 */
void DigitalTube_Refresh();

// 主函数
void main()
{
    // 打开数码管开关
    P36 = 0;
    // 关闭流水灯
    P34 = 0;

    // 设置要显示的数字
     //DigitalTube_setBuffer(250);
    //DigitalTube_setBuffer(0);
    //DigitalTube_setBuffer(123456789);
    DigitalTube_setBuffer(88889999);

    // 死循环
    while (1)
    {
        DigitalTube_Refresh();
    }
}

void DigitalTube_setBuffer(u32 number)
{
    u8 i;

    // 1. 清空之前的显示内容
    for (i = 0; i < 8; i++)
    {
        digital_buffer[i] = 0x00;
    }

    // 2. 依次取出number中每位上的数，将其段选信息存储数组；最低位存入最后一个元素
    for (i = 7; ; i--)
    {
        // 取出当前位上的数,将其段选信息存入数组指定位置
        digital_buffer[i] = number_codes[number % 10];
        // 处理number，去掉最低位
        number /= 10;
        // 如果number变为0，说明数字已经取完，停止循环
        if (number == 0 || i == 0)
        {
            break;
        }
    }    


}

void DigitalTube_Single(u8 pos, u8 number_code)
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

void DigitalTube_Refresh()
{
    // 循环0到7
    u8 i;
    for (i = 0; i <= 7; i++)
    {
        DigitalTube_Single(i, digital_buffer[i]);
        Delayms(1);
    }
}

// 延时函数，指定延时多少毫秒
void Delayms(u16 count)
{
    u8 data i, j;
    while (count)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
        count--;
    }
}
