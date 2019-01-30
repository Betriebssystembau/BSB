/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#include "buzzer.h"
#include "device/cgastr.h"

extern CGA_Stream cga_stream;

Buzzer::Buzzer() {

}

Buzzer::~Buzzer() {
    bellringer.cancel(this);
    this->ring();
}

void Buzzer::ring() {
    Thread * thread = (Thread * )
    this->dequeue();
    while (thread != 0) {
        scheduler.wakeup(*((Customer *) thread));
        thread = (Thread * )
        this->dequeue();
    }
}

void Buzzer::set(int ms) {
    this->ticks = ((ms * 1000 + 500) / 838);
    bellringer.job(this, this->ticks);
}

void Buzzer::sleep() {
    scheduler.block(*((Customer *) scheduler.active()), *this);
}
