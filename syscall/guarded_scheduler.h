/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S C H E D U L E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__

/* Hier muesst ihr selbst Code vervollstaendigen */

class Guarded_Scheduler
/* Hier muesst ihr selbst Code vervollstaendigen */
{
private:
    Guarded_Scheduler(const Guarded_Scheduler &copy); // Verhindere Kopieren
public:
    Guarded_Scheduler() {}


    /**
     * Mit dieser Methode wird der Prozess that beim Scheduler angemeldet.
     * @param that
     */
    void ready(Thread &that);

    /**
     * Hiermit kann sich ein Prozess selbst beenden.
     */
    void exit();

    /**
     * Mit dieser Methode kann ein Prozess einen anderen (that) beenden.
     * @param that
     */
    void kill(Thread &that);

    /**
     * Hiermit kann ein Prozesswechsel ausgelöst werden.
     */
    void resume();
};

#endif
