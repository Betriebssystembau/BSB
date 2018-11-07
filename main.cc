/* $Id: main.cc 8485 2017-03-27 11:50:06Z friesel $ */

/* Hier muesst ihr selbst Code vervollstaendigen */

#include "machine/cgascr.h"
#include "device/cgastr.h"

int main() {
    CGA_Stream cga_stream;
    unsigned short i = 5234;
    long l = -54324532356;
    cga_stream << 'h' << 'a' << 'l' << 'l' << 'o' << "test" << i << 'a' << endl << l << " test2";
    cga_stream.flush();

/* Hier muesst ihr selbst Code vervollstaendigen */

/* Hier muesst ihr selbst Code vervollstaendigen */

/* Hier muesst ihr selbst Code vervollstaendigen */

    return 0;
}
