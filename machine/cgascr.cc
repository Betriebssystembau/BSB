/* $Id: cgascr.cc 5834 2013-10-08 17:04:08Z os $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

/* Hier muesst ihr selbst Code vervollstaendigen */
void CGA_Screen::show(int x, int y, char c, int attrib) {
    char *CGA_START = (char*) 0xb8000;
    char *pos;
    pos = CGA_START + 2 * (x + y * 80);
    *pos = c;
    *(pos + 1) = attrib;

    IO_Port io_port(*pos);
    io_port.outb(*pos);
}

void CGA_Screen::setpos (int x, int y){
    this->posX = x;
    this->posY = y;
}

void CGA_Screen::getpos (int &x, int &y){
    x = this->posX;
    y = this->posY;
}

void CGA_Screen::print (char* text, int length, unsigned char attrib){
    for(int i = 0; i < length; i++){
        if(text[i] == '\n'){
            this->posX = 0;
            this->posY++;
        }
        show(this->posX++, this->posY, text[i], attrib);
    }
}