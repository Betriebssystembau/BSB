/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "bellringer.h"

void Bellringer::check() {
    Bell *currentBell = (Bell *) this->bells.dequeue();
    bool finished = false;
    while (currentBell != 0 && !finished) {
        currentBell->tick();

        if (currentBell->run_down()) {
            currentBell->ring();
        } else {
            finished = true;
            this->bells.insert_first(currentBell);
        }
    }

    Bell *next = (Bell *) currentBell->next;
    while (next != 0) {
        next->tick();
        next = (Bell *) next->next;
    }
}

void Bellringer::job(Bell *bell, int ticks) {
    bell->wait(ticks);

    Bell *currentBell = (Bell *) this->bells.first();
    Bell *lastBell = 0;
    bool finished = false;

    if (currentBell == 0) {
        this->bells.insert_first(bell);
    } else {
        while (currentBell != 0 && !finished) {
            if (currentBell->wait() > ticks) {
                if (lastBell == 0) {
                    this->bells.insert_first(bell);
                } else {
                    this->bells.insert_after(lastBell, bell);
                }
                finished = true;
            } else {
                lastBell = currentBell;
                currentBell = (Bell *) currentBell->next;
            }
        }
    }
}

void Bellringer::cancel(Bell *bell) {
    this->bells.remove(bell);
}