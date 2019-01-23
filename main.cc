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
#include "meeting/bellringer.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;
Guarded_Organizer scheduler;
Bellringer bellringer;

int main() {
    {
        Secure secure;
        cga_stream << "Main: Starting" << endl;
        cga_stream << "Dummy" << endl;
        cga_stream << "Dummy" << endl;
        const int stack_size = 2048;

        Guarded_Semaphore waitingroom(1);
        static void *stack1[stack_size];
        void *tos1 = &stack1[stack_size - 1];
        EntrantLoop entrantLoop1(tos1, 0, 55000, -1, "C1", 1);
        scheduler.Scheduler::ready(entrantLoop1);
        entrantLoop1.setWaitingRoom(&waitingroom);

        static void *stack2[stack_size];
        void *tos2 = &stack2[stack_size - 1];
        EntrantLoop entrantLoop2(tos2, 2, 55000, -1, "C2", 2);
        scheduler.Scheduler::ready(entrantLoop2);
        entrantLoop2.setWaitingRoom(&waitingroom);

        Watch watch(5000000);
        watch.plugin();
        watch.windup();

        cpu.enable_int();
        scheduler.schedule();
        while (true);
    }


    return 0;
}
