/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        G U A R D E D _ B U Z Z E R                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Schnittstelle von Anwendungsthreads zu Buzzer-Objekten.                   */
/*****************************************************************************/

/* INCLUDES */

#include "syscall/guarded_buzzer.h"

Guarded_Buzzer::~Guarded_Buzzer() {
    Secure secure;
    this->Buzzer::~Buzzer();
}

void Guarded_Buzzer::set(int ms) {
    Secure secure;
    this->Buzzer::set(ms);
}

void Guarded_Buzzer::sleep() {
    Secure secure;
    this->Buzzer::sleep();
}
