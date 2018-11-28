/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */
/* Hier muesst ihr selbst Code vervollstaendigen */
#include "panic.h"
#include "cgastr.h"
#include "machine/cpu.h"

extern CGA_Stream cga_stream;

void Panic::trigger() {
    cga_stream << "FEUER!!!!";
    cga_stream.flush();

    CPU cpu;
    cpu.halt();
}