/* $Id: main.cc 8485 2017-03-27 11:50:06Z friesel $ */

/* Hier muesst ihr selbst Code vervollstaendigen */

#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "user/appl.h"
#include "guard/guard.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;

static void * stack_end [256];
static void * stack_start = stack_end + 255;

int main() {
    /*Application app;
    app.action();*/

    /*CGA_Stream cga_stream;
    unsigned short i = 5234;
    int speed = 31;
     int delay = 1;
     int test = speed | (delay << 5);
    long l = -54356;
    cga_stream << 'h' << 'a' << "test" << hex << i << 'a' << endl << oct << l << " test2";
    cga_stream << "Repeat test: " << dec << test;
    cga_stream.flush();
    Keyboard_Controller keyboard;
    Key key;
    while(true) {
        key = keyboard.key_hit();
        if (key.valid()) {
            cga_stream << (char)key;
        }
        cga_stream.flush();
    }*/
    /*CGA_Screen cga_screen;
    cga_screen.setpos(10, 10);*/
    cga_stream << "Main Start " << (long) stack_end << endl;
    cga_stream.flush();
    Application app(stack_start);
    cga_stream << "App create" << endl;
    cga_stream.flush();    
    app.go();
    cga_stream << "App go";
    cga_stream.flush();

    return 0;
}
