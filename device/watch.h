/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#ifndef __watch_include__
#define __watch_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/pit.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

class Watch : public Gate, public PIT {
private:
    Watch(const Watch &copy); // Verhindere Kopieren
public:
    /**
     * Initialisiert die Uhr.
    */
    Watch(int us) : PIT(us) {

    }

    /**
    * "zieht die Uhr auf". Danach laeuft sie los und loest in
    * regelmaessigen Abstaenden Unterbrechungen aus.
    */
    void windup();

    /**
     * Prologue der Uhrenunterbrechung
     */
    bool prologue();

    /**
     * Epilogue der Uhrenunterbrechung
     */
    void epilogue();
};

#endif
