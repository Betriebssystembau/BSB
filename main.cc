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
const int stack_size = 1024;

void* stack_end [stack_size];
void* tos = stack_end + stack_size - 1;


int main() {
    cga_stream << "Main Start tos " << (long) tos << endl;
    Application app(tos);
    cga_stream << "App created" << endl;
    cga_stream << "New tos" << (long) tos << endl;
    tos = app.getTos();
    app.go();
    cga_stream << "App go";


    return 0;
}
