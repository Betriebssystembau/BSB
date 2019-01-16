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

extern CGA_Stream cga_stream;
extern Guarded_Scheduler scheduler;

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
    scheduler.Scheduler::resume();
}