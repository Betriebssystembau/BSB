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

bool Keyboard::prologue() {
    this->currentKey = key_hit();
    cga_stream << "keyboard prologue";
    cga_stream.flush();
    return true;
}

void Keyboard::epilogue() {
    cga_stream<<"keyboard epilogue";
    if (this->currentKey.valid()) {
        cga_stream << (unsigned char) this->currentKey;
    }
    cga_stream.flush();
}