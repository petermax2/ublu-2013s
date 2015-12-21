#ifndef __TREE_H
#define __TREE_H

#include "semantic.h"
#include "memtab.h"

typedef struct tree {
	short op;		/* node type */
	struct tree *kids[2];	/* successor nodes */
	struct tree *parent; 	/* ancestor node (only available in boolean expressions) */
	char *reg;		/* register name */
	long number;		/* value of numeric literal */
	long type; 		/* variable type (array depth) */
	char *id;		/* variable/array/function name */
	MemTab memt;		/* memory table */
	int ifnr;		/* label number for cond. jumps */
	int belseav;		/* else-stats available (if-stats only) */ 
	int labelnr;		/* label number for cond. jumps (interal) */
	struct burm_state *state;	/* BURG state variable */
} *NODEPTR_TYPE, *Tree;

#define LEFT_CHILD(p)		((p)->kids[0])
#define RIGHT_CHILD(p)		((p)->kids[1])
#define PARENT(p)		((p)->parent)
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
	ARR_DEREF=8,
	VARDEF=9,
	VASSIGN=10,
	LOR=12,
	LNEQ=13,
	LLESS=14,
	LNOT=15
};

#endif
