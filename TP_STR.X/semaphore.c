#include "semaphore.h"


void Init(unsigned char sem)
{
    switch (sem)
    {
        case SEM_CAN:
            Val_sem_cna=1;
            break;
        case SEM_RXTX:
            Val_sem_rxtx=1;
            break;
        default:
            ;
        
    }
}

/*reentrant*/ void P(unsigned char sem)
{
    switch(sem)
    {
        case SEM_CAN:
            while (Val_sem_cna<1)  // Tant que le cna est occupé
                ;                   // On attend
                Val_sem_cna=0; // Dès qu'il est libre, on le réserve
        case SEM_RXTX:
            while (Val_sem_rxtx<1)  // Tant que la liaison série est occupé
                ;                   // On attend
                Val_sem_cna=0; // Dès qu'elle est libre, on la réserve
        default:
            ;
    }
}

/*reentrant*/ void V(unsigned char sem)
{
    switch(sem)
    {
        case SEM_CAN:
            Val_sem_cna=1;
            break;
        case SEM_RXTX:
            Val_sem_rxtx=1;
            break;
        default:
            ;
    }
}