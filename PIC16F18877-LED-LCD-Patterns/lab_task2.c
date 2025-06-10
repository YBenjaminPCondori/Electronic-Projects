/*
 * File:   lab_task2.c
 * Author: 2231349
 *
 * Created on 31 January 2024, 19:59
 */


#include <xc.h> 
void main(void) {
    ANSELA = 0;           // Set all PINS on the PORTA side as Digital
    TRISA = 0xff;         // Set all PINS on the PORTA side as Input
    TRISB = 0;            // Set all BITS in PORTB as Outputs  

        while(1) 
            // Forever Loop (While) for Embedded Machines
            { 
                if (PORTAbits.RA0 != 1 && 
                    PORTAbits.RA1 != 1 && 
                    PORTAbits.RA2 != 1 && 
                    PORTAbits.RA3 != 1)
                    // If Switches 0, and 1, and 2, and 3 and 4 aren't turned ON.
                {
                    LATB = 0; 
                    /* turn off all LEDS, if no switches are pressed. 
                    Using "AND" operator instead of "OR". */
                }
                else if (PORTAbits.RA0 != 0) 
                    //If Switch Button 0 is pressed (Not OFF)
                { 
                    LATB = 0xF0; 
                    //Turn on LEDs: 7, 6 ,5 and 4 on and the rest are off.
                    
                } 
                else if (PORTAbits.RA1 != 0)
                    //If Switch Button 1 is pressed (Not OFF)
                {
                    LATB = 0b00001111;
                    //Turn on LEDs: 0, 1, 2, 3 collectively (4 LEDs)
                }
                else if (PORTAbits.RA2 != 0)
                    //If Switch Button 2 is pressed (Not OFF)
                {
                    LATB = 0b10101010;
                    //Turn on LEDs: 7, 5, 3, 1 collectively (4 LEDs)
                }
                else if (PORTAbits.RA3 != 0)
                    //If Switch Button 3 is pressed (Not OFF)
                {
                    LATB = 0b01010101;
                    //Turn on LEDs: 6, 4, 2, 0 collectively (4 LEDs)
                } 
    }
return;
}
         
