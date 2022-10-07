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
    
    
    void interrupt low_priority LOWISR();
    void interrupt high_priority HIGHISR ();

    unsigned char flagVitesse=0;
    unsigned char flagChoc = 0;
    
#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

