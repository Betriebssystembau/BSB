/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "dispatch.h"
#include "object/queue.h"
#include "thread/entrant.h"
#include "object/list.h"
#include "meeting/waitingroom.h"

/* Hier muesst ihr selbst Code vervollstaendigen */

class Scheduler : public Dispatcher
/* Hier muesst ihr selbst Code vervollstaendigen */
{
private:
    Scheduler(const Scheduler &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
protected:
    Queue queue;
    Entrant *currentEntrant;
    List* waitingRooms;

public:
    Scheduler() {
        
    };
    /**
    * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet. Er wird an das Ende der Ready-Liste angefügt.
    */
    void ready(Entrant &that);

    /**
     * Diese Methode setzt das Scheduling in Gang,
     * indem der erste Prozess von der Ready-Liste entfernt und aktiviert wird.
     */
    void schedule();

    /**
     * Hiermit kann sich ein Prozess selbst beenden.
     * Er wird nun nicht wieder an das Ende der Ready-Liste angefügt.
     * Statt dessen wird nur der erste Prozess von der Ready-Liste heruntergenommen und aktiviert.
     */
    void exit();

    /**
     * Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
     * Der Prozess that wird einfach von der Ready-Liste entfernt und erhält somit nie wieder den Prozessor.
     * @param that
     */
    void kill(Entrant &that);

    /**
     * Hiermit kann ein Prozesswechsel ausgelöst werden, ohne dass der aufrufende Entrant wissen muss, welche anderen
     * Entrant Objekte im System existieren und welcher davon sinnvollerweise aktiviert werden sollte.
     * Diese Entscheidung trifft der Scheduler anhand der Einträge seiner Ready-Liste.
     * Im derzeitigen System soll er den gerade laufenden Prozess an das Ende
     * der Ready-Liste anfügen und den ersten aktivieren.
     */
    void resume();

    /**
     * Übergibt dem Scheduler eine Liste von Waitingrooms um zu prüfen,
     * ob noch schlafende Threads vorhanden sind;
     */
    void setWaitingRooms(List* waitingRooms) {
        this->waitingRooms = waitingRooms;
    }

    /**
     * Prüft ob noch geblockte Threads vorhanden sind.
     */
    bool isThreadSleeping() {
        Waitingroom* current = (Waitingroom*)this->waitingRooms->first();
        if (!current) {
            return false;
        }
        Waitingroom* next = (Waitingroom*) current->next;
        do {
            if (! current->isEmpty()) {
                return true;
            }
            current = next;
            next = (Waitingroom*) current->next;
        } while(next);
        return false;
    }
};

#endif
