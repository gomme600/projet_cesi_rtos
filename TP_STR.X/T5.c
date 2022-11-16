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
            error_active = setBit(error_active, 6);
        //else
            //error_active = clearBit(error_active, 6);
        
        if (n_octet_badge==0)
            alarme_active = setBit(alarme_active, 4);
        else
            alarme_active = clearBit(alarme_active, 4);
        
        if (CHOC==0)
        {
            choc_time++;
            if (choc_time>4000)
                alarme_active = setBit(alarme_active, 2);
            if (choc_time>8000)
                error_active = setBit(error_active, 2);
        }
        else
        {
                if (choc_time==0)
                {
                    //Add 1 because we dont want to wrap around
                    choc_time++;
                    alarme_active = clearBit(alarme_active, 2);
                }
                
                choc_time--;
        }
        
        if (FREIN_A_MAIN==0 && vitesse>0)
            alarme_active = setBit(alarme_active, 5);
        else
            alarme_active = clearBit(alarme_active, 5);
        
        
        if (tempeau>200)
            alarme_active = setBit(alarme_active, 0);
        else if (tempeau>230)
            error_active = setBit(error_active, 0);
        else
            alarme_active = clearBit(alarme_active, 0);
        
        
        if (temphuile>200)
            alarme_active = setBit(alarme_active, 1);
        else if (temphuile>230)
            error_active = setBit(error_active, 1);
        else
            alarme_active = clearBit(alarme_active, 1);
        
        
        if (batterie<25)
            alarme_active = setBit(alarme_active, 3);
        else if (batterie<12)
            error_active = setBit(error_active, 3);
        else
            alarme_active = clearBit(alarme_active, 3);
        
        
        // Buzzer alume
        if (alarme_active > 0 || error_active > 0 || MARCHE_ARRIERE==0)
        {
            RJ7=buz;
            buz=!buz;
        }
        
        //reset alarms and errors
        if (VITESSE_PLUS==0 & VITESSE_MOINS==0)
        {
            alarme_active = 0;
            error_active = 0;
        }
        
    }
}
