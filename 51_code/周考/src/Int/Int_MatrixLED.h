#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include"Com_Util.h"
#include"Dri_Timer0.h"

#define SER P10
#define RCK P11
#define SCK P12

void Int_MatrixLED_Init();

void Int_MatrixLED_SetPixels(u8 pixels[8]);

#endif /* __INT_MATRIXLED_H__ */