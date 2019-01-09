/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Koroutinenkonzepts.                                   */
/* Im Konstruktor wird der initiale Kontext der Koroutine eingerichtet.      */
/* Mit go() wird die erste Koroutine aktiviert. Alle weiteren Koroutinen-    */
/* wechsel sollten mit resume() erfolgen.                                    */
/* Um bei einem Koroutinenwechsel den Kontext sichern zu koennen, enthaelt   */
/* jedes Koroutinenobjekt eine Struktur toc, in dem die Werte der nicht-     */
/* fluechtigen Register gesichert werden koennen.                            */
/*****************************************************************************/
#include "device/cgastr.h"

#include "machine/toc.c"

#include "thread/coroutine.h"
#include "thread/kickoff.h"

// Funktionen, die auf der C- oder Assembler-Ebene implementiert werden,
// muessen als extern "C" deklariert werden, da sie nicht dem Name-Mangeling
// von C++ entsprechen.
extern CGA_Stream cga_stream;
extern "C"
{
void toc_go(struct toc *regs);
void toc_switch(struct toc *regs_now, struct toc *reg_then);
};

Coroutine::Coroutine(void *tos) {
    toc_settle(&regs, tos, kickoff, this);
}

void Coroutine::go() {
    toc_go(&regs);
}

void Coroutine::resume(Coroutine &next) {
    cga_stream << "Coroutine: Switching stack from - to: " << (long) regs.rsp;
    cga_stream << " - " << (long) next.regs.rsp << endl;
    toc_switch(&regs, &(next.regs));
}
