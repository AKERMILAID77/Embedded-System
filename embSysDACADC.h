//******************************************
#define _XTAL_FREQ 10000000
#pragma config CONFIG = 0x3D3A

#include <xc.h>
unsigned char mask = 0, i = 0, olD = 0;
unsigned char tCon = 0x8F;


int err = 0, oldErr = 0;
int vPr, vDi, vIn;
int dcMax = 245, dcMin = 5, dc = 5;

void calculer();

/*
 tCon = 28° 
*****************************
t =  28
v =  2.8000
D = 143
B = 0b10001111
B = 0x8F
 */