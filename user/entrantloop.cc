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

#include "user/entrantloop.h"
#include "device/cgastr.h"
#include "thread/scheduler.h"

extern CGA_Stream cga_stream;
extern Scheduler scheduler;

void EntrantLoop::action() {
    cga_stream << this->name << ": Starting to count" << endl;
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
        if (i == stop) {
            cga_stream << this->name << ": Pausing, let the others do some work" << endl;
            scheduler.resume();
            cga_stream << this->name << ": Resumed" << endl;
        }
    }
    cga_stream << this->name
            << ": Sum from " << start << " to " << end << " is " << sum << endl;
    scheduler.exit();
}

