/* 
 * File:   interrupt.h
 * Author: WAGNER Marco
 *
 * Created on 6 octobre 2022, 11:04
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif


//Initialise Interrupts
 /*   RCONbits.IPEN = 1; //Enable interrupt priority levels
    INTCON = 0xD0; //Enable INT0
    INTCON2 = 0x70; //External interrupts on rising edge
    INTCON3 = 0x18; //INT1 low priority INT 2 low priority*/
    
    
    //void interrupt low_priority LOWISR();
    //void interrupt high_priority HIGHISR ();

    unsigned char flagVitesse=0;
    
#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

