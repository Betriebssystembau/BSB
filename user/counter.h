#include "thread/coroutine.h"
#include "device/cgastr.h"

extern CGA_Stream cga_stream;
class Counter : public Coroutine{
    public:
        Counter (void* tos, char start) :Coroutine(tos){
            this->start = start;
            cga_stream << "Counter constructor, start: " << start;
            cga_stream.flush();
        }

        void action(){
            cga_stream << "Counter action";
            cga_stream.flush();
            for (int i = 0; i < this->count; i++) {
                cga_stream << (this->start + i);
                cga_stream.flush();
            }
        }
    private:
        char start;
        int count = 9;
};