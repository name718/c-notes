#include "Com_Util.h"
#include "Int_DigitalTube.h"

// 主函数
void main()
{

    // 初始化数码管
    Int_DigitalTube_Init();

    // 设置要显示的数字
    Int_DigitalTube_setBuffer(12345);
                    

    // 死循环
    while (1)
        ;
}
