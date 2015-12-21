/*
 * Code-Erzeugung A
 * -- Beispiel aus 185.A48 Uebersetzerbau
 * -- Author: Peter Nirschl
 * -- E-Mail: e1025647@student.tuwien.ac.at
 */

#ifndef __AST_H
#define __AST_H

#include "tree.h"
#include "memtab.h"

enum ast_bool {
	AST_FALSE = 0,
	AST_TRUE = 1
};

Tree astNew(short op, Tree left, Tree right, long number, char *id);
Tree astFuncdef(char *name, MemTab memt);
Tree astLiteral(long value);
Tree astArithmetic(short op, Tree left, Tree right); 
Tree astReturn(Tree expr); 
Tree astVar(char *name, long type, MemTab memt);
Tree astArrayDeref(Tree left, Tree right);
Tree astVardef(Tree expr, MemTab memt);
Tree astAssign(Tree lexpr, Tree expr);
Tree astBoolOp(short op, Tree left, Tree right);
Tree astBoolNot(Tree child);

void passMemTabToChildren(Tree root, MemTab memt);
void passIfNrToChildren(Tree root, int ifnr, int belseav); 
void invertBooleanOps(Tree root);

#endif
