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
    this->currentEntrant = (Entrant * )
    this->queue.dequeue();

    go(*this->currentEntrant);
}

void Scheduler::exit() {
    cga_stream << "Scheduler: Thread " << this->currentEntrant->name << " terminated" << endl;
    this->currentEntrant = (Entrant * ) this->queue.dequeue();
    if (!currentEntrant) {
        cga_stream << "Scheduler: All threads finished!" << endl;
        while(true);
    } else {
        cga_stream << "Scheduler: Next thread: " << this->currentEntrant->name << endl;
        this->dispatch(*this->currentEntrant);
    }
}

void Scheduler::kill(Entrant &that) {
    this->queue.remove((Chain * ) & that);
}

void Scheduler::resume() {
    this->queue.enqueue(this->currentEntrant);

    this->currentEntrant = (Entrant * )
            this->queue.dequeue();
    this->dispatch(*this->currentEntrant);
}