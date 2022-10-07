/* 
 * File:   systeme.h
 * Author: Franck
 *
 * Created on 29 janvier 2015, 09:47
 */

#ifndef SYSTEME_H
#define	SYSTEME_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"



// Prototypes
    void interrupt fonction_d_interruption();
    void initialisation_du_systeme();
    
    // Function to set the kth bit of n
char setBit(char n, int k);

// Function to clear the kth bit of n
char clearBit(char n, int k);

// Function to toggle the kth bit of n
char toggleBit(char n, int k);


#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEME_H */

