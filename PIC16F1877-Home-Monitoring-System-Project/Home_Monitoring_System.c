/*
 * File:   Home_Monitoring_System.c
 * Author: Y. Benjamin Perez Condori
 * Student ID: 2231349
 *
 * Created on March 2024
 * 
 * Home Monitoring System Project
 * Features: LCD Display, Keypad Input, Temperature Sensor, LED Control
 * Microcontroller: PIC16F1877
 */

#include <xc.h>
#include <stdio.h>
#include <string.h>

// Configuration bits
#pragma config FOSC = INTRC_NOCLKOUT    // Oscillator Selection bits
#pragma config WDTE = OFF               // Watchdog Timer Enable bit
#pragma config PWRTE = ON               // Power-up Timer Enable bit
#pragma config MCLRE = ON               // MCLR Pin Function Select bit
#pragma config CP = OFF                 // Code Protection bit
#pragma config CPD = OFF                // Data Code Protection bit
#pragma config BOREN = ON               // Brown Out Reset Selection bits
#pragma config IESO = ON                // Internal External Switchover bit
#pragma config FCMEN = ON               // Fail-Safe Clock Monitor Enabled bit
#pragma config LVP = OFF                // Low Voltage Programming Enable bit

// LCD pin definitions
#define LCD_RS PORTEbits.RE0
#define LCD_EN PORTEbits.RE1
#define LCD_D4 PORTDbits.RD4
#define LCD_D5 PORTDbits.RD5
#define LCD_D6 PORTDbits.RD6
#define LCD_D7 PORTDbits.RD7

// LCD control pin directions
#define LCD_RS_DIR TRISEbits.TRISE0
#define LCD_EN_DIR TRISEbits.TRISE1
#define LCD_D4_DIR TRISDbits.TRISD4
#define LCD_D5_DIR TRISDbits.TRISD5
#define LCD_D6_DIR TRISDbits.TRISD6
#define LCD_D7_DIR TRISDbits.TRISD7

// Keypad definitions
#define R1 PORTBbits.RB0
#define R2 PORTBbits.RB1
#define R3 PORTBbits.RB2
#define R4 PORTBbits.RB3

#define C1 PORTBbits.RB4
#define C2 PORTBbits.RB5
#define C3 PORTBbits.RB6

// LED definitions
#define LED1 PORTCbits.RC0
#define LED2 PORTCbits.RC1
#define LED3 PORTCbits.RC2
#define BUZZER PORTCbits.RC3

// Temperature sensor (LM35)
#define TEMP_SENSOR 0  // AN0 channel

// Function prototypes
void system_init(void);
void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_string(const char* str);
void lcd_clear(void);
void lcd_goto(unsigned char row, unsigned char col);
void delay_ms(unsigned int ms);
void delay_us(unsigned int us);

char keypad_scan(void);
void keypad_init(void);

unsigned int adc_read(unsigned char channel);
void adc_init(void);
float read_temperature(void);

void display_menu(void);
void display_temperature(void);
void display_security_status(void);
void handle_keypad_input(char key);

// Global variables
char current_mode = '1';  // Default mode: Temperature monitoring
char security_armed = 0;
char password[5] = "1234";  // Default password
char entered_password[5];
unsigned char password_index = 0;
unsigned int temp_threshold = 25;  // Temperature threshold in Celsius

void main(void) {
    system_init();
    lcd_init();
    keypad_init();
    adc_init();
    
    lcd_clear();
    lcd_string("Home Monitor");
    lcd_goto(1, 0);
    lcd_string("System Ready");
    delay_ms(2000);
    
    display_menu();
    
    while(1) {
        char key = keypad_scan();
        
        if(key != 0) {
            handle_keypad_input(key);
            delay_ms(200);  // Debounce delay
        }
        
        // Continuous monitoring based on current mode
        switch(current_mode) {
            case '1':
                display_temperature();
                break;
            case '2':
                display_security_status();
                break;
            case '3':
                // Settings menu
                break;
        }
        
        delay_ms(100);
    }
}

void system_init(void) {
    // Configure oscillator
    OSCCONbits.IRCF = 0b1111;  // 8MHz internal oscillator
    OSCCONbits.SCS = 0b10;     // Internal oscillator
    
    // Configure I/O ports
    ADCON1 = 0x0E;  // Configure AN0 as analog, rest as digital
    
    // LCD pins as outputs
    LCD_RS_DIR = 0;
    LCD_EN_DIR = 0;
    LCD_D4_DIR = 0;
    LCD_D5_DIR = 0;
    LCD_D6_DIR = 0;
    LCD_D7_DIR = 0;
    
    // LED pins as outputs
    TRISCbits.TRISC0 = 0;  // LED1
    TRISCbits.TRISC1 = 0;  // LED2
    TRISCbits.TRISC2 = 0;  // LED3
    TRISCbits.TRISC3 = 0;  // BUZZER
    
    // Clear all outputs
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;
}

void lcd_init(void) {
    delay_ms(20);
    
    // Initialize LCD in 4-bit mode
    lcd_cmd(0x02);  // 4-bit mode
    lcd_cmd(0x28);  // 2 lines, 5x7 matrix
    lcd_cmd(0x0C);  // Display on, cursor off
    lcd_cmd(0x06);  // Increment cursor
    lcd_cmd(0x01);  // Clear display
    delay_ms(2);
}

void lcd_cmd(unsigned char cmd) {
    LCD_RS = 0;  // Command mode
    
    // Send upper nibble
    LCD_D4 = (cmd >> 4) & 1;
    LCD_D5 = (cmd >> 5) & 1;
    LCD_D6 = (cmd >> 6) & 1;
    LCD_D7 = (cmd >> 7) & 1;
    
    LCD_EN = 1;
    delay_us(1);
    LCD_EN = 0;
    delay_us(200);
    
    // Send lower nibble
    LCD_D4 = cmd & 1;
    LCD_D5 = (cmd >> 1) & 1;
    LCD_D6 = (cmd >> 2) & 1;
    LCD_D7 = (cmd >> 3) & 1;
    
    LCD_EN = 1;
    delay_us(1);
    LCD_EN = 0;
    delay_ms(2);
}

void lcd_data(unsigned char data) {
    LCD_RS = 1;  // Data mode
    
    // Send upper nibble
    LCD_D4 = (data >> 4) & 1;
    LCD_D5 = (data >> 5) & 1;
    LCD_D6 = (data >> 6) & 1;
    LCD_D7 = (data >> 7) & 1;
    
    LCD_EN = 1;
    delay_us(1);
    LCD_EN = 0;
    delay_us(200);
    
    // Send lower nibble
    LCD_D4 = data & 1;
    LCD_D5 = (data >> 1) & 1;
    LCD_D6 = (data >> 2) & 1;
    LCD_D7 = (data >> 3) & 1;
    
    LCD_EN = 1;
    delay_us(1);
    LCD_EN = 0;
    delay_us(50);
}

void lcd_string(const char* str) {
    while(*str) {
        lcd_data(*str++);
    }
}

void lcd_clear(void) {
    lcd_cmd(0x01);
    delay_ms(2);
}

void lcd_goto(unsigned char row, unsigned char col) {
    unsigned char address;
    
    if(row == 0)
        address = 0x80 + col;
    else
        address = 0xC0 + col;
    
    lcd_cmd(address);
}

void keypad_init(void) {
    // Configure rows as outputs, columns as inputs
    TRISBbits.TRISB0 = 0;  // R1
    TRISBbits.TRISB1 = 0;  // R2
    TRISBbits.TRISB2 = 0;  // R3
    TRISBbits.TRISB3 = 0;  // R4
    
    TRISBbits.TRISB4 = 1;  // C1
    TRISBbits.TRISB5 = 1;  // C2
    TRISBbits.TRISB6 = 1;  // C3
    
    // Enable weak pull-ups on columns
    OPTION_REGbits.nRBPU = 0;
    WPUBbits.WPUB4 = 1;
    WPUBbits.WPUB5 = 1;
    WPUBbits.WPUB6 = 1;
    
    // Set all rows high initially
    R1 = R2 = R3 = R4 = 1;
}

char keypad_scan(void) {
    char key = 0;
    
    // Scan Row 1
    R1 = 0; R2 = R3 = R4 = 1;
    if(!C1) key = '1';
    else if(!C2) key = '2';
    else if(!C3) key = '3';
    
    // Scan Row 2
    R2 = 0; R1 = R3 = R4 = 1;
    if(!C1) key = '4';
    else if(!C2) key = '5';
    else if(!C3) key = '6';
    
    // Scan Row 3
    R3 = 0; R1 = R2 = R4 = 1;
    if(!C1) key = '7';
    else if(!C2) key = '8';
    else if(!C3) key = '9';
    
    // Scan Row 4
    R4 = 0; R1 = R2 = R3 = 1;
    if(!C1) key = '*';
    else if(!C2) key = '0';
    else if(!C3) key = '#';
    
    R1 = R2 = R3 = R4 = 1;  // Reset rows
    
    return key;
}

void adc_init(void) {
    // Configure ADC
    ADCON0bits.CHS = 0;     // Select AN0
    ADCON0bits.ADON = 1;    // Enable ADC
    ADCON1bits.PCFG = 0x0E; // AN0 analog, rest digital
    ADCON1bits.ADFM = 1;    // Right justified
    ADCON2bits.ACQT = 0b010; // Acquisition time
    ADCON2bits.ADCS = 0b001; // Conversion clock
}

unsigned int adc_read(unsigned char channel) {
    ADCON0bits.CHS = channel;   // Select channel
    delay_us(20);               // Acquisition time
    ADCON0bits.GO = 1;          // Start conversion
    
    while(ADCON0bits.GO);       // Wait for conversion to complete
    
    return ((ADRESH << 8) + ADRESL);
}

float read_temperature(void) {
    unsigned int adc_value = adc_read(TEMP_SENSOR);
    float voltage = (adc_value * 5.0) / 1024.0;  // Convert to voltage
    float temperature = voltage * 100.0;         // LM35: 10mV/°C
    return temperature;
}

void display_menu(void) {
    lcd_clear();
    lcd_string("1:Temp 2:Security");
    lcd_goto(1, 0);
    lcd_string("3:Settings *:Back");
}

void display_temperature(void) {
    float temp = read_temperature();
    char temp_str[16];
    
    lcd_clear();
    lcd_string("Temperature:");
    lcd_goto(1, 0);
    
    sprintf(temp_str, "%.1f C", temp);
    lcd_string(temp_str);
    
    // Temperature alarm
    if(temp > temp_threshold) {
        LED1 = 1;
        BUZZER = 1;
        delay_ms(100);
        BUZZER = 0;
    } else {
        LED1 = 0;
    }
    
    delay_ms(1000);
}

void display_security_status(void) {
    lcd_clear();
    
    if(security_armed) {
        lcd_string("Security: ARMED");
        LED2 = 1;
        LED3 = 0;
    } else {
        lcd_string("Security: DISARMED");
        LED2 = 0;
        LED3 = 1;
    }
    
    lcd_goto(1, 0);
    lcd_string("*:Toggle #:Menu");
    
    delay_ms(500);
}

void handle_keypad_input(char key) {
    switch(current_mode) {
        case '0':  // Menu mode
            if(key >= '1' && key <= '3') {
                current_mode = key;
                if(key == '1') display_temperature();
                else if(key == '2') display_security_status();
                else if(key == '3') {
                    lcd_clear();
                    lcd_string("Settings Menu");
                    delay_ms(1000);
                    display_menu();
                    current_mode = '0';
                }
            }
            break;
            
        case '1':  // Temperature mode
            if(key == '*') {
                display_menu();
                current_mode = '0';
            }
            break;
            
        case '2':  // Security mode
            if(key == '*') {
                security_armed = !security_armed;
                if(security_armed) {
                    BUZZER = 1;
                    delay_ms(200);
                    BUZZER = 0;
                }
            } else if(key == '#') {
                display_menu();
                current_mode = '0';
            }
            break;
            
        default:
            if(key == '#') {
                display_menu();
                current_mode = '0';
            }
            break;
    }
}

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 1000; j++) {
            __delay_us(1);
        }
    }
}

void delay_us(unsigned int us) {
    while(us--) {
        __delay_us(1);
    }
}
