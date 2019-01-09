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
#include "machine/toc.h"
#include "guard/secure.h"
#include "thread/dispatch.h"

/* GLOBALE VARIABLEN */

extern Dispatcher dispatcher;
extern CGA_Stream cga_stream;
extern CPU cpu;

void Application::action() {
    void* loop_stack[64];
    void* loop_tos = &loop_stack[63];
    Loop loop_app(loop_tos, 0, 9);
    dispatcher.dispatch(loop_app);
}
