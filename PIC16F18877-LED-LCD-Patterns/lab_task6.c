
/*
 * File:   lab_task8.c
 * Author: 2231349
 *
 * Created on 20th January 2024, 20:00
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

void delay(unsigned int j) 
{ 
    unsigned int i; 
    while(j != 0) 
    { 
        for(i = 4681; i != 0; i--); // Number of iterations are 4681 (4681/10)
        j--;                        // Decrementing values (j--)
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

char seg7(char x) 
{ 
    if(x < 10) 
    { 
        return patterns[x];
    } 
    else 
    { 
        return 0xff; 
    }  
} 

void refresh(char dig0, char dig1, char dig2, char dig3) 
{ 
    LATB = seg7(dig0); 
    LATAbits.LATA3 = 1;    // enable digit 0
    delay(10); // use delay
    LATAbits.LATA3 = 0;    // disable digit 0 
    
    LATB = seg7(dig1); 
    LATAbits.LATA2 = 1;    // enable digit 1 
    delay(10); 
    LATAbits.LATA2 = 0;    // disable digit 1 
    
    LATB = seg7(dig2); 
    LATAbits.LATA1 = 1;    // enable digit 2 
    delay(10); 
    LATAbits.LATA1 = 0;    // disable digit 2 
    
    LATB = seg7(dig3); 
    LATAbits.LATA0 = 1;    // enable digit 3 
    delay(10); 
    LATAbits.LATA0 = 0;    // disable digit 3 
} 

void main(void) 
{
    TRISA = 0x00; // Set PORTA as output
    TRISB = 0x00; // Set PORTB as output

    unsigned int value; 
    char count;
    char dig0, dig1, dig2, dig3; // removed from parameters and used as characters
    //inside here (initialisation))
    
    while(1) 
    { 
        for(value = 0; value < 10000; value++)  
        { 
            dig3 = value / 1000;           //digit to the far left
            dig2 = (value % 1000) / 100;   //digit on the 3rd segment
            dig1 = (value % 100) / 10;     //digit on the 2nd segment
            dig0 = value % 10;             //digit to the far right
            
            for(count = 20; count != 0; count--) 
            { 
                refresh(dig0, dig1, dig2, dig3); 
            } 
        } 
    }
}
