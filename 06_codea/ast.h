/*
 * Code-Erzeugung A
 * -- Beispiel aus 185.A48 Uebersetzerbau
 * -- Author: Peter Nirschl
 * -- E-Mail: e1025647@student.tuwien.ac.at
 */

#ifndef __AST_H
#define __AST_H

#include "tree.h"

Tree astNew(short op, Tree left, Tree right, long number, char *id);
Tree astFuncdef(char *name);
Tree astLiteral(long value);
Tree astArithmetic(short op, Tree left, Tree right); 
Tree astReturn(Tree expr); 
Tree astVar(char *name, long type, struct symT *sym);
Tree astArrayDeref(Tree left, Tree right);

#endif
