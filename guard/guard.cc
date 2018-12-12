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
#include "guard/secure.h"


extern CPU cpu;

void Guard::leave() {
    Chain *currentChain;
    cpu.disable_int();
    while ((currentChain = this->queue.dequeue()) != 0) {
        Gate *currentGate = (Gate *) currentChain;
        currentGate->queued(false);
        cpu.enable_int();
        currentGate->epilogue();
        cpu.disable_int();
    }
    this->retne();
    cpu.enable_int();
}

void Guard::relay(Gate *item) {
    if (this->avail()) {
        cpu.enable_int();
        {
            Secure epi;
            item->epilogue();
        }
    } else if (!item->queued()) {
        //cpu.disable_int();
        this->queue.enqueue(item);
        item->queued(true);
        cpu.enable_int();
    }
}