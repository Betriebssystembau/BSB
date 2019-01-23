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

extern Guarded_Organizer scheduler;

void Semaphore::p() {
    if (this->counter > 0) {
        this->counter--;
    } else {
        scheduler.block(*scheduler.getCurrentCustomer(), *this);
    }
}

void Semaphore::v() {
    Customer *customer = (Customer *) this->dequeue();
    if (customer) {
        this->counter++;
    } else {
        scheduler.wakeup(*customer);
    }
}