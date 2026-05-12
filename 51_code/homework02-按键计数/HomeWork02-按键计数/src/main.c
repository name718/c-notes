#include "Com_Util.h"
#include "Int_Key.h"
#include "Int_DigitalTube.h"

// 主函数
void main()
{
    // 定义需要计数的数字
    u32 num = 0;

    // 数码管初始化
    Int_DigitalTube_Init();

    // 设置数码管初始显示内容
    Int_DigitalTube_setBuffer(num);

    // 死循环
    while (1)
    {
        // 判断SW1是否触发  自增
        if (Int_Key_IsSW1Pressed())
        {
            if (num < 99999999)
            {
                num++;
                Int_DigitalTube_setBuffer(num);
            }
        }

        // 判断SW2是否触发  自减
        if (Int_Key_IsSW2Pressed())
        {
            if (num > 0)
            {
                num--;
                Int_DigitalTube_setBuffer(num);
            }
        }

        // 判断SW3是否触发 归零
        if (Int_Key_IsSW3Pressed())
        {
            num = 0;
            Int_DigitalTube_setBuffer(num);
        }

        // 判断SW4是否触发 设置成最大值
        if (Int_Key_IsSW4Pressed())
        {
            num = 99999999;
            Int_DigitalTube_setBuffer(num);
        }

        // 数码管刷新显示
        Int_DigitalTube_Refresh();
    }
}
