/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine Koroutine, die vom Scheduler verwaltet wird.                         */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

#include "thread/coroutine.h"
#include "object/chain.h"

class Entrant: public Chain, public Coroutine {
private:
    Entrant(const Entrant &copy); // Verhindere Kopieren

public:
    /**
     * Der Entrant Konstruktor gibt nur den Parameter tos an den Coroutinen Konstruktor weiter.
     * @param tos
     */
    Entrant(void *tos) : Chain(), Coroutine(tos){};
};

#endif
