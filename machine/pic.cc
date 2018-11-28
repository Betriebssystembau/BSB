/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */
#include "pic.h"

void PIC::allow(int interrupt_device) {
    if (interrupt_device < 8) {
        char allowedInterrupts = masterUp.inb();
        allowedInterrupts &= ~(1 << interrupt_device);
        masterUp.outb(allowedInterrupts);
    } else {
        char allowedInterrupts = slaveUp.inb();
        allowedInterrupts &= ~(1 << interrupt_device - 8);
        slaveUp.outb(allowedInterrupts);
    }
}

void PIC::forbid(int interrupt_device) {
    if (interrupt_device < 8) {
        char allowedInterrupts = masterUp.inb();
        allowedInterrupts |= (1 << interrupt_device);
        masterUp.outb(allowedInterrupts);
    } else {
        char allowedInterrupts = slaveUp.inb();
        allowedInterrupts |= (1 << interrupt_device - 8);
        slaveUp.outb(allowedInterrupts);
    }
}

bool PIC::is_masked(int interrupt_device) {
    char allowedInterrupts;
    if (interrupt_device < 8) {
        allowedInterrupts = masterUp.inb();
        return (allowedInterrupts & (1 << interrupt_device)) != 0;
    } else {
        allowedInterrupts = slaveUp.inb();
        return (allowedInterrupts & (1 << interrupt_device - 8)) != 0;
    }
}