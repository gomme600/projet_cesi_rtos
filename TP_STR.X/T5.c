#include "T5.h"

// Function to set the kth bit of n
char setBit(char n, int k)
{
    return (n | (1 << k));
}
  
// Function to clear the kth bit of n
char clearBit(char n, int k)
{
    return (n & (~(1 << k)));
}
  
// Function to toggle the kth bit of n
char toggleBit(char n, int k)
{
    return (n ^ (1 << k));
}

//Alarme

int buz=1;

void tache5()
{
    unsigned int a;
    while(1)
    {
        
        //Si personne dans siege et vitesse > 0
        if (SIEGE==1 && vitesse>0)
            alarme_active = setBit(alarme_active, 6);
            //alarme_active |= (1 << 6);
        else
            alarme_active = clearBit(alarme_active, 6);
            //alarme_active &= (0 << 6);
        
        if (n_octet_badge==0)
            alarme_active = setBit(alarme_active, 4);
            //alarme_active |= (1 << 4);
        else
            alarme_active = clearBit(alarme_active, 4);
            //alarme_active &= (0 << 4);
        
        if (CHOC==0)
            alarme_active = setBit(alarme_active, 2);
            //alarme_active |= (1 << 2);
        else
            alarme_active = clearBit(alarme_active, 2);
            //alarme_active &= (0 << 2);
        
        if (FREIN_A_MAIN==0 && vitesse>0)
            alarme_active = setBit(alarme_active, 5);
            //alarme_active |= (1 << 5);
        else
            alarme_active = clearBit(alarme_active, 5);
            //alarme_active &= (0 << 5);
        
        if (lecture_8bit_analogique(TEMPERATURE_EAU)>200)
            alarme_active = setBit(alarme_active, 0);
            //alarme_active |= (1 << 0);
        else
            alarme_active = clearBit(alarme_active, 0);
            //alarme_active &= (0 << 0);
        
        if (lecture_8bit_analogique(TEMPERATURE_HUILE)>200)
            alarme_active = setBit(alarme_active, 1);
            //alarme_active |= (1 << 1);
        else
            alarme_active = clearBit(alarme_active, 1);
            //alarme_active &= (0 << 1);
        
        if (batterie<25)
            alarme_active = setBit(alarme_active, 3);
            //alarme_active |= (1 << 3);
        else
            alarme_active = clearBit(alarme_active, 3);
            //alarme_active &= (0 << 3);
        
        // Buzzer alume
        buz=!buz;
        //RJ7=buz;
        
    }
}
