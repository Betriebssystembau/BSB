/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/

/* INCLUDES */
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "guard.h"
#include "machine/cpu.h"
#include "device/cgastr.h"
/* FUNKTIONEN */

extern CGA_Stream cga_stream;
extern "C" void guardian(unsigned int slot);
extern Plugbox plugbox;
extern Guard guard;
extern CPU cpu;
/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian(unsigned int slot) {
    //cpu.disable_int();
    //cga_stream << endl << slot;
    //cga_stream.flush();
    //cga_stream.setpos(0, 0);
    bool epilogue = plugbox.report(slot).prologue();
    //cpu.enable_int();
    if (epilogue) {
        guard.relay(&plugbox.report(slot));
    }
}