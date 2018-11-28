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

#include "guard.h"

void Guard::leave() {
    this->retne();
    Chain *currentChain;
    while ((currentChain = this->queue.dequeue()) != 0) {
        Gate *currentGate = (Gate *) currentChain;
        currentGate->queued(false);
        currentGate->epilogue();
    }
}

void Guard::relay(Gate *item) {
    if (this->avail()) {
        item->epilogue();
    } else if (!item->queued()) {
        this->queue.enqueue(item);
        item->queued(true);
    }
}