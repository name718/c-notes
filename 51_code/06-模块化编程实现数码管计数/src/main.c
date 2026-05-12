#include "Com_Util.h"
#include "Int_DigitalTube.h"

// 主函数
void main()
{
    // 定义变量保存数码管要显示的数字
    u8 num = 10;
    // 定义变量，死循环每循环100次，num就自减一次
    u8 i = 100;

    // 初始化数码管
    Int_DigitalTube_Init();

    // 设置初始显示的数字
    Int_DigitalTube_setBuffer(num);

    // 死循环
    while (1)
    {
        if (i == 0 && num > 0)
        {
            num--;
            i = 100;
            Int_DigitalTube_setBuffer(num);
        }
        else
        {
            i--;
        }

        // 刷新数码管
        Int_DigitalTube_Refresh();
    }
}
