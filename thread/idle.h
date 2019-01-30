#ifndef __idle_include__
#define __idle_include__

#include "thread/coroutine.h"
#include "object/chain.h"
#include "machine/cpu.h"
#include "syscall/guarded_organizer.h"
#include "device/cgastr.h"

extern CPU cpu;
extern Guarded_Organizer scheduler;
extern CGA_Stream cga_stream;

class Idle: public Customer {
private:
    Idle(const Idle &copy); // Verhindere Kopieren

public:
    /**
     * Der Entrant Konstruktor gibt nur den Parameter tos an den Coroutinen Konstruktor weiter.
     * @param tos
     */
    Idle(void *tos) : Customer(tos){
        this->name = "Idle";
    };


    char *name = "";

    void action() {
        while(true) {
            cpu.idle();
        }
    }
};

#endif
