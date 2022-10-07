#include "T2.h"

void tache2()
{
    unsigned char hx,lx,hy,ly;
    unsigned int ix,iy;

    TP_appui=0;

    while(1)
    {
        DRIVEA=1;// Right=Vcc Left=GND Top en l'air
        DRIVEB=0;// Bottom en l'air
        tp_delai(3000);// Délai d'établissement du signal ~= 3000 us

        //P(SEM_CAN);

        ADCON2=0x16; // Fosc/64 Tacq=4TAD
        ADCON0=0x01; // Module AD ON channel 0 (X)
        ADCON0=0x03; //Début de conversion
        while(ADCON0bits.DONE==1)
            ;
        hx=ADRESH;
        lx=ADRESL;

        //V(SEM_CAN);

        if ((lx&0x0F)!=0){hx=0;lx=0;}// Si tension négative


        if (hx>=10)
        {
            DRIVEA=0;// Right en l'air Left en l'air Top=Vcc
            DRIVEB=1;// Bottom=GND
            tp_delai(3000);// Délai d'établissement du signal ~= 3000 us

            //P(SEM_CAN);

            ADCON2=0x16; // Fosc/64 Tacq=4TAD
            ADCON0=0x05; // Module AD ON channel 1 (Y)
            ADCON0=0x07; //Début de conversion
            while(ADCON0bits.DONE==1)
                ;
            hy=ADRESH;
            ly=ADRESL;

            //V(SEM_CAN);

            if ((ly&0x0F)!=0){hy=0;ly=0;}// Si tension négative

            if (hy>=20)
            {
                ix=lx+(((unsigned int)(hx))<<8);
                iy=ly+(((unsigned int)(hy))<<8);
                ix=ix-3150; // Offset
                iy=iy-6500; // Offset

                TP_x=ix/246; //Gain X
                TP_y=127-(iy/409); //Gain Y

//                hx=hx-15;
//                hy=hy-26;
//                hx=(unsigned char)(hx*1.053); // transformation de
//                hy=(unsigned char)(hy*1.255);
//                hy=127-(hy>>1);
//                TP_x=hx;
//                TP_y=hy;
                TP_appui=1;
            }
            else
            {
                TP_appui=0;
            }
        }
        else
        {
            TP_appui=0;
        }
        
        
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
        
        //Detection des appuis
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
            if ((TP_x>=190)&&(TP_x<210))
            {
                if ((TP_y>=10)&&(TP_y<30))
                {
                    alarme_pannel=~alarme_pannel;
                    int a=0;
                    //Slow down the reading for double touches
                    for (a=0;a<100;a++)
                    ;
                }
            }
        }
        
        
    }
}

void tp_delai(unsigned int itpd)
{
    while(itpd>0) //la boucle dure 12 cycles machines
    {
        Nop();Nop();Nop();
        itpd--;
    }
}