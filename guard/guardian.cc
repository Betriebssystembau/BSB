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
/* FUNKTIONEN */

extern "C" void guardian(unsigned int slot);
extern Plugbox plugbox;
extern Guard guard;
extern CPU cpu;
extern CGA_Stream cga_stream;
/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian(unsigned int slot) {
    cga_stream << "Int: " << slot << endl;
    cga_stream.flush();
    cpu.disable_int();
    bool epilogue = plugbox.report(slot).prologue();
    cpu.enable_int();
    if (epilogue) {
        guard.relay(&plugbox.report(slot));
    }
}