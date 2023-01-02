#include "embSysDACADC.h"

void
main ()
{
  // RE0: Retour de la comparaison
  ADCON1 = 0x06;
  TRISE0 = 1;


  // RC2: Alimentation du moteur
  TRISC2 = 0;

  PORTB = 0x00;
  TRISB = 0x00;

  PORTD = 0x00;
  TRISD = 0x00;

  // Period: T = (PR2 + 1 ) × 4 × Tosc × prediv
  PR2 = 0xFF;

  // Duty Cycle: D = CCPR1L × 4 × Tosc × prediv, D = Dxy × T_osc × prediv
  CCP1X = 0;
  CCP1Y = 0;
  CCPR1L = (dc & 0xFF);
  CCP1M3 = 1;
  CCP1M2 = 1;

  // Timer2
  T2CKPS0 = 0;
  T2CKPS1 = 0;
  TMR2ON = 1;


  //initialiser
  i = 0;
  mask = 0x80;
  PORTB = 0x00;

  while (1)
    {
      // Lire tCon
      tCon = 0x8F;

      PORTB = PORTB | mask; //DAC++
      __delay_ms (5); //Time to convert

      if (RE0) PORTB = (PORTB & ~mask); //DAC--
      mask = mask >> 1;
      i++;

      if (i > 7)
        {
          i = 0;
          mask = 0x80;

          calculer ();
          PORTB = 0x00;

        }
    }
}

void
calculer ()
{
  // Consigne tCon
  // Mesure POERTD
  PORTD = PORTB;
  // Erreur inversée (le moteur diminue la temperature)
  err = (PORTD & 0x00FF)-(tCon & 0x00FF);

  // valeur proportionnelle
  vPr = err;
  // valeur dirrivée
  vDi = err - oldErr;
  // valeur integrale
  vIn = vIn + err;

  // PID
  dc = (vPr<<2) + (vDi<<1) + (vIn<<2);

  // ecriire l'erreur
  oldErr = err;

  // appliquer
  if (dc > dcMax) dc = dcMax;
  if (dc < dcMin) dc = dcMin;

  CCPR1L = (dc & 0xFF);
}
