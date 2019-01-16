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


Waitingroom::~Waitingroom() {
    Customer *customer = (Customer *) this->dequeue();
    customer->resume();
}

void Waitingroom::remove(Customer *customer) {
    this->Queue::remove(customer);
}