/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#ifndef __Guard_include__
#define __Guard_include__

#include "locker.h"
#include "gate.h"
#include "object/queue.h"

/* Hier muesst ihr selbst Code vervollstaendigen */

class Guard : public Locker {
private:
    Guard(const Guard &copy); // Verhindere Kopieren
    Queue queue;
public:
    Guard() {}
/* Hier muesst ihr selbst Code vervollstaendigen */

    /**
     * Mit dieser Methode wird der kritische Abschnitt verlassen und die angestauten Epiloge werden abgearbeitet.
     */
    void leave();

    /**
     * Diese Methode wird von guardian () aufgerufen, falls der zuvor ausgeführte Prolog durch einen Rückgabewert true
     * angezeigt hat, dass sein Epilog ausgeführt werden soll. Ob der Epilog sofort behandelt oder zunächst nur in die
     * Epilogliste eingehängt wird, hängt davon ab, ob der kritische Abschnitt frei oder besetzt ist.
     * @param item
     */
    void relay(Gate *item);

};

#endif
