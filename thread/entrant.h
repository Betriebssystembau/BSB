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

#include "coroutine.h"

/* Hier muesst ihr selbst Code vervollstaendigen */

class Entrant : public Chain, public Coroutine
/* Hier muesst ihr selbst Code vervollstaendigen */
{
private:
    Entrant(const Entrant &copy); // Verhindere Kopieren

public:
    /**
     * Der Entrant Konstruktor gibt nur den Parameter tos an den Coroutinen Konstruktor weiter.
     * @param tos
     */
    Entrant(void *tos);
};

#endif
