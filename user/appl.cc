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
    resume(*(loop));
    while(true);
}
