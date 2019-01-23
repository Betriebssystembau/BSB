/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include "semaphore.h"
#include "syscall/guarded_organizer.h"
#include "device/cgastr.h"

extern Guarded_Organizer scheduler;
extern CGA_Stream cga_stream;

void Semaphore::p() {
    if (this->counter > 0) {
        this->counter--;
    } else {
        cga_stream << "p: " << scheduler.active() << endl;
        scheduler.block((Customer &) *scheduler.active(), *this);
    }
}

void Semaphore::v() {
    Customer *customer = (Customer *) this->dequeue();
    if (customer) {
        scheduler.wakeup(*customer);
    } else {
        this->counter++;
    }
}