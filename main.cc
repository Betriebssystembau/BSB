/* $Id: main.cc 8485 2017-03-27 11:50:06Z friesel $ */

/* Hier muesst ihr selbst Code vervollstaendigen */

#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"

int main() {
    CGA_Stream cga_stream;
    unsigned short i = 5234;
    long l = -54324532356;
    cga_stream << 'h' << 'a' << 'l' << 'l' << 'o' << "test" << i << 'a' << endl << l << " test2";

    Keyboard_Controller keyboard;
    Key key;
    for(int i = 0; i < 4; i++) {
        key = keyboard.key_hit();
        if (key.valid()) {
            cga_stream << key.ascii();
        } else {
            cga_stream << "error";
        }
    }
    cga_stream.flush();
    /*CGA_Screen cga_screen;
    cga_screen.setpos(10, 10);*/

/* Hier muesst ihr selbst Code vervollstaendigen */

/* Hier muesst ihr selbst Code vervollstaendigen */

/* Hier muesst ihr selbst Code vervollstaendigen */

    return 0;
}
