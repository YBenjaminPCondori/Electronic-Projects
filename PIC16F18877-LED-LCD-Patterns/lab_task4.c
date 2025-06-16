/*
 * File:   lab_task4.c
 * 
 * Author: <Student ID ommited for privacy reasons>
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
        for(i=468; i!=0; i--); // Number of iterations are 4681 (i.e. 46811/100)
        j--;                     // Decrementing values (j--)
    }
}

void main(void) {
    ANSELA = 0;           // Set all PINS on the PORTA side as Digital
    TRISA = 0xff;         // Set all PINS on the PORTA side as Input
    TRISB = 0;            // Set all BITS in PORTB as Outputs  

        while(1) 
            { 
                if (PORTAbits.RA4 != 0) 
                     //If switch 4 of PORTA is on, copy the state of PORTA switches to PORTB LEDs  
                { 
                    LATB = PORTA; 
                    //copy the state of PORTA pins (switches) to PORTB LED Pins (0-7) // 
                } 
                
                else if (PORTAbits.RA3 != 0)
                {
                    unsigned char copy;
                    copy = 0x80; // LED Pin 7 (PORT B) turned ON
                    char i;      // The character i is initialised
                    for(i=0; i<8; i++) 
                    // (FOR Loop): Responsible for looping the shift (to right-hand side)
                    {
                        LATB = copy;
                        copy = copy>>1; 
                    // instruction to shift LED values on PORT B right-direction (once)
                        delay(125); 
                    //time delay of 0.125 seconds
                    }
                    copy = 0x01; // The LED Pin 0 (PORT B) Turned ON
                    for(i=0; i<8; i++)
                    {
                        LATB = copy;
                        copy = copy<<1;
                        // instruction to shift LED values on PORT B leftt-direction (once)
                        delay(125); 
                        //time delay of 0.125 seconds
                    }
                }
                      
                else if (PORTAbits.RA2 != 0)
                {
                    unsigned char copy;
                    copy = 0x01; // LED Pin 0 (PORT B) Turned ON
                    char i;
                    for(i=0; i<8; i++)
                    {
                        LATB = copy;
                        copy = copy<<1;
                        // instruction to shift LED values on PORT B left-direction (once)
                        delay(125);
                        //time delay of 0.125 seconds
                    }
                    copy = 0x80;
                    for(i=0; i<8; i++)
                    {
                        LATB = copy;
                        copy = copy>>1;
                        delay(1);
                    }
                }
                
                else if (PORTAbits.RA1 != 0)
                {
                    unsigned char copy;
                    copy = 0x01; // LED 1 ON
                    char i;
                    for(i=0; i<8; i++)
                    {
                        LATB = copy;
                        copy = copy<<1;
                        delay(125); 
                        //time delay of 0.125 seconds
                    }
                }
                
                else if (PORTAbits.RA0 != 0)
                {
                    LATB = 0xff;
                    // All LEDS on LATA are turned ON: 0b11111111
                }  
                else     // If all switches are turned off (!=0), 
                {                              // then the LED Pins are all OFF
                    LATB = 0;                // All LEDs on LATA are turned OFF
                } 
            }
        }

