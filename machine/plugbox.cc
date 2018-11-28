/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */
#include "plugbox.h"

Plugbox::Plugbox() {
    for (int i = 0; i < 64; i++) {
        this->gates[i] = &this->panic;
    }
}

void Plugbox::assign(unsigned int slot, Gate &gate) {
    if (slot < 64) {
        this->gates[slot] = &gate;
    }
}

Gate &Plugbox::report(unsigned int slot) {
    if (slot < 64) {
        return *this->gates[slot];
    } else {
        return this->panic;
    }
}