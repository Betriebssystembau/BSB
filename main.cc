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

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;
Scheduler scheduler;

int main() {
    int stack_size = 2048;
    cga_stream << "Main started" << endl;

    //toc switch test
    /*
    void* app_stack[stack_size];
    void* app_tos = &app_stack[stack_size - 1];
    cga_stream << "toc switch/dispatcher test" << endl;
    Application app(app_tos);
    dispatcher.go(app);
    */

    //Scheduler test

    void* c1_stack[stack_size];
    void* c1_tos = &c1_stack[stack_size - 1];
    EntrantLoop counter1(c1_tos, 0, 50, 25, "C1: 0-25-50");
    scheduler.ready(counter1);
    cga_stream << "C1scheduled. SP: "<< (long) counter1.regs.rsp << endl;

    void* c2_stack[stack_size];
    void* c2_tos = &c2_stack[stack_size - 1];
    EntrantLoop counter2(c2_tos, 51, 100, 75, "C2: 51-75-100");
    scheduler.ready(counter2);
    cga_stream << "C2 scheduled. SP: "<< (long) counter2.regs.rsp << endl;

    void* c3_stack[stack_size];
    void* c3_tos = &c3_stack[stack_size - 1];
    EntrantLoop counter3(c3_tos, 101, 150, 0, "C3: 101-0-150");
    scheduler.ready(counter3);
    cga_stream << "C3 scheduled. SP: "<< (long) counter3.regs.rsp << endl;

    scheduler.schedule();

    cga_stream << "End of main reached!" << endl;
    return 0;
}
