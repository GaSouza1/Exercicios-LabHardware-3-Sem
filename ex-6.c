/*
 * File:   ex-2.c
 * Author: Gabriel
 *
 * Created on 18 de Outubro de 2026, 13:49
 */
#include <xc.h>

#pragma config OSC = XT
#pragma config WDT = OFF
#pragma config LVP = OFF

#define LED1 LATDbits.LATD0
#define LED2 LATDbits.LATD1
#define _XTAL_FREQ 4000000UL


void tempo_1ms (void);

void main(void) {
    ADCON1 = 0x0F; 
    TRISBbits.TRISB0 = 1;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    
    T0CON = 0b11000001;
    if (PORTBbits.RB0 == 0)
    {
        LED2 = 0;
        LED1 = 1;
    }
    else
    {
        LED1 = 0;
        LED2 = 1;
    }
   
}
void tempo_1ms(void) {
    TMR0L = 6;
     
    INTCONbits.TMR0IF = 0;
    while(INTCONbits.TMR0IF == 0);
    
}
