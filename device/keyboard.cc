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
#include "device/panic.h"

extern CGA_Stream cga_stream;
extern Plugbox plugbox;
extern PIC pic;

void Keyboard::plugin() {
    plugbox.assign(33, *this);
    pic.allow(PIC::keyboard);
}

bool Keyboard::prologue() {
    this->currentKey = key_hit();
    return true;
}

void Keyboard::epilogue() {
    if (this->currentKey.valid()) {
        //cga_stream << (unsigned char) this->currentKey;
        if (this->waiting) {
            this->waiting = false;
            this->waitingroom->signal();
        }
    }
}

Key Keyboard::getKey() {
    if (this->currentKey && this->currentKey.valid()) {
        return this->currentKey;
    } else {
        if (!this->waitingroom) {
            Panic().prologue();
        } else {
            this->waiting = true;
            this->waitingroom->wait();
        }
    }
    return this->currentKey;
}