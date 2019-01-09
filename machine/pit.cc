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
    IO_Port counter0Low(0x40);
    IO_Port controlLow(0x43);

    if (us < 0) {
        return;
    }
    this->us = us;

    char ctrlByte = 0b00110100;
    int ticks = ((us * 1000 + 500) / tick_length_us);

    if (ticks >= 65536) {
        ticks = 65535;
    }

    int lsb = ticks % 256;
    int msb = ticks / 256;

    controlLow.outb(ctrlByte);
    counter0Low.outb(lsb);
    counter0Low.outb(msb);
}