#include <STC89C5xRC.H>
#include <INTRINS.H>

typedef unsigned char u8;
typedef unsigned int u16;

void Delayms(u16 count);

// 主函数
void main()
{
    // 定义变量 二进制： 10000000
    u8 temp = 0x80;

    // 死循环
    while (1)
    {
        // 给 P0 寄存器赋值
        P0 = ~temp;

        // temp 右移1位  temp = temp << 1
        temp >>= 1;

        // 如果移没了（00000000），从头再来
        if (temp == 0x00)
        {
            temp = 0x80;
        }

        // 延时100ms
        Delayms(100);
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