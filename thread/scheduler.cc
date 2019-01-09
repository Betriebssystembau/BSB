/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#include "scheduler.h"

void Scheduler::ready(Entrant &that) {
    this->queue.enqueue((Chain * ) & that);
}

void Scheduler::schedule() {
    Chain *chain = this->queue.dequeue();
    Entrant *entrant = (Entrant *) chain;
    go(*entrant);
}

void Scheduler::exit() {
    this->currentEntrant = (Entrant * )
    this->queue.dequeue();
    Coroutine &cur = *this->currentEntrant;
    this->dispatch(cur);
}

void Scheduler::kill(Entrant &that) {
    this->queue.remove((Chain * ) & that);
}

void Scheduler::resume() {
    this->queue.enqueue((Chain * ) & this->currentEntrant);
    this->currentEntrant = (Entrant * )
    this->queue.dequeue();
    this->dispatch(*this->currentEntrant);
}