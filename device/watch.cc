/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include "watch.h"

#include "device/cgastr.h"
#include "meeting/bellringer.h"

extern CGA_Stream cga_stream;
extern Guarded_Scheduler scheduler;
extern Bellringer bellringer;

void Watch::plugin() {
    plugbox.assign(plugbox.timer, *this);
}

void Watch::windup() {
    pic.allow(PIC::timer);
}

bool Watch::prologue() {
    return true;
}

void Watch::epilogue() {
    bellringer.check();
    scheduler.Scheduler::resume();
}