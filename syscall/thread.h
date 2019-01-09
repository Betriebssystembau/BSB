/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Benutzerschnittstelle eines Threads.                                      */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

#include "thread/entrant.h"

/* Hier muesst ihr selbst Code vervollstaendigen */

class Thread : public Entrant
/* Hier muesst ihr selbst Code vervollstaendigen */

{
private:
    Thread(const Thread &copy); // Verhindere Kopieren

    /**
     * Der Konstruktor leitet den Parameter tos an den Konstruktor der Basisklasse Entrant weiter.
     * @param tos
     */
    Thread(void *tos) : Entrant(tos) {}
};

#endif
