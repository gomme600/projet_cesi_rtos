#include "T5.h"

//Alarme

int buz=1;

void tache5()
{
    unsigned int a;
    while(1)
    {
        
        //Si personne dans siege et vitesse > 0
        if (SIEGE==1 && vitesse>0)
            alarme_active |= (1 << 6);
        else
            alarme_active &= (0 << 6);
        
        if (n_octet_badge==0)
            alarme_active |= (1 << 4);
        else
            alarme_active &= (0 << 4);
        
        if (CHOC==0)
            alarme_active |= (1 << 2);
        else
            alarme_active &= (0 << 2);
        
        if (FREIN_A_MAIN==0)
            alarme_active |= (1 << 5);
        else
            alarme_active &= (0 << 5);
        
        // Buzzer alume
        buz=!buz;
        //RJ7=buz;
        
    }
}
