#include "Int_MatrixLED.h"

static u8 s_pixels[8]={0,0,0,0,0,0,0,0};

static void Int_MatrixLED_Refresh()
{
    static u8 i=0;

    P0=0xFF;

    if(i==0)
    {
        SER=1;
    
    }
    else
    {
        SER=0;
    }

    SCK=0;  
    SCK=1;

    RCK=0;
    RCK=1;

    P0=~s_pixels[i];

    i++;
    if(i==8)
    {
        i=0;
    }
}

void Int_MatrixLED_Init()
{
    P34 =0;
    P36=1;
    P35=0;

    Dri_Timer0_Init();
    Dri_Timer0_RegisterCallback(Int_MatrixLED_Refresh);
}

void Int_MatrixLED_SetPixels(u8 pixels[8])
{
    u8 i;
    for(i=0;i<8;i++)
    {
        s_pixels[i]=pixels[i];
    }
}