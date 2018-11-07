/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"

/* Hier muesst ihr selbst Code vervollstaendigen */
O_Stream &O_Stream::operator<<(unsigned char c) {
    this->put(c);
    return *this;
}

O_Stream &O_Stream::operator<<(char c) {
    this->put(c);
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned short number) {
    short ascii_start = 48;
    short div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(short number) {
    if (number < 0) {
        this->put('-');
        number *= -1;
    }
    short ascii_start = 48;
    short div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned int number) {
    short ascii_start = 48;
    unsigned int div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(int number) {
    if (number < 0) {
        this->put('-');
        number *= -1;
    }
    short ascii_start = 48;
    int div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned long number) {
    short ascii_start = 48;
    unsigned long div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(long number) {
    if (number < 0) {
        this->put('-');
        number *= -1;
    }
    short ascii_start = 48;
    long div = 1;
    while (div <= number / 10) {
        div *= 10;
    }

    while (number > 0) {
        this->put((number / div) + ascii_start);
        number %= div;
        div /= 10;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(void *pointer) {

    return *this;
}

O_Stream &O_Stream::operator<<(char *text) {
    int index = 0;
    while (text[index] != '\0') {
        this->put(text[index++]);
    }
    return *this;
}

O_Stream &O_Stream::operator<<(O_Stream &(*fkt)(O_Stream &)) {

    return *this;
}


O_Stream &endl(O_Stream &os) {

    return os;
}

O_Stream &bin(O_Stream &os) {

    return os;
}

O_Stream &oct(O_Stream &os) {

    return os;
}

O_Stream &dec(O_Stream &os) {

    return os;
}

O_Stream &hex(O_Stream &os) {

    return os;
}