/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"
#include "device/cgastr.h"

extern CGA_Stream cga_stream;

class PIT {
private:
    PIT(const PIT &copy); // Verhindere Kopieren

    const int tick_length_us = 838;

    int us;

public:
    PIT(int us) {
        cga_stream << "PIT Constr." << endl;
        interval(us);
    }

    int interval() {
        return this->us;
    }

    void interval(int us);
};

#endif
