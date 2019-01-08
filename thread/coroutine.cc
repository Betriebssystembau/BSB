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

#include "thread/coroutine.h"
#include "thread/kickoff.h"
#include "machine/toc.c"
#include "device/cgastr.h"

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
    cga_stream << "Coroutine constructor tos: " << (long) tos << endl;
    toc_settle(this->regs, tos, kickoff, (void *) this);
    cga_stream << "Coroutine reg sp: " << (long) regs->rsp << endl;
    tos = regs->rsp;
    cga_stream << "Stack content: kickoff, return, this" << endl;
    void **sp = (void **) regs->rsp;
    cga_stream << "sp[0]: kickoff " << (long) sp[0] << endl;
    cga_stream << "sp[1]: return " << (long) sp[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp[2] << endl;
}

void Coroutine::go() {
    cga_stream << "Coroutine go rsp kickoff" << endl;
    cga_stream << "Coroutine go rsp: " << (long) this->regs->rsp << endl;
    void **sp = (void **) regs->rsp;
    cga_stream << "sp[0]: kickoff " << (long) sp[0] << endl;
    cga_stream << "sp[1]: return " << (long) sp[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp[2] << endl;
    cga_stream << "Coroutine go kickoff: " << (long) kickoff << endl;
    toc_go(this->regs);

}

void *Coroutine::getTos() {
    return regs->rsp;
}

void Coroutine::resume(Coroutine &next) {
    cga_stream << "Resume called" << endl;
    void **sp = (void **) next.regs->rsp;
    cga_stream << "sp[0]: kickoff " << (long) sp[0] << endl;
    cga_stream << "sp[1]: return " << (long) sp[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp[2] << endl;
    void **sp1 = (void **) this->regs->rsp;
    cga_stream << "before switch:" << endl;
    cga_stream << "sp[0]: kickoff " << (long) sp1[0] << endl;
    cga_stream << "sp[1]: return " << (long) sp1[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp1[2] << endl;
    cga_stream << "Resume finished" << endl;
    toc_switch(this->regs, next.regs);
    void **sp2 = (void **) this->regs->rsp;
    cga_stream << "after switch:" << endl;
    cga_stream << "sp[0]: kickoff " << (long) sp2[0] << endl;
    cga_stream << "sp[1]: return " << (long) sp2[1] << endl;
    cga_stream << "sp[2]: this " << (long) sp2[2] << endl;
    cga_stream << "Resume finished" << endl;
}
