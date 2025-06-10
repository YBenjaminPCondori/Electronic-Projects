/*
 * File:   lab_task77.c
 * Author: 2231349
 *
 * Created on 20 February 2024, 15:12
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

void delay(int x)
{
	unsigned int i; 
	while(x !=0) //Outer Loop
	{ 
		for(i = 250; i!=0; i--);  // Number of iterations are 250
		x--;                      // Decrementing values (x--)
    }
}

void lcd_cmd(unsigned char cmd) // to SEND Command
 {
    LATB = 0x20 + ((cmd >> 4) & 0x0f);  // enable + MSB of instruction
    LATB = (cmd >> 4) & 0x0f;                  
// sent
    delay(1);
    LATB = 0x20 + (cmd & 0x0f);             
    LATB = cmd & 0x0f;                             
    delay(1);
 }

 void lcd_char(unsigned char c) // To Send a Message
 {
    LATB = 0x30 + ((c >> 4) & 0x0f);    // enable + MSB of char
    LATB = 0x10 + ((c >> 4) & 0x0f);    // sent
    delay(1);
    LATB = 0x30 + (c & 0x0f);               
// enable + LSB of char
    LATB = 0x10 + (c & 0x0f);               
    delay(1);
 }

void display_message(const unsigned char * mess) // to Display Message
{
    unsigned int i=0;
    while(mess[i] != 0)
    {
    lcd_char(mess[i]);
    i++;
    }
 }

void lcd_init() // to initialise LCD
{ 
	delay(60); 
	LATB = 0x23;   //enable 
	LATB = 0x03;   //sent 
	delay(20); 
	LATB = 0x23;   //enable 
	LATB = 0x03;  //sent 
	delay(5); 
	LATB = 0x23;   //enable 
	LATB = 0x03;   //sent 
	delay(5); 
	LATB = 0x23;   //enable 
	LATB = 0x03;   //sent 
	delay(5); 
} 

void display_cursor(unsigned char line, unsigned char position)
{
    if(line != 0)
    {
        position = position + 0x40; 
    }
 lcd_cmd(0x80+position);
}

//display_number(1234);

void display_number(unsigned long value)
{
    display_cursor(0,0x94);
    lcd_char('0' + value / 1000000);
    value = value % 1000000;
    lcd_char('0' + value / 100000);
    value = value % 100000;
    lcd_char('0' + value / 10000);
    value = value % 10000;
    lcd_char('0' + value / 1000);
    value = value % 1000;
    lcd_char('0' + value / 100);
    value = value % 100;
    lcd_char('0' + value / 10 );
    lcd_char('0' + value % 10);
}

void main()
{ 
 TRISB=0x00;           //set all pins in port B as outputs
 lcd_init();           // Initialise the LCD Display
 lcd_cmd(0x28);        //  2 lines, 4 bit interface, 5x7 or 5x8 dots    (0010 0100)
 lcd_cmd(0x0c);        // Turn display ON, no Cursor Displayed          (1000 0000)  
 lcd_cmd(0x06);        // Set Cursor to move right after each character (0000 0101)
 lcd_cmd(1);           // Clear the LCD Display                      (1111 1111)
 const unsigned char yehoshuabenjamin [18] = 
 { 'Y', 'e', 'h', 'o', 's','h', 'u', 'a', ' ', 'B', 'e', 'n', 'j', 'a', 'm', 'i', 'n', 0x00 };
 const unsigned char perezcondori [14] = 
 { 'P', 'e', 'r', 'e', 'z',' ','C', 'o', 'n', 'd', 'o','r','i', 0x00 };
    while(1)
    {
     lcd_cmd(0x80);         // set to display at left of line 1
     display_message(yehoshuabenjamin);
     lcd_cmd(0xC0);         // set to display at left of line 2
     display_message(perezcondori);
     lcd_cmd(0x94);	        // set to display at left of line 3
     display_number(2231349); 
     delay(60);
    }
 }
 
 



