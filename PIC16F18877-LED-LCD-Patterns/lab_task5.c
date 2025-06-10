/*
 * File:   lab_task5.c
 * Author: 2231349
 *
 * Created on 31 January 2024, 20:00
 */


#include <xc.h>

// CONFIG1
#pragma config FEXTOSC = OFF    
// External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = HFINT32 
// Power-up default value for COSC bits (HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF   
// Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON       
// Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       
// Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = ON       
// Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = ON       
// Power-up Timer Enable bit (PWRT enabled)
#pragma config LPBOREN = ON     
// Low-Power BOR enable bit (ULPBOR enabled)
#pragma config BOREN = ON      
// Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        
// Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD = OFF        
// Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = OFF    
// Peripheral Pin Select one-way control (The PPSLOCK bit can be set and cleared repeatedly by software)
#pragma config STVREN = ON      
// Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31 
// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF         
// WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7  
// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC        
// WDT input clock selector (Software Control)

// CONFIG4
#pragma config WRT = OFF        
// UserNVM self-write protection bits (Write protection off)
#pragma config SCANE = available 
// Scanner Enable bit (Scanner module is available for use)
#pragma config LVP = OFF        
// Low Voltage Programming Enable bit (High Voltage on MCLR/Vpp must be used for programming)

// CONFIG5
#pragma config CP = OFF  
// UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD = OFF 
// DataNVM code protection bit (Data EEPROM code protection disabled)

#define _XTAL_FREQ 32000000 
// Defines the hardware crystal frequency allowing the delay function to work correctly

void delay(unsigned int j) 
{ 
    unsigned int i; 
    while(j!=0) // value of integer inside delay()
    { 
        for(i=46811; i!=0; i--); // Number of iterations are 46811
        j--;                     // Decrementing values (j--)
    }
}

const char patterns [10] = 
{ 
    0xc0, 0xf9, 0xa4, 0xb0, 0x99,  
    0x92, 0x82, 0xf8, 0x80, 0x90 
    //0x82 (not 0x83)
    //0x80 (not 0x90)
    //0x90 (not 0x96)

};
    //This is the table of CORRECT 0-9 values (10 HEX values)
    //corresponding to each digit in order (0-9)

char seg7(char x) 
{ 
    if(x < 10) 
    { 
        return(patterns[x]); 
    } 
    else 
    { 
        return(0xff); 
    }  
} 

void main (void) {
    ANSELA = 0;           // Set all PINS on the PORTA side as Digital
    TRISA = 0xff;         // Set all BITS in PORTA as Inputs
    TRISB = 0;            // Set all BITS in PORTB as Outputs
    char digit;  
    while(1) 
    { 
        for( digit = 0; digit < 10; digit++) 
        { 
            LATB = seg7(digit); 
            LATAbits.LATA0=1; //The Switch Button 0 is pressed (ON)
            LATAbits.LATA1=1; //The Switch Button 1 is pressed (ON)
            LATAbits.LATA2=1; //The Switch Button 2 is pressed (ON)
            LATAbits.LATA3=1; //The Switch Button 3 is pressed (ON)
            delay(100); //10 second delay
        } 
    }
}

