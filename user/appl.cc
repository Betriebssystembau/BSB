/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */

/* GLOBALE VARIABLEN */

extern CGA_Stream cga_stream;

/* Hier muesst ihr selbst Code vervollstaendigen */

void Application::action() {
    Keyboard keyboard;
    keyboard.plugin();
    CPU cpu;
    cpu.enable_int();
    while (true) {
        cga_stream.setpos(0, 0);
        cga_stream << "Testausgabe";
        cga_stream.setpos(0, 0);
        cga_stream.flush();
    }
}
