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

    IO_Port counter0Low;
    IO_Port counter0High;
    IO_Port counter1Low;
    IO_Port counter1High;
    IO_Port counter2Low;
    IO_Port counter2High;
    IO_Port controlLow;
    IO_Port controlHigh;

    const float tick_length_us = 0.833;

    int us;

public:
    PIT(int us) : counter0Low(0x40), counter0High(0x48),
                  counter1Low(0x41), counter1High(0x49),
                  counter2Low(0x42), counter2High(0x4a),
                  controlLow(0x43), controlHigh(0x4b) {
        cga_stream << "PIT Constr." << endl;
        interval(us);
    }

    int interval() {
        return this->us;
    }

    void interval(int us);
};

#endif
