#include "Com_Util.h"
#include "Dri_Timer0.h"

// LED1 每隔1s 亮灭一次
void cb1()
{
    static u16 count = 1000;
    count--;
    if (count == 0)
    {
        P00 = ~P00;
        count = 1000;
    }
}

// LED5 每隔 0.1s 亮灭一次
void cb2()
{
    static u16 count = 100;
    count--;
    if (count == 0)
    {
        P04 = ~P04;
        count = 100;
    }
}

// 500HZ 声音
void cb3()
{
    P46 = ~P46;
}


// 主函数
void main()
{
    // 初始化Timer0
    Dri_Timer0_Init();

    // 注册回调函数
    Dri_Timer0_RegisterCallback(cb1);
    Dri_Timer0_RegisterCallback(cb2);
    Dri_Timer0_RegisterCallback(cb3);


    // 3s 之后，蜂鸣器不响
    Delayms(3000);
    Dri_Timer0_DeregisterCallback(cb3);

    // 死循环
    while (1)
        ;
}
