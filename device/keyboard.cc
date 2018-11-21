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

void Keyboard::plugin() {
    Plugbox plugbox;
    PIC pic;

    plugbox.assign(1, this);
    pic.allow(1);
    
}
 
void Keyboard::trigger() {
    CGA_Stream cga_stream;
    Key key;
    key = key_hit();
    if (key.valid()) {
        cga_stream << (char)key;
    }
    cga_stream.flush();
}