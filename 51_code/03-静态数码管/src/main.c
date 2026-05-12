#include <STC89C5xRC.H>
#include <INTRINS.H>

typedef unsigned char u8;
typedef unsigned int u16;

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

/**
 * @brief 数码管指定位置指定数字
 *
 * @param pos     位置，使用数字0~7分别表示从左边数第1到到第8个
 * @param number  数字
 */
void DigitalTube_Single(u8 pos, u8 number);

// 主函数
void main()
{
    // 打开数码管开关
    P36 = 0;
    // 关闭流水灯
    P34 = 0;

    // 显示
    DigitalTube_Single(5, 9);

    // 死循环不让程序向下执行
    while (1)
        ;
}

void DigitalTube_Single(u8 pos, u8 number)
{
    // 1. 位选 -------------------------------
    // 1.1 pos 左移3位,  与P15、P14、P13 对齐
    pos <<= 3;
    // 1.2 将P1的P15、P14、P13三位置0，其他位保持不变， P1 & 0b1100 0111
    P1 &= 0xC7;
    // 1.3 将pos上的三位有效数, 赋值到 P15、P14、P13 位置上
    P1 |= pos;

    // 2. 段选 --------------------------------
    P0 = number_codes[number];
}

// 延时函数，指定延时多少毫秒
// void Delayms(u16 count)
// {
//     u8 data i, j;
//     while (count)
//     {
//         _nop_();
//         i = 2;
//         j = 199;
//         do
//         {
//             while (--j)
//                 ;
//         } while (--i);
//         count--;
//     }
// }
