/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab. Der Scheduler bestimmt dann, welcher Thread als         */
/* naechstes laufen soll.                                                    */
/*****************************************************************************/

#include "user/loop.h"
#include "device/cgastr.h"

extern CGA_Stream cga_stream;



void Loop::action() {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    cga_stream << "Sum from " << start << " to " << end << " is " << sum << endl;
}

