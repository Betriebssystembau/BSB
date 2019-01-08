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
#include "machine/toc.h"
#include "guard/secure.h"
/* Hier muesst ihr selbst Code vervollstaendigen */

/* GLOBALE VARIABLEN */


extern CGA_Stream cga_stream;
extern CPU cpu;
extern void *tos;

/* Hier muesst ihr selbst Code vervollstaendigen */

void Application::action() {
    cga_stream << "Application action" << endl;
    Counter counter((void *) this->stack_start, 'a');
    cga_stream << "counter nach konstruktor:" << endl;
    void **sp = (void **) counter.regs->rsp;
    cga_stream << "sp[0]: kickoff " << (long) sp[0] << endl;
    //cga_stream << "sp[1]: return " << (long) sp[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp[2] << endl;
    // Counter counter2((void *) this->stack_start, 'b');
    //while (true) {
    this->resume(counter);
    //this->resume(counter2);
    //}
}
