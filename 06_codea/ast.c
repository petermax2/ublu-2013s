/* 
 * Code-Erzegung A
 * -- Beispiel aus 185.A48 Uebersetzerbau
 * -- Author: Peter Nirschl (#1025647) 
 * -- E-Mail: e1025647@student.tuwien.ac.at
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "ast.h"

Tree astNew(short op, Tree left, Tree right, long number, char *id)
{
	Tree t = malloc(sizeof(struct tree));
	OP_LABEL(t) = op;
	LEFT_CHILD(t) = left;
	RIGHT_CHILD(t) = right;
	t->number = number;  
	t->id = id;
	t->sym = NULL;
	t->type = -1;
	return t;
}

Tree astFuncdef(char *name)
{
	return astNew(FUNC, NULL, NULL, 0, name);
}

Tree astLiteral(long value)
{
	return astNew(CONST, NULL, NULL, value, NULL);
}

Tree astArithmetic(short op, Tree left, Tree right)
{
	return astNew(op, left, right, 0, NULL);
}

Tree astReturn(Tree expr)
{
	return astNew(RET, expr, NULL, 0, NULL); 
}

Tree astVar(char *name, long type, struct symT *sym)
{
	Tree t = astNew(VARI, NULL, NULL, 0, name);
	t->type = type;
	t->sym = sym;
	return t;
}

Tree astArrayDeref(Tree left, Tree right)
{
	return astNew(ARR_DEREF, left, right, 0, NULL); 
}
