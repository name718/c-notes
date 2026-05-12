#include "Com_Util.h"
#include "Int_DigitalTube.h"
#include "Int_MatrixKey.h"
#include "Int_Buzzer.h"

// 主函数
void main()
{
    u8 key;

    // 初始化数码管
    Int_DigitalTube_Init();

    // 死循环
    while (1)
    {
        // 获取哪个按键被触发了， 返回0表示没有按键被触发
        key = Int_MatrixKey_Checkkey();
        if (key)
        {
            // 设置数码管显示的数字
            Int_DigitalTube_setBuffer(key);
            // 蜂鸣器发声
            Int_Buzzer_Buzz(500);
        }

        // 刷新数码管
        Int_DigitalTube_Refresh();
    }
}


