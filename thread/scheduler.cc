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
    this->queue.enqueue(that);
}

void Schedular::schedule() {
    Chain chain = this->queue.dequeue();
    Entrant *entrant = (Entrant *) chain;
    entrant->go();
}

void Schedular::exit() {
    this->currentEntrant = (Entrant *) this->queue.dequeue();
    this->currentEntrant->go();
}

void Schedular::kill(Entrant &that) {
    this->queue.remove(that);
}

void Schedular::resume() {
    this->queue.enqueue(this->currentEntrant);
    this->currentEntrant = (Entrant *) this->queue.dequeue();
    this->currentEntrant->go();
}