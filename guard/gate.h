/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

class Gate : public Chain {
private:
    bool isQueued;


public:
    /**
     * Prolog der Unterbrechungsbehandlung. Ein Rückgabewert true zeigt an, dass der zugehörige Epilog ausgeführt werden soll.
     * @return
     */
    virtual bool prologue() = 0;

    /**
     * Epilogue der Unterbrechungsbehandlung.
     */
    virtual void epilogue() = 0;

    /**
     * Speichert, ob das jeweilige Objekt sich gerade in einer Epilog-Warteschlange befindet.
     * @param q
     */
    void queued(bool q) {
        this->isQueued = q;
    }

    /**
     * Methode zum Abfragen, ob sich das jeweilige Objekte gerade in einer Epilog-Warteschlange befindet.
     * @return
     */
    bool queued() { return this->isQueued; }
};

#endif
