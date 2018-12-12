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
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */

/* GLOBALE VARIABLEN */

extern CGA_Stream cga_stream;
extern CPU cpu;

/* Hier muesst ihr selbst Code vervollstaendigen */

void Application::action() {
    Keyboard keyboard;
    keyboard.plugin();
    cpu.enable_int();
    while (true) {
        {
            //Secure secure;
            //cga_stream.setpos(0, 0);
            cga_stream << "Test42";
            //cga_stream.setpos(0, 0);
            cga_stream.flush();
        }
    }
}
