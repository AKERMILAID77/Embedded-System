/*
 * File:   testBroches.c
 * Author: hp
 *
 * Created on 26 septembre 2022, 09:57
 */

#define _XTAL_FREQ 2000000

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

#include <xc.h> 

void
main ()
{
  ADCON1 = 0x06;
  PORTA = 0x55;
  TRISA = 0x00;

  PORTB = 0x55;
  TRISB = 0x00;

  PORTC = 0x55;
  TRISC = 0x00;

  PORTD = 0x55;
  TRISD = 0x00;

  PORTE = 0x55;
  TRISE = 0x00;

  while (1)
    {
      PORTA = ~PORTA;
      PORTB = ~PORTB;
      PORTC = ~PORTC;
      PORTD = ~PORTD;
      PORTE = ~PORTE;

      __delay_ms (1000);
    }
}

