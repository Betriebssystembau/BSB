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

extern Plugbox plugbox;

void Keyboard::plugin() {
    PIC pic;

    plugbox.assign(33, *this);
    pic.allow(1);
    
}
 
void Keyboard::trigger() {
    CGA_Stream cga_stream;
    cga_stream.flush();
    Key key;
    key = key_hit();
    if (key.valid()) {
        cga_stream << (char)key;
    }
    cga_stream.flush();
}