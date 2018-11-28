/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "device/keyboard.h"
#include "machine/cpu.h"

class Application {
private:
    Application(const Application &copy); // Verhindere Kopieren
    Keyboard keyboard;

public:
/* Hier muesst ihr selbst Code vervollstaendigen */
    Application() {
    }

    void action();
};

#endif
