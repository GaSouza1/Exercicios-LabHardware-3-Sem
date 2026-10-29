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


void tempo_100ms (void);

void main(void) {
    ADCON1 = 0x0F; 
    TRISD = 0xF8;   // RD0?RD2 como saídas
    LATD = 0x00;

    T0CON = 0b11000111;
    while (1)
    {
        for (uint8_t valor = 0; valor <= 7; valor++)
        {
            LATD = (LATD & 0xF8) | valor;
            tempo_100ms();
        }
    }
   
}
void tempo_100ms (void) {
    TMR0L = 61;
     
    INTCONbits.TMR0IF = 0;
    while(INTCONbits.TMR0IF == 0);
    
}
