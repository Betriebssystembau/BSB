/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab.                                                         */
/*****************************************************************************/

#ifndef __loop_include__
#define __loop_include__

#include "thread/coroutine.h"
#include "device/cgastr.h"
extern CGA_Stream cga_stream;
class Loop : public Coroutine {

    private:
        Loop(const Loop& loop);

        int start = 0;
        int end = 0;
    public:
        Loop(void* tos, int start, int end) : Coroutine(tos){
            cga_stream << "Loop constructor: " << start << "-" << end << endl;
            this->start = start;
            this->end = end;
        }

        void action();
};
#endif
