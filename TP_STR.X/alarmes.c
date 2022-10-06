#include "alarmes.h"
#include "stid.h"

/*
struct alarme *p = &(struct alarme){  .bSiege = false,
                                      .bT_eau = false,
									  .bT_huile = false,
									  .bChoc= false,
									  .bVitesse= false,
									  .bBatterie = false,
									  .bFrein= false,
									  .bClef= false,
									};*/

/*
char setBit(char n, int k)
{
    return (n | (1 << k));
}


char clearBit(char n, int k)
{
    return (n & (~(1 << k)));
}


char toggleBit(char n, int k)
{
    return (n ^ (1 << k));
}*/

unsigned int majAlarmes()
{
    //valeurClef = lecture_normale();
/*
 unsigned int alarmesEnCours = 0;
    
 if((SIEGE == 1) && vitesse>0)  
 {
     msgErreur = setBit(msgErreur,def_siege);
     alarmesEnCours ++;
 }
 if(TEMPERATURE_HUILE == 1)  
 {
    msgErreur = setBit(msgErreur,def_temp_huile);
    alarmesEnCours ++;
 }
 if (TEMPERATURE_EAU == 1)
 {
     msgErreur = setBit(msgErreur,def_temp_eau);
     alarmesEnCours ++;
 }
 if (CHOC == 1)
 {   
     if ((tickCounter %120)==1)
     {
         msgErreur = setBit(msgErreur,def_choc);
         alarmesEnCours ++;
     }
 }
 if ((BATTERIE_MOINS == 0x0A) ||(BATTERIE_MOINS == 0x00))
 {
     msgErreur = setBit(msgErreur,def_batterie);
     alarmesEnCours ++;
 }
 if (VITESSE_PLUS == 0x0A)
 {
     msgErreur = setBit(msgErreur,def_vitesse);
     alarmesEnCours ++;
 }
 if (FREIN_A_MAIN = 0x00)
 {
     msgErreur = setBit(msgErreur,def_frein);
     alarmesEnCours ++;
 }
 if (valeurClef == 0)
 {
     msgErreur = setBit(msgErreur,def_clef);
     alarmesEnCours ++;
     goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
 }
 
 return alarmesEnCours;*/
}

