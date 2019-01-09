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
#include "thread/scheduler.h"
#include "user/entrantloop.h"
#include "device/watch.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;
Scheduler scheduler;

int main() {
    const int stack_size = 2048;
    cga_stream << "Main started" << endl;

    Watch watch(1000);
    watch.plugin();
    cga_stream << "Main: End of main reached!" << endl;
    while (true);

    return 0;
}
