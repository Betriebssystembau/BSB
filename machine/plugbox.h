/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"

class Plugbox
 {
private:
    Panic panic;
    /**
     * Interrupt-Nummer des Timer Bausteins
     */
    const int timer = 32;
    /**
     * Interrupt-Nummer der Tastatur
     */
    const int keyboard = 33;

    Gate *gates[64];
    /**
      * Im Konstruktor wird für alle Unterbrechungen und Ausnahmen das global bekannte Panic-Objekt panic eingetragen, das eine minimale Unterbrechungsbehandlung sicherstellt.
      * @param copy
      */

 public:
     Plugbox ();
    Plugbox(const Plugbox &copy);

    /**
     * Mit dieser Methode kann das Objekt einer spezialisierten Unterbrechungsbehandlung gate zu der Unterbrechung Nummer slot in die Plugbox eingetragen werden.
     * @param slot
     * @param gate
     */
    void assign (unsigned int slot, Gate& gate);

    /**
     * Hiermit kann das Gate-Objekt abgefragt werden, das zu der Unterbrechung Nummer slot in die Plugbox eingetragen wurde.
     * @param slot
     * @return
     */
    Gate& report (unsigned int slot);

 };

#endif
