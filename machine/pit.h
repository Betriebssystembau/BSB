/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

class PIT {
private:
    PIT(const PIT &copy); // Verhindere Kopieren

    int us;

public:
    PIT(int us) {
        interval(us);
    }

    int interval() {
        return this->us;
    }

    void interval(int us);
};

#endif
