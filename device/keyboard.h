/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
 
class Keyboard : public Gate, Keyboard_Controller
{        
private:
      Keyboard (const Keyboard &copy); // Verhindere Kopieren
      Key currentKey;
public:
      Keyboard () {};

    /**
     * Mit dieser Methode wird die Tastatur initialisiert und "angestöpselt". Dazu muss sich das Keyboard-Objekt bei
     * der Plugbox plugbox anmelden und dem PIC-Objekt pic mitteilen, dass Unterbrechungen der Tastatur fortan dem
     * Prozessor gemeldet werden sollen.
     */
    void plugin();

    /**
     * Mit dieser Methode wird auf die Unterbrechungen durch die Tastatur reagiert. Da bei jedem Tastendruck mehrere
     * Unterbrechungen ausgelöst werden, ist nicht in jedem Fall mit einem verwertbaren ASCII-Code zu rechnen.
     * Nur wenn die Methode key_hit der Basisklasse Keyboard_Controller einen gültigen Key liefert,
     * konnte ein vollständiger Scancode ermittelt werden. Für "normale" Tasten existiert dann auch ein ASCII-Code
     * ungleich Null. Falls Ctrl-Alt-Delete gedrückt wurde, soll ein Reboot ausgelöst werden. Außerdem soll die
     * Ausführung eines Epilogs angefordert werden.
     * @return
     */
    bool prologue();

    /**
     * Hier wird das im Rahmen der Prolog- Behandlung ausgelesene Zeichen auf dem Bildschirm mit Hilfe des globalen
     * CGA_Stream Objekts kout ausgegeben.
     */
    void epilogue();
 };

#endif
