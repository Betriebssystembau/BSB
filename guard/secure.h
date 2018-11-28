/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               S E C U R E                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Secure dient dem Setzen und Freigeben der Sperrvariablen, mit  */
/* der die kritischen Abschnitte des Betriebssystemkerns geschuetzt werden.  */
/* Im Konstruktor der Klasse wird die Sperre gesetzt, im Destruktor wieder   */
/* freigegeben. Dadurch genuegt schon die Deklaration eines Secure Objekts,  */
/* um den gesamten Geltungsbereich als kritischen Abschnitt zu schuetzen.    */
/*****************************************************************************/

#ifndef __Secure_include__
#define __Secure_include__

/* Die Methoden der Klasse sind so kurz, dass sie am besten inline definiert werden sollten.*/
class Secure {
    /**
     * Im Konstruktor wird der durch das Guard Objekt guard geschützte kritische Abschnitt betreten.
     */
    Secure() {}

    /**
     * Im Destruktor wird der kritische Abschnitt wieder verlassen.
     */
    ~Secure() {}
};

#endif
