/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#include "device/cgastr.h"
#include "device/keyboard.h"
#include "machine/pic.h"
#include "machine/plugbox.h"

extern CGA_Stream cga_stream;
extern Plugbox plugbox;
extern PIC pic;

void Keyboard::plugin() {
    plugbox.assign(33, *this);
    pic.allow(PIC::keyboard);
}

void Keyboard::trigger() {
    cga_stream.flush();
    Key key;
    key = key_hit();
    if (key.valid()) {
        cga_stream << (unsigned char) key;
    }
    cga_stream.flush();
}