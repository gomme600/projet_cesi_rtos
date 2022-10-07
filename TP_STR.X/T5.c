#include "T5.h"


//Alarme et erreurs

int buz=1;

void tache5()
{
    unsigned int a;
    while(1)
    {
        
        //Si personne dans siege et vitesse > 0
        if (SIEGE==1 && vitesse>0)
            alarme_active = setBit(alarme_active, 6);
        else
            alarme_active = clearBit(alarme_active, 6);
        
        if (n_octet_badge==0)
            alarme_active = setBit(alarme_active, 4);
        else
            alarme_active = clearBit(alarme_active, 4);
        
        if (CHOC==0)
        {
            choc_time++;
            if (choc_time>3000)
                alarme_active = setBit(alarme_active, 2);
            if (choc_time>6000)
                error_active = setBit(alarme_active, 2);
        }
        else
        {
            if (choc_time==0)
            {
                //alarme_active = clearBit(alarme_active, 2);
                //error_active = clearBit(alarme_active, 2);
                //Add 1 because we dont want to wrap around
                choc_time++;
            }
                
            choc_time--;
        }
        
        if (FREIN_A_MAIN==0 && vitesse>0)
            alarme_active = setBit(alarme_active, 5);
        else
            alarme_active = clearBit(alarme_active, 5);
        
        if (lecture_8bit_analogique(TEMPERATURE_EAU)>200)
            alarme_active = setBit(alarme_active, 0);
        else
            alarme_active = clearBit(alarme_active, 0);
        
        if (lecture_8bit_analogique(TEMPERATURE_HUILE)>200)
            alarme_active = setBit(alarme_active, 1);
        else
            alarme_active = clearBit(alarme_active, 1);
        
        if (batterie<25)
            alarme_active = setBit(alarme_active, 3);
        else
            alarme_active = clearBit(alarme_active, 3);
        
        // Buzzer alume
        buz=!buz;
        //RJ7=buz;
        
        //reset alarms and errors
        if (VITESSE_PLUS==0 & VITESSE_MOINS==0)
        {
            alarme_active = 0;
            error_active = 0;
        }
        
    }
}
