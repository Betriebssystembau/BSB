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

void Watch::plugin() {
    plugbox.assign(plugbox.timer, *this);
}

void Watch::windup() {
    pic.allow(pic.timer);
}

bool Watch::prologue() {
    while (true);
}

void Watch::epilogue() {
}