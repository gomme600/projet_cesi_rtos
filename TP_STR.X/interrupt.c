#include "interrupt.h"
#include "main.h"



void interrupt low_priority LOWISR()
{

}


void interrupt high_priority HIGHISR ()
{
    if (VITESSE_PLUS > 0x26)
    {
       flagVitesse = 1;
    }
}