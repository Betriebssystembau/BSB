/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__

#include "io_port.h"

class PIC
 {
private:
    PIC(const PIC &copy); // Verhindere Kopieren
    IO_Port masterLow;
    IO_Port masterUp;
    IO_Port slaveLow;
    IO_Port slaveUp;
    char allowedInterruptsMaster = 0;
    char allowedInterruptsSlave = 0;

public:
    PIC() : masterLow(0x20), masterUp(0x21), slaveLow(0xa0), slaveUp(0xa1) {}

    enum {
        timer    = 0,
        keyboard = 1
    };

    /**
     *  Lässt zu, dass der PIC Unterbrechungen des Geräts Nummer interrupt_device an den Prozessor weiterleitet.
     */
    void allow (int interrupt_device);

    /**
     * Verhindert, dass der PIC Unterbrechungen des Geräts Nummer interrupt_device an den Prozessor weiterleitet.
     * @param interrupt_device
     */
    void forbid (int interrupt_device);

    /**
     * Gibt den Zustand des Maskierbits von interrupt_device zurück. Wenn Unterbrechungen dieses Geräts nicht an die CPU weitergeleitet werden, soll true zurückgegeben werden, andernfalls false.
     * @param interrupt_device
     * @return
     */
    bool is_masked (int interrupt_device);
};

#endif
