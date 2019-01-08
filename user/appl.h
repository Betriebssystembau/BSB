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

#include "user/loop.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "machine/cpu.h"
#include "thread/coroutine.h"

extern CGA_Stream cga_stream;

class Application : public Coroutine {
private:
    Application(const Application &copy); // Verhindere Kopieren
    Keyboard keyboard;
    Loop* loop;
public:

    /**
     * Der Konstruktor gibt dem Anwendungsprozess einen Stack. Dabei muss tos bereits auf das Ende des Stacks zeigen, da Stacks beim PC von den hohen zu den niedrigen Adressen wachsen.
     * @param tos
     */
    Application(void *tos, Loop* loop) : Coroutine(tos) {
        cga_stream << "App constructor called" << endl;
        this->loop = loop;
    }

    /**
     * Diese Methode enthält die Aktion der Anwendung.
     */
    void action();
};

#endif
