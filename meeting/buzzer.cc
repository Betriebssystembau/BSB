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
    //TODO zu ms umrechnen:
    this->ticks = ms;
}

void Buzzer::sleep() {
    bellringer.job(this, this->ticks);
}
