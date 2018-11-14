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

CGA_Screen::CGA_Screen(){
    this->setpos(0,0);
}

/* Hier muesst ihr selbst Code vervollstaendigen */
void CGA_Screen::show(int x, int y, char c, int attrib) {
    char *CGA_START = (char *) 0xb8000;
    char *pos;
    pos = CGA_START + 2 * (x + y * 80);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(int x, int y) {
    char cursorHigh;
    char cursorLow;

    int cursorValue = y * 80 + x;

    cursorHigh = cursorValue / 256;
    cursorLow = cursorValue % 256;

    IO_Port ioIndex(0x3d4);
    IO_Port ioData(0x3d5);
    ioIndex.outb(14);
    ioData.outb(cursorHigh);
    ioIndex.outb(15);
    ioData.outb(cursorLow);
}

void CGA_Screen::getpos(int &x, int &y) {
    IO_Port ioIndex(0x3d4);
    IO_Port ioData(0x3d5);
    ioIndex.outb(14);
    char cursorHigh = ioData.inb();
    ioIndex.outb(15);
    char cursorLow = ioData.inb();

    int cursorValue = cursorHigh * 256 + cursorLow;
    x = cursorValue % 80;
    y = (cursorValue - x) / 80;
}

void CGA_Screen::print(char *text, int length, unsigned char attrib) {
    int x = 0;
    int y = 0;
    this->getpos(x, y);
    for (int i = 0; i < length; i++) {
        if (text[i] == '\n') {
            y++;
            x = 0;
        }
        show(x, y, text[i], attrib);
        x++;
        if(x == 80){
            y++;
            x = 0;
        }
        this->setpos(x,y);
    }
}