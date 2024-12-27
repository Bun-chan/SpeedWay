/*
 * File:   main.c
 * Author: boombox
 *
 * Created on December 27, 2024, 1:52 PM
 */


#include <xc.h>
#include "LCD.h"

#pragma config FOSC = INTOSCIO_EC   // Internal oscillator, external clock on RA6/OSC2/CLKOUT
#pragma config WDT = OFF           // Watchdog Timer disabled
#pragma config PWRT = ON           // Power-up Timer enabled
#pragma config MCLRE = ON          // MCLR pin enabled


void main(void) {
//    OSCCON = 0x72; // Set the internal oscillator to 8 MHz
    OSCCONbits.IRCF = 0b111;  // Internal Oscillator set to 8MHz
    OSCCONbits.SCS = 0b10;    // System Clock Select set to Internal Oscillator
    
    TRISA = 0x00; // Set all PORTA pins as outputs (0 = Output)
    LATA = 0x00; // Clear all output latches (LED off initially)
    
    TRISD = 0x00; // 0b00000000 - All pins of Port D set to output
    TRISC = 0x00; // 0b00000000 - All pins of Port C set to output
    
    
    LATAbits.LATA0 = 0; // Set RA0 high
    
    
    LCD_init();
    LCD_write_string("check baby check");
    
    while(1) {
        
        
    }
    return;
}
