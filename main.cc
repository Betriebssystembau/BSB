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
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "user/waiting_key_output.h"
#include "user/buzzerTester.h"
#include "object/list.h"
#include "thread/idle.h"

Plugbox plugbox;
CGA_Stream cga_stream;
Guard guard;
PIC pic;
CPU cpu;
Dispatcher dispatcher;
Guarded_Organizer scheduler;
Bellringer bellringer;
Guarded_Keyboard keyboard;

const int stack_size = 2048;
const int KEYBOARD_BUFFER_SIZE = 1;

static void *idleStack[stack_size];
void *idleTos = &idleStack[stack_size - 1];
const void * initIdleTos = idleTos;

int main() {
    {
        Semaphore keyboardSemaphore(KEYBOARD_BUFFER_SIZE);
        Guarded_Semaphore waitingroom(1);

        List waitingrooms;
        waitingrooms.enqueue(&keyboardSemaphore);
        waitingrooms.enqueue(&waitingroom);
        scheduler.setWaitingRooms(&waitingrooms);

        keyboard.plugin();
        keyboard.setSemaphore(&keyboardSemaphore);
        Secure secure;

        cga_stream << "Main: Starting" << endl;
        cga_stream << "Dummy" << endl;
        cga_stream << "Dummy" << endl;
        cga_stream << "Keylogger:" << endl;
        cga_stream << "Waiting for Key..." << endl;

        static void *stack1[stack_size];
        void *tos1 = &stack1[stack_size - 1];
        EntrantLoop entrantLoop1(tos1, 0, 15000, -1, "C1", 1);
        scheduler.Scheduler::ready(entrantLoop1);
        entrantLoop1.setWaitingRoom(&waitingroom);

        static void *stack2[stack_size];
        void *tos2 = &stack2[stack_size - 1];
        EntrantLoop entrantLoop2(tos2, 2, 5000, -1, "C2", 2);
        scheduler.Scheduler::ready(entrantLoop2);
        entrantLoop2.setWaitingRoom(&waitingroom);

        static void *stack3[stack_size];
        void *tos3 = &stack3[stack_size - 1];
        WaitingKeyOutput outputApp(tos3);
        scheduler.Scheduler::ready(outputApp);

        static void *stack4[stack_size];
        void *tos4 = &stack4[stack_size - 1];
        BuzzerTester buzzerTester(tos4, 15, 1000, &waitingroom);
        //scheduler.Scheduler::ready(buzzerTester);

        static void *stack5[stack_size];
        void *tos5 = &stack5[stack_size - 1];
        BuzzerTester buzzerTester2(tos5, 18, 500, &waitingroom);
        //scheduler.Scheduler::ready(buzzerTester2);

        Idle idle(idleTos);
        scheduler.Scheduler::ready(idle);

        Watch watch(500);
        watch.plugin();
        watch.windup();

        cpu.enable_int();
        scheduler.schedule();
        while (true);
    }
    return 0;
}
