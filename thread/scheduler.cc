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
#include "guard/guard.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "thread/entrant.h"
#include "thread/idle.h"

extern CGA_Stream cga_stream;
extern Guard guard;
extern CPU cpu;

extern void *idleStack;
extern void *idleTos;

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
        if (!isThreadSleeping()) {
            cga_stream << "Scheduler: All threads finished!" << endl;
        } else {
            cga_stream << "Scheduler: No active Threads left, but somebody is sleeping!" << endl;
            Idle idle(idleTos);
            this->Scheduler::ready(idle);
            cga_stream << "Scheduler: Idling" << endl;
            this->schedule();
        }
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

    this->currentEntrant = (Entrant * ) this->queue.dequeue();
    if (this->currentEntrant) {
        this->dispatch(*this->currentEntrant);
    }
}

