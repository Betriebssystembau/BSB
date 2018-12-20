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
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    unsigned short div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }


    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(short number) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    if (number < 0 && base == 10) {
        this->put('-');
        number *= -1;
    }
    short div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned int number) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    unsigned int div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(int number) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    if (number < 0 && base == 10) {
        this->put('-');
        number *= -1;
    }
    int div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned long number) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    unsigned long div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(long number) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    if (base == 2) {
        *this << "0b";
    } else if (base == 8) {
        *this << "0o";
    } else if (base == 16) {
        *this << "0x";
    }
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    if (number < 0 && base == 10) {
        this->put('-');
        number *= -1;
    }
    long div = 1;
    while (div <= number / this->base) {
        div *= this->base;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= this->base;
    }
    return *this;
}

O_Stream &O_Stream::operator<<(void *pointer) {
    char ascii_start = '0';
    char ascii_alpha_start = 'a';
    *this << "0x";
    int number = *(int *) pointer;
    if (number == 0) {
        this->put(ascii_start);
        return *this;
    }
    long long div = 1;
    while (div <= number / this->base) {
        div *= 16;
    }

    while (number > 0) {
        if (number / div > 10) {
            this->put((number / div) + ascii_alpha_start);
        } else {
            this->put((number / div) + ascii_start);
        }
        number %= div;
        div /= 16;
    }
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
    return fkt(*this);
}


O_Stream &endl(O_Stream &os) {
    os << '\n';
    os.flush();
    return os;
}

O_Stream &bin(O_Stream &os) {
    os.base = 2;
    return os;
}

O_Stream &oct(O_Stream &os) {
    os.base = 8;
    return os;
}

O_Stream &dec(O_Stream &os) {
    os.base = 10;
    return os;
}

O_Stream &hex(O_Stream &os) {
    os.base = 16;
    return os;
}