/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

#include "organizer.h"

void Organizer::block(Customer &customer, Waitingroom &waitingroom) {
    customer.waiting_in(waitingroom);
    waitingroom.queue(customer);
    this->currentEntrant = (Entrant * ) this->queue.dequeue();
    this->dispatch(*this->currentEntrant);
}

void Organizer::wakeup(Customer &customer) {
    customer.waiting_in(0);
    this->ready(customer);
}

void Organizer::kill(Customer &that) {
    this->Scheduler::kill(that);
    //TODO: that aus waitingromm entfernen
}