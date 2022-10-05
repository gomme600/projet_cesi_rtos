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
            alarme_active=1;
        else
            alarme_active=0;
        
        if (n_octet_badge==0)
            alarme_active=1;
        else
            alarme_active=0;
        
        // Buzzer alume
        buz=!buz;
        //RJ7=buz;
        
    }
}
