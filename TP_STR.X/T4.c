#include "T4.h"

void write_to_serial()
{
    
}

void write_title()
{
        while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='A';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='H';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='4';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='N';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='O';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='U';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='R';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='S';while (TXSTA1bits.TRMT==0);    
}

void new_line()
{
        //New line
        while (PIR1bits.TX1IF==0);   TXREG1=0x0A;while (TXSTA1bits.TRMT==0);
        //Carriage return
        while (PIR1bits.TX1IF==0);   TXREG1=0x0d;while (TXSTA1bits.TRMT==0);   
}

void clear_term()
{
    unsigned int b;
    for (b=0;b<25;b++)
        new_line();
    ;
}

void data()
{
    while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='a';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='u';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='=';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1=eauReel;while (TXSTA1bits.TRMT==0);
    new_line();
    
    while (PIR1bits.TX1IF==0);   TXREG1='T';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='h';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='u';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='l';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='=';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1=huileReel;while (TXSTA1bits.TRMT==0);
    new_line();
    
    while (PIR1bits.TX1IF==0);   TXREG1='V';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='s';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='s';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='=';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1=vitesseReel;while (TXSTA1bits.TRMT==0);
    new_line();
    
    while (PIR1bits.TX1IF==0);   TXREG1='B';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='a';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='r';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='=';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1=batterieReel;while (TXSTA1bits.TRMT==0);
    new_line();

    while (PIR1bits.TX1IF==0);   TXREG1='U';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='l';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='s';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='a';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='i';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='o';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='n';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1='=';while (TXSTA1bits.TRMT==0);
    while (PIR1bits.TX1IF==0);   TXREG1=machine_use_time;while (TXSTA1bits.TRMT==0);
    new_line();
}

void tache4()
{
    unsigned int a;
    while(1)
    {
        P(SEM_RXTX);
        while(RXTX_libre==0);
        RXTX_libre=0;

        clear_term();
        write_title();
        new_line();
        data();
                
        RXTX_libre=1;
        V(SEM_RXTX);
        for (a=0;a<65000;a++)
            ;
        for (a=0;a<65000;a++)
            ;
    }
}
