#include "Com_Util.h"
#include "Int_MatrixLED.h"

// 主函数
void main()
{

    u8 led_pixels[8]={0x18,
0x18,
0x18,
0xFF,
0xFF,
0x18,
0x18,
0x18,
};

    Int_MatrixLED_Init();
    Int_MatrixLED_SetPixels(led_pixels);
    // 死循环
    while (1)
        ;
}
