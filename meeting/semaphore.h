/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__

#include "waitingroom.h"

class Semaphore : public Waitingroom {
private:
    Semaphore(const Semaphore &copy); // Verhindere Kopieren
    int counter;
public:
    /**
     * Der Konstruktor initialisiert den Semaphorzähler mit dem angegebenen Wert c
     * @param c
     */
    Semaphore(int c) : counter(c) {}

    /**
     * Warteoperation: Sofern der Semaphorzähler größer als Null ist, wird er nur um eins erniedrigt.
     * Anderenfalls wird der aktuell laufende Prozess (ein Customer Objekt) an die Warteliste angefügt und blockiert.
     */
    void p();

    /**
     * Freigabeoperation: Wenn auf der Warteliste mindestens ein Customer eingetragen ist,
     * wird der erste davon aufgeweckt. Anderenfalls wird der Semaphorzähler um eins erhöht.
     */
    void v();

    /**
     * Diese Methode ist nur ein anderer Name für die Methode p ()
     */
    void wait() { this->p(); }

    /**
     * Diese Methode ist nur ein anderer Name für die Methode v ()
     */
    void signal() { this->v(); }

};

#endif
