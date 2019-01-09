/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */

#include "pit.h"

void PIT::interval(int us) {
    if (us < 0) {
        return;
    }
    if (us >= 65536) {
        us = 65535;
    }
    this->us = us;

    char ctrlByte = 00110100;
    float ticksFloat = (us /tick_length_us) + 0.5;
    int ticks = ticksFloat;

    int lsb = ticks % 256;
    int msb = ticks / 256;

    controlLow.outb(ctrlByte);
    counter0Low.outb(lsb);
    counter0Low.outb(msb);
}