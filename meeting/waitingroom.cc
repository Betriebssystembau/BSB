/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

#include "waitingroom.h"
#include "thread/customer.h"
#include "syscall/guarded_organizer.h"

extern Guarded_Organizer scheduler;

Waitingroom::~Waitingroom() {
    Customer *customer = (Customer *) this->dequeue();
    while (customer) {
        scheduler.wakeup(*customer);
        customer = (Customer *) this->dequeue();
    }
}

void Waitingroom::remove(Customer *customer) {
    customer->waiting_in(0);
    this->Queue::remove(customer);
}