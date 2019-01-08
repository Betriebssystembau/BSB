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

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;

int main() {
    cga_stream << "Main started" << endl;
    void* app_stack[4096];
    void* app_tos = &app_stack[4095];

    void* loop_stack[64];
    void* loop_tos = &loop_stack[63];
    cga_stream << "Creating Loop app" << endl;
    Loop loop_app(loop_tos, 0, 9);
    cga_stream << "Created" << endl;
    cga_stream << "Creating main app" << endl;
    Application app(app_tos, &loop_app);
    app.go();
    cga_stream << "End of main reached!" << endl;
    return 0;
}
