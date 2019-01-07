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
#include "user/counter.h"
#include "device/cgastr.h"
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */

/* GLOBALE VARIABLEN */


extern CGA_Stream cga_stream;
extern CPU cpu;

/* Hier muesst ihr selbst Code vervollstaendigen */

void Application::action() {
    cga_stream << "Application action" << endl;
    while(true);
    //Counter counter((void*) this->stack_start, 'a');
    //this->resume(counter);

    //Counter counter2((void*) this->stack_start, 'n');
    
}
