/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

#include "guarded_organizer.h"
#include "guard/secure.h"

void Guarded_Organizer::ready(Thread &that) {
    Secure secure;
    this->Organizer::ready(that);
}

void Guarded_Organizer::exit() {
    Secure secure;
    this->Organizer::exit();
}

void Guarded_Organizer::kill(Thread &that) {
    {
        Secure secure;
        this->kill(that);
    }
}

void Guarded_Organizer::resume() {
    Secure secure;
    this->resume();
}
