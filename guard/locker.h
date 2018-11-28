/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Locker implementiert eine Sperrvariable, die verwendet wird,   */
/* um kritische Abschnitte zu schuetzen. Die Variable zeigt allerdings nur   */
/* an, ob der kritische Abschnitt frei ist. Ein eventuelles Warten und der   */
/* Schutz der fuer diese Klasse notwendigen Zaehlfunktion muss ausserhalb    */
/* erfolgen.                                                                 */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__


/*
    Die Methoden der Klasse sind so kurz, dass sie am besten inline definiert werden sollten.
    Doppelte enter- oder retne-Aufrufe (d.h. Betreten des kritischen Abschnitts aus dem kritischen Abschnitt heraus bzw. doppeltes Verlassen ebendieses) sind oft Zeichen für Implementierungsfehler im Betriebssystem. Es kann sich lohnen, in diesem Fall eine Fehlermeldung auszugeben und das System anzuhalten.
*/

#include "device/panic.h"

class Locker {
private:
    Locker(const Locker &copy); // Verhindere Kopieren

    bool isFree;
public:
    /**
     * Initialisiert die Sperrvariable so, dass der kritische Abschnitt als frei markiert wird.
     */
    Locker() {
        this->isFree = true;
    }

    /**
     * Diese Methode muss aufgerufen werden, wenn der kritische Abschnitt betreten wird.
     */
    void enter() {
        if (!this->isFree) {
            Panic panic;
            panic.prologue();
        }
        this->isFree = false;
    }

    /**
     * Mit dieser Methode wird der kritische Abschnitt wieder verlassen.
     */
    void retne() {
        if (this->isFree) {
            Panic panic;
            panic.prologue();
        }
        this->isFree = true;
    }

    /**
     * Diese Methode gibt an, ob der kritische Abschnitt frei ist.
     * @return
     */
    bool avail() {
        return this->isFree;
    }
};

#endif
