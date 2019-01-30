#ifndef __waiting_key_output_include__
#define __waiting_key_output_include__

#include "thread/customer.h"
#include "syscall/guarded_keyboard.h"
#include "device/cgastr.h"

extern Guarded_Keyboard keyboard;
extern CGA_Stream cga_stream;

class WaitingKeyOutput: public Customer {
    private:
        WaitingKeyOutput (const WaitingKeyOutput& ref);
        Key lastKey;

    public:
        WaitingKeyOutput (void* tos) : Customer(tos) {};

        void action() {
            while (true) {
                int x = 0;
                int y = 0;
                {
                    Secure secure;
                    cga_stream.getpos(x, y);
                    cga_stream.setpos(0,3);
                    cga_stream << "Waiting.............. " << endl;
                }

                cga_stream.setpos(0,4);

                cga_stream << "Pressed: " << (unsigned char) keyboard.getKey() << endl;
                cga_stream.setpos(x,y);

            }
        }
};

#endif