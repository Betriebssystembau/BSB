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
#include "syscall/thread.h"
#include "thread/customer.h"

extern CGA_Stream cga_stream;

class EntrantLoop : public Customer {

private:
    EntrantLoop(const EntrantLoop &loop);

    int start = 0;
    int end = 0;
    int stop = 0;
    int row = -1;
    EntrantLoop *threadToKill = 0;
    Waitingroom* waitingroomToBlock;
public:
    EntrantLoop(void *tos, int start, int end, int stop, char *name, int row) : Customer(tos) {
        this->start = start;
        this->end = end;
        this->stop = stop;
        this->name = name;
        this->row = row;
    };

    void setThreadToKill(EntrantLoop *toKill) {
        this->threadToKill = toKill;
    };

    void setWaitingRoom(Waitingroom* waitingroom) {
        this->waitingroomToBlock = waitingroom;
    }

    void action();
};

#endif
