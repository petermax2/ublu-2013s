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

int labelnr = 1;

Tree astNew(short op, Tree left, Tree right, long number, char *id)
{
	Tree t = malloc(sizeof(struct tree));
	OP_LABEL(t) = op;
	LEFT_CHILD(t) = left;
	RIGHT_CHILD(t) = right;
	PARENT(t) = NULL; // default (only used in boolean expressions)
	t->number = number;  
	t->id = id;
	t->memt = NULL;
	t->type = -1;
	t->ifnr = -1;
	t->labelnr = -1;
	t->belseav = AST_FALSE;
	return t;
}

Tree astFuncdef(char *name, MemTab memt)
{
	Tree t = astNew(FUNC, NULL, NULL, 0, name);
	t->memt = memt;
	return t;
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

Tree astVar(char *name, long type, MemTab memt)
{
	Tree t = astNew(VARI, NULL, NULL, 0, name);
	t->type = type;
	t->memt = memt;
	return t;
}

Tree astArrayDeref(Tree left, Tree right)
{
	return astNew(ARR_DEREF, left, right, 0, NULL); 
}

Tree astVardef(Tree expr, MemTab memt) {
	Tree t = astNew(VARDEF, expr, NULL, 0, NULL);
	passMemTabToChildren(expr, memt);
	return t;
}

Tree astAssign(Tree lexpr, Tree expr) {
	return astNew(VASSIGN, lexpr, expr, 0, NULL);
}

Tree astBoolOp(short op, Tree left, Tree right) {
	Tree t = astNew(op, left, right, 0, NULL);
	if(op == LOR) { t->labelnr = labelnr++; }
	return t;
}

Tree astBoolNot(Tree node) {
	Tree t;

	if(node->op != LNOT) {
		t = astBoolOp(LNOT, node, NULL);
		node->parent = t;
		return t;
	} else {
		/* skip double negation */
		PARENT(LEFT_CHILD(node)) = NULL;
		return LEFT_CHILD(node);
	}	
}

// set memt to all descendants of root
void passMemTabToChildren(Tree root, MemTab memt) {
	if(root == NULL) { return; }	
	root->memt = memt;
	passMemTabToChildren(LEFT_CHILD(root), memt);
	passMemTabToChildren(RIGHT_CHILD(root), memt); 
}

// pass stat-information of if statement to all descendants of root
void passIfNrToChildren(Tree root, int ifnr, int belseav) {
	if(root == NULL) { return; }
	root->ifnr = ifnr;
	root->belseav = belseav;
	passIfNrToChildren(LEFT_CHILD(root), ifnr, belseav);
	passIfNrToChildren(RIGHT_CHILD(root), ifnr, belseav); 
}

