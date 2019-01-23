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
#include "syscall/guarded_organizer.h"
#include "guard/secure.h"
#include "syscall/guarded_semaphore.h"

extern CGA_Stream cga_stream;
extern Guarded_Organizer scheduler;

void EntrantLoop::action() {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        {
            Secure secure;
            int x = -1;
            int y = -1;
            cga_stream.getpos(x, y);
            cga_stream.setpos(0, row);
            cga_stream << this->name << ": my next number is: " << i << endl;
            cga_stream.setpos(x,y);
        }
        sum += i;

        if (threadToKill && i == 500) {
            scheduler.Organizer::block(*threadToKill, *this->waitingroomToBlock);
        }

    }
    {
        Secure secure;
        cga_stream << this->name
               << ": Sum from " << start << " to " << end << " is " << sum << endl;
    }
    scheduler.exit();
}

