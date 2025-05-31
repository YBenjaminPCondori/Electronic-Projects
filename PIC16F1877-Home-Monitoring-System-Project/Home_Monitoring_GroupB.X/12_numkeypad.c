/*
 * File:   12_numkeypad.c
 * Author: 2231349
 *
 * Created on 01 March 2024, 12:12
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

//#define _XTAL_FREQ 32000000 
// Defines the hardware crystal frequency allowing the delay function to work correctly

void delay(int x)
{
	unsigned int i; 
	while(x !=0) //Outer Loop
	{ 
		for(i = 250; i!=0; i--);  // Number of iterations are 250
		x--;                      // Decrementing values (x--)
    }
}

void main()
{ 
ANSELA = 0;
TRISA=0b11110000;
LATA=0xff;
    
    char value; 
	while(1)
	{        
       
    LATAbits.LATA0=0;
    if(PORTAbits.RA4 == 0)
    {
    value = '1';
    }
    else if(PORTAbits.RA5 == 0)
    {
    value = '2';
    }
    else if(PORTAbits.RA6 == 0)
    {
    value = '3';
    }
    LATAbits.LATA0=1;
    LATAbits.LATA1=0;
    if(PORTAbits.RA4 == 0)
    {
    value = '4';
    }
    else if(PORTAbits.RA5 == 0)
    {
    value = '5';
    }
    else if(PORTAbits.RA6 == 0)
    {
    value = '6';
    }
    LATAbits.LATA1=1;
    LATAbits.LATA2=0;
    if(PORTAbits.RA4 == 0)
    {
    value = '7';
    }
    else if(PORTAbits.RA5 == 0)
    {
    value = '8';
    }
    else if(PORTAbits.RA6 == 0)
    {
    value = '9';
    }
    LATAbits.LATA2=1;
    LATAbits.LATA3=0;
    if(PORTAbits.RA4 == 0)
    {
    value = '*';
    }
    else if(PORTAbits.RA5 == 0)
    {
    value = '0';
    }
    else if(PORTAbits.RA6 == 0)
    {
    value = '#';
    }
    LATAbits.LATA3=1;
	}
}
