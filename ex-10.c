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


#define _XTAL_FREQ 4000000UL

volatile unsigned char passo = 0;

void __interrupt() ISR(void)
{
    if (INTCONbits.TMR0IF)
    {
        INTCONbits.TMR0IF = 0;
        TMR0L = 256 - 10; // 10 * 4 microS = 40 mS
        LATDbits.LATD0 = (passo < 33);
        
        passo++;
        if (passo >= 100)
            passo = 0;
    }
}

void main(void) {
    ADCON1 = 0x0F; 
    TRISDbits.TRISD0 = 0;   // RD0 como saída
    LATDbits.LATD0 = 0;

    T0CON = 0b11000001;
    
    TMR0 = 256 - 10;
    
    INTCONbits.TMR0IE = 1; // Evento de interrupção Timer0
    INTCONbits.GIE = 1; // Evento de interrupção global
    
    while (1);
   
}

