#include "thread/coroutine.h"
#include "device/cgastr.h"

extern CGA_Stream cga_stream;
class Counter : public Coroutine{
    public:
        Counter (void* tos, char start) :Coroutine(tos){
            this->start = start;
            cga_stream << "Counter constructor, start: " << start << endl;
        }

        void action(){
            cga_stream << "Counter action, would be counting now" << endl;
        }
    private:
        char start;
        int count = 9;
};