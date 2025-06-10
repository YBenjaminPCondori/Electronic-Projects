/*
 * File:   lab_task1.c
 * Author: 2231349
 *
 * Created on 31 January 2024, 19:59
 */


#include <xc.h> 
void main(void) { 
    ANSELA = 0;           // Set all PINS on the PORTA side as Digital
    TRISA = 0xff;         // Set all PINS on the PORTA side as Input
    TRISB = 0;            // Set all BITS in PORTB as Outputs
    while(1)              // Create an Infinite Loop using (While) condition
    { 

    LATB = PORTA;         // All values from PORTA switches will be copied to PORTB LEDs
} 
return; 
}
