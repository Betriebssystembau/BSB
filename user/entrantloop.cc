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
        cga_stream << this->name << ": my next number is: " << i << endl;
        sum += i;
    }
    cga_stream << this->name
               << ": Sum from " << start << " to " << end << " is " << sum << endl;
    if (this->threadToKill != 0) {
        cga_stream << this->name << ": Kill it with fire: " << this->threadToKill -> name << endl;
        scheduler.kill(*this->threadToKill);
    }
    scheduler.exit();
}

