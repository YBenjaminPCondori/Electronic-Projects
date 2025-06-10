/*
 * File:   lab_task8.c
 * Author: 2231349
 *
 * Created on 26th February 2024 2024, 15:10
 */
#include <xc.h>
#include <stdio.h>

#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits (Oscillator not enabled)
#pragma config RSTOSC = HFINT32 // Power-up default value for COSC bits (HFINTOSC OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF   // Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON //is allowed
#pragma config FCMEN = ON    //  enabled)
// CONFIG2
#pragma config MCLRE = ON      // Clock Switch Enable bit (Writing to NOSC and NDIV
 // Fail-Safe Clock Monitor Enable bit (FSCM timer
// Master Clear Enable bit (MCLR pin is Master Clear function)
#pragma config PWRTE = ON
       //Power-up Timer Enable bit (PWRT enabled)
#pragma config LPBOREN = ON     // Low-Power BOR enable bit (ULPBOR enabled)
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
#pragma config WDTCPS = WDTCPS_31// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF      // (ignored)
// WDT operating mode (WDT Disabled, SWDTEN is
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)
// CONFIG4
#pragma config WRT = OFF       //(off)
 // UserNVM self-write protection bits (Write protection
#pragma config SCANE = available// Scanner Enable bit (Scanner module is available for use)
#pragma config LVP = OFF
        //Voltage Programming Enable bit (High Voltage on MCLR/Vpp must be used for programming)
// CONFIG5
#pragma config CP = OFF      
   // UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD = OFF        
// DataNVM code protection bit (Data EEPROM code protection disabled)
#define _XTAL_FREQ 32000000 the delay function to work correctly
// Defines the hardware crystal frequency allowing

void delay(int x)
{
    unsigned int i;
    while(x !=0)
    {
        for(i = 250; i!=0; i--);
        x--;
    }
}
void lcd_init()
{
delay(60);
LATB = 0x23;   // enable
LATB = 0x03;   //sent
delay(20);
LATB = 0x23;   // enable
LATB = 0x03;  //sent
delay(5);
LATB = 0x23;   //enable
LATB = 0x03;   //sent
delay(5);
LATB = 0x23;   //enable
LATB = 0x03;   //sent
delay(5);
}

void lcd_cmd(unsigned char cmd)
 {
 LATB = 0x20 + ((cmd >> 4) & 0x0f);  // enable + MSB of instruction
 LATB = (cmd >> 4) & 0x0f;                  
// sent
 delay(1);
 LATB = 0x20 + (cmd & 0x0f);            
LATB = cmd & 0x0f;                            
delay(1);
 }

void lcd_char(unsigned char c)
 {
 LATB = 0x30 + ((c >> 4) & 0x0f);    // enable + MSB of char
 LATB = 0x10 + ((c >> 4) & 0x0f);    // sent
 delay(1);
 LATB = 0x30 + (c & 0x0f);              
// enable + LSB of char
 LATB = 0x10 + (c & 0x0f);              
delay(1);
 }

void adc_init(){
    TRISB = 0;
    ADPCH = 0x00; // use ANA0 channel
    ADCON0bits.ADON = 1; //Enable ADC module
    ADCON0bits.ADFRM = 0; //Result format is left justified
}
void binary_to_decimal_converter(unsigned long int) {/*
// Manually check each bit and display '1' or '0'
    lcd_char('0' + (value >= 128)); // Check the 128's place
    value %= 128; // Remove the 128's place
    lcd_char('0' + (value >= 64)); // Check the 64's place
    value %= 64; // Remove the 64's place
    lcd_char('0' + (value >= 32)); // Check the 32's place
    value %= 32; // Remove the 32's place
    lcd_char('0' + (value >= 16)); // Check the 16's place
    value %= 16; // Remove the 16's place
    lcd_char('0' + (value >= 8)); // Check the 8's place
    value %= 8; // Remove the 8's place
    lcd_char('0' + (value >= 4)); // Check the 4's place
    value %= 4; // Remove the 4's place
    lcd_char('0' + (value >= 2)); // Check the 2's place
    value %= 2; // Remove the 2's place
    lcd_char('0' + (value >= 1)); // Check the 1's place
    // No need to mod by 1 as we're checking the last bit*/
}


 void display_message(const unsigned char * message)
 {
 unsigned int i=0;
 while(message[i] != 0)
 {
 lcd_char(message[i]);
 i++;
 }
 }
   void display_cursor(unsigned char line, unsigned char position)
 {
 if(line != 0)
 {
 position = position + 0x40;
}
 lcd_cmd(0x80+position);
 }
 void display_number(unsigned long value)
 {
 display_cursor(0,0x94);
 lcd_char('0' + value / 1000);
 value = value % 1000;
 lcd_char('0' + value / 100);
 value = value % 100;
 lcd_char('0' + value / 10 );
 lcd_char('0' + value % 10);
 }                                           // This subroutine is used to display integers inside the LCD Display.
 float ADCReading_to_Voltage(int adcvalue) { // Only applicable if the Voltage input is 5V
    return ((float)adcvalue * 5.0 / 1023.0);
}

unsigned int convert(unsigned char chan){
    ADPCH = 0x00; //select channel
    ADCON0bits.ADGO=1;
    while (ADCON0bits.ADGO);
    return ((ADRESH<<8) | ADRESL);
}

void main() {
    TRISB = 0x00;
    adc_init();
    lcd_init();
    lcd_cmd(0x28);
    lcd_cmd(0x0c);
    lcd_cmd(0x06);
    lcd_cmd(1);
    unsigned int value;
    const unsigned char ADCResults[13] = {'A', 'D', 'C', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ':', 0x00};
    const unsigned char VoltageUnit[4] = {'V', 'o', 'l', 0x00};
    unsigned char ADC[13];
    unsigned char V[15];
    ANSELA = 0xff;
    ADCON0 = 0x84;

    while (1) {
        value = convert(0);
        float Voltage = ADCReading_to_Voltage(value);
        sprintf(ADC, "%u", value);
        sprintf(V, "%.2f Volt", Voltage);
        lcd_cmd(0x80);
        display_message(ADCResults);
        lcd_cmd(0x94);
        display_message(ADC);
        lcd_cmd(0xD4);
        display_message(V);
        delay(60);
    }
}