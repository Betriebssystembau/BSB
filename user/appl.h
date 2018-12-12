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
#include "thread/coroutine.h"

class Application : public Coroutine {
private:
    Application(const Application &copy); // Verhindere Kopieren
    Keyboard keyboard;

public:

    /**
     * Der Konstruktor gibt dem Anwendungsprozess einen Stack. Dabei muss tos bereits auf das Ende des Stacks zeigen, da Stacks beim PC von den hohen zu den niedrigen Adressen wachsen.
     * @param tos
     */
    Application(void *tos);

    /**
     * Diese Methode enthält die Aktion der Anwendung.
     */
    void action();
};

#endif
