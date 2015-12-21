#ifndef __TREE_H
#define __TREE_H

#include "semantic.h"

typedef struct tree {
	short op;		/* node type */
	struct tree *kids[2];	/* successor nodes */
	char *reg;		/* register name */
	long number;		/* value of numeric literal */
	long type; 		/* variable type (array depth) */
	char *id;		/* variable/array/function name */
	struct symT *sym;	/* symbol table */
	struct burm_state *state;	/* BURG state variable */
} *NODEPTR_TYPE, *Tree;

#define LEFT_CHILD(p)		((p)->kids[0])
#define RIGHT_CHILD(p)		((p)->kids[1])
#define PANIC			printf
#define STATE_LABEL(p)		((p)->state)
#define OP_LABEL(p)		((p)->op)
#define STATE_TYPE		long

enum
{
	FUNC=1,
	RET=2,
	CONST=3,
	ADD=4, 
	SUB=5, 
	MUL=6,
	VARI=7,
	ARR_DEREF=8
};

#endif
