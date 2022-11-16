#include "T3.h"

int seuil_vitesse_haut=0;

void tache3()
{
    while(1)
    {

        tempeau = lecture_8bit_analogique(TEMPERATURE_EAU);
        temphuile = lecture_8bit_analogique(TEMPERATURE_HUILE);
        
        //Mode degrade
        if (alarme_active != 0x00)
        {
            //4 fois moins en mode dégradé
            seuil_vitesse_haut=0x40;
            if (vitesse > seuil_vitesse_haut)
            {
                vitesse=seuil_vitesse_haut;
            }
        }
        else
        {
            seuil_vitesse_haut=0xFE;
        }
        
        if (VITESSE_PLUS==0)
            if ( vitesse <= seuil_vitesse_haut)
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
        
        //Mise a l'echelle
        vitesseReel=vitesse/10;
        batterieReel=batterie/10;
        eauReel=tempeau/2.5;
        huileReel=temphuile/2.5;
        
        //Temps d'utilisation de la machine (uniquement lorsque le badge est inseree)
        if (n_octet_badge != 0)
        {
            machine_use_time=machine_use_time+(millis-previous_use_time);
        }
        previous_use_time=millis;
        
    }
    
}