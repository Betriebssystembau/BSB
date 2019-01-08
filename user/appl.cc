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
#include "user/loop.h"
#include "device/cgastr.h"
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */

/* GLOBALE VARIABLEN */

extern CGA_Stream cga_stream;
extern CPU cpu;

void Application::action() {
    cga_stream << "App action called!" << endl;
    void* loop_stack[64];
    void* loop_tos = &loop_stack[63];
    cga_stream << "Creating Loop app" << endl;
    Loop loop(loop_tos, 0, 9);
    this->resume(loop);
    while(true);
}
