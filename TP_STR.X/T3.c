#include "T3.h"

void tache3()
{
    while(1)
    {
        if (TP_appui==1)
        {
            if ((TP_x>=203)&&(TP_x<209))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_R=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_R=0;
                }
            }
        }
        if (TP_appui==1)
        {
            if ((TP_x>=215)&&(TP_x<221))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_G=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_G=0;
                }
            }
        }
        if (TP_appui==1)
        {
            if ((TP_x>=227)&&(TP_x<233))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_B=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_B=0;
                }
            }
        }
        
        //Alarms
        if (TP_appui==1)
        {
            if ((TP_x>=200)&&(TP_x<210))
            {
                if ((TP_y>=20)&&(TP_y<30))
                {
                    alarme_pannel=~alarme_pannel;
                }
            }
        }
        
    }
    
}