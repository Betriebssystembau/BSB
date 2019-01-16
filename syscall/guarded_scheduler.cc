/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

#include "guarded_scheduler.h"

void Guarded_Scheduler::ready(Thread &that) {
    {
        if (!guard.avail()) {
            guard.leave();
        }
        Secure secure;
        this->Scheduler::ready(that);
    }
}

void Guarded_Scheduler::exit() {
    {
        if (!guard.avail()) {
            guard.leave();
        }
        Secure secure;
        this->Scheduler::exit();
    }
}


void Guarded_Scheduler::kill(Thread &that) {
    {
        if (!guard.avail()) {
            guard.leave();
        }

        Secure secure;
        this->Scheduler::kill(that);
    }
}

void Guarded_Scheduler::resume() {
    {
        if (!guard.avail()) {
            guard.leave();
        }

        Secure secure;
        this->Scheduler::resume();
    }
}