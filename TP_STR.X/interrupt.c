#include "interrupt.h"
#include "main.h"
#include "systeme.h"

/*void interrupt high_priority HIGHISR ()
{
    //Interruptions boutons
    //Choc
    if (INTCON3bits.INT3IF==1)
    {
    INTCON3bits.INT3IF=0;
    tache_prioritaire=5;
    flagChoc = 1;
    
    }

    //Marche arriere
    if (INTCON3bits.INT1IF==1)
    {
    INTCON3bits.INT1IF=0;
    tache_prioritaire=5;
    flagMarcheArriere = 1;
    
    }

    //Siege
    if (INTCON3bits.INT2IF==1)
    {
    INTCON3bits.INT2IF=0;
    tache_prioritaire=5;
    flagSiege = 1;
    
    }
}*/