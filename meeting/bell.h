/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h"

class Bell : public Chain {
private:
    Bell(const Bell &copy); // Verhindere Kopieren
    int counter;
public:
    Bell() {}

    /**
     * Setzen des Zählers.
     * @param value
     */
    void wait(int value) { this->counter = value; }

    /**
     * Abfragen des Zählers.
     * @return
     */
    int wait() { return this->counter; }

    /**
     * Dekremementiert den Zähler.
     */
    void tick() { this->counter--; }

    /**
     * Liefert true, wenn die Zeit abgelaufen ist.
     * @return
     */
    bool run_down() { return counter <= 0; }

    /**
     * Wird vom Glöckner aufgerufen, wenn es an der Zeit ist.
     */
    virtual void ring() = 0;
};

#endif
