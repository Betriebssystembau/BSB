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
#include "device/cgastr.h"

extern CGA_Stream cga_stream;

void Scheduler::ready(Entrant &that) {
    this->queue.enqueue((Chain * ) & that);
}

void Scheduler::schedule() {
    Chain *chain = this->queue.dequeue();
    Entrant *entrant = (Entrant *) chain;
    go(*entrant);
}

void Scheduler::exit() {
    cga_stream << "Exit" << endl;
    this->currentEntrant = (Entrant* )
            this->queue.dequeue();
    this->dispatch(*this->currentEntrant);
}

void Scheduler::kill(Entrant &that) {
    this->queue.remove((Chain * ) & that);
}

void Scheduler::resume() {
    cga_stream << "Enqueueing" << (long) currentEntrant->regs.rsp << endl;
    this->queue.enqueue((Chain * ) this->currentEntrant);
    this->currentEntrant = (Entrant * )
            this->queue.dequeue();
    this->dispatch(*this->currentEntrant);
}