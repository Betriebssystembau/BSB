/* $Id: main.cc 8485 2017-03-27 11:50:06Z friesel $ */

/* Hier muesst ihr selbst Code vervollstaendigen */
#include "user/loop.h"
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "thread/dispatch.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;

int main() {
    cga_stream << "Main started" << endl;
    void* app_stack[4096];
    void* app_tos = &app_stack[4095];

    //toc switch test
    
    cga_stream << "toc switch/dispatcher test" << endl;
    Application app(app_tos);
    dispatcher.go(app);

    cga_stream << "End of main reached!" << endl;
    return 0;
}
