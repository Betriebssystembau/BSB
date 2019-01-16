/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#include "guarded_semaphore.h"

void Guarded_Semaphore::p() {
    Secure secure;
    this->Semaphore::p();
}

void Guarded_Semaphore::v() {
    Secure secure;
    this->Semaphore::v();
}

void Guarded_Semaphore::wait() {
    Secure secure;
    this->Semaphore::wait();

}

void Guarded_Semaphore::signal() {
    Secure secure;
    this->Semaphore::signal();
}
