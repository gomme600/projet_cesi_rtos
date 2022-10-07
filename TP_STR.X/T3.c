#include "T3.h"

void tache3()
{
    while(1)
    {

        tempeau = lecture_8bit_analogique(TEMPERATURE_EAU);
        temphuile = lecture_8bit_analogique(TEMPERATURE_HUILE);
        
        if (VITESSE_PLUS==0)
            if ( vitesse <= 0xFE)
                vitesse++;
        if (VITESSE_MOINS==0)
            if ( vitesse > 0)
                vitesse--;
        if (error_active != 0x00) //Dont allow mouvement if error is active
            vitesse=0;
        
        if (BATTERIE_PLUS==0)
            if ( batterie <= 0xFE)
                batterie++;
        if (BATTERIE_MOINS==0)
            if ( batterie > 0)
                batterie--;
        
        vitesseReel=vitesse/10;
        batterieReel=batterie/10;
        eauReel=tempeau/2.5;
        huileReel=temphuile/2.5;
        
        
        
    }
    
}