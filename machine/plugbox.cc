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

Plugbox::Plugbox(){
    for(int i= 0; i < 64; i++){
        Panic *panic;
        this->gates[i] = panic;
    }
}

void Plugbox::assign (unsigned int slot, Gate& gate){
    this->gates[slot] = &gate;
}

Gate& Plugbox::report (unsigned int slot){
    this->gates[slot]->trigger();
}