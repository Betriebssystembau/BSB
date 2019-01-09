/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* EntrantLoop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab.                                                         */
/*****************************************************************************/

#ifndef __entrantloop_include__
#define __entrantloop_include__

#include "thread/coroutine.h"
#include "device/cgastr.h"
#include "thread/entrant.h"
extern CGA_Stream cga_stream;
class EntrantLoop : public Entrant {

    private:
        EntrantLoop(const EntrantLoop& loop);

        int start = 0;
        int end = 0;
        int stop = 0;
        char* name = "";
        EntrantLoop* threadToKill = 0;
    public:
        EntrantLoop(void* tos, int start, int end, int stop, char* name) : Entrant(tos){
            this->start = start;
            this->end = end;
            this->stop = stop;
            this->name = name;
        };

        void setThreadToKill(EntrantLoop* toKill) {
            this->threadToKill = toKill;
        };

        void action();
};
#endif
