/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Dispatcher.                                           */
/* Der Dispatcher verwaltet den life-Pointer, der die jeweils aktive         */
/* Koroutine angibt. mit go() wird der life Pointer initialisiert und die    */
/* erste Koroutine gestartet, alle weiteren Kontextwechsel werden mit        */
/* dispatch() ausgeloest. active() liefert den life Pointer zurueck.         */
/*****************************************************************************/
#include "thread/dispatch.h"

    Dispatcher::Dispatcher() {
        this->life = 0;
    }

    /**
     * Mit dieser Methode wird die Koroutine first im Life-Pointer vermerkt und gestartet.
     * @param first
     */
    void Dispatcher::go(Coroutine &first) {
        this->life = &first;
        this->life->go();

    }

    /**
     * Diese Methode setzt den Life-Pointer auf next und führt einen Koroutinenwechsel
     * vom alten zum neuen Life-Pointer durch.
     * @param next
     */
    void Dispatcher::dispatch(Coroutine &next) {
        Coroutine* old = this->life;
        this->life = &next;
        old->resume(*this->life);

    }

    /**
     * Hiermit kann abgefragt werden, welche Koroutine gerade im Besitz des Prozessors ist.
     * @return
     */
    Coroutine* Dispatcher::active() {
        return this->life;
    }
