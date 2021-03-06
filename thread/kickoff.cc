/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K I C K O F F                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Funktion zum Starten einer Koroutine.                                     */
/* Da diese Funktion nicht wirklich aufgerufen, sondern nur durch eine       */
/* geschickte Initialisierung des Stacks der Koroutine angesprungen wird,    */
/* darf sie nie terminieren. Anderenfalls wuerde ein sinnloser Wert als      */
/* Ruecksprungadresse interpretiert werden und der Rechner abstuerzen.       */
/*****************************************************************************/


#include "coroutine.h"
#include "kickoff.h"
#include "machine/cpu.h"
#include "device/cgastr.h"
#include "guard/guard.h"
extern CPU cpu;
extern CGA_Stream cga_stream;
extern Guard guard;
/**
 * Diese Methode realisiert den Sprung von der C Ebene zur C++ Ebene,
 * indem sie ganz einfach die Methode action() des als Parameter vorgefundenen Koroutinenobjektes object aufruft.
 * @param dummy1
 * @param dummy2
 * @param dummy3
 * @param dummy4
 * @param dummy5
 * @param dummy6
 * @param object
 */
void kickoff(void *dummy1, void *dummy2, void *dummy3, void *dummy4, void *dummy5, void *dummy6, void *object) {
    guard.leave();
    ((Coroutine*) object)->action();
    while (true);
}
