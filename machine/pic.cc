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

void PIC::allow (int interrupt_device){
    if(interrupt_device < 8) {
        this->allowedInterruptsMaster |= (1 << interrupt_device);
        masterUp.outb(this->allowedInterruptsMaster);
    } else {
        this->allowedInterruptsSlave |= (1 << interrupt_device - 8);
        slaveUp.outb(this->allowedInterruptsSlave);
    }
}

void PIC::forbid (int interrupt_device){

}

bool PIC::is_masked (int interrupt_device){

}