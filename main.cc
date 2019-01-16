/* $Id: main.cc 8485 2017-03-27 11:50:06Z friesel $ */

/* Hier muesst ihr selbst Code vervollstaendigen */
#include "user/loop.h"
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "device/keyboard.h"
#include "machine/cpu.h"
#include "machine/pic.h"
#include "machine/plugbox.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "thread/dispatch.h"
#include "thread/scheduler.h"
#include "user/entrantloop.h"
#include "device/watch.h"
#include "syscall/guarded_scheduler.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;
Guarded_Scheduler scheduler;

int main() {
    {
        Secure secure;
        cga_stream << "Main: Starting" << endl;
        const int stack_size = 2048;

        static void *stack1[stack_size];
        void *tos1 = &stack1[stack_size - 1];
        EntrantLoop entrantLoop1(tos1, 0, 15000, -1, "C1:");
        scheduler.ready(entrantLoop1);

        static void *stack2[stack_size];
        void *tos2 = &stack2[stack_size - 1];
        EntrantLoop entrantLoop2(tos2, 25, 15000, -1, "C2:");
        scheduler.ready(entrantLoop2);

        Watch watch(500000);
        watch.plugin();
        watch.windup();
        cga_stream << "Main: End of main reached!" << endl;

        cpu.enable_int();
        scheduler.schedule();
        while (true);
    }


    return 0;
}
