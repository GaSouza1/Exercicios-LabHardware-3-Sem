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

#define LED LATDbits.LATD0
#define _XTAL_FREQ 4000000UL


void tempo_100ms (void);

void main(void) {
    ADCON1 = 0x0F;
    TRISBbits.TRISB0 = 1;
    TRISDbits.TRISD0 = 0;
    LED = 0;

    T0CON = 0b11000111;
    while (PORTBbits.RB0 == 1)
    {
        LED = 0;
        tempo_100ms();
        LED = 1;
        tempo_100ms();
    }
}
void tempo_100ms(void) {

    for (int i = 0; i < 2; i++)
    {
        TMR0L = 61;

        INTCONbits.TMR0IF = 0;
        while(INTCONbits.TMR0IF == 0);
    }
}
