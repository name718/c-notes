#include "Com_Util.h"
#include "Int_MatrixLED.h"
#include "Int_EEPROM.h"

// 主函数
void main()
{
    // u8 i = 0;
    // u8 picture[26] = {0xF8, 0x0A, 0xEC, 0xAF, 0xEC, 0x8A, 0xF8, 0x00,
    //                   0x10, 0xF9, 0x97, 0xF1, 0x88, 0xAA, 0xFF, 0xAA,
    //                   0x88, 0x00, 0x14, 0x0A, 0xF5, 0x92, 0x92, 0xF5,
    //                   0x0A, 0x14};

    // 将 pictur中的数据写入EEPROM
    // Int_EEPROM_WriteBytes(0, picture, 26);

    u8 i = 0;
    u8 picture[26];

    // 从EEPROM中读取数据存入 pricture
    Int_EEPROM_ReadBytes(0, picture, 26);

    // 点阵屏初始化
    Int_MatrixLED_Init();

    // 死循环
    while (1)
    {
        if (i < 26)
        {
            Int_MatrixLED_ShiftPixels(picture[i]);
        }
        else
        {
            Int_MatrixLED_ShiftPixels(0x00);        // 移入空行
        }

        i++;
        if (i == 34)
        {
            i = 0;
        }

        Delayms(200);
    }
}
