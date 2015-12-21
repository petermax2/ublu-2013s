/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "semantic.h"

/* initialize a new symbol table by setting the head to NULL */
void initSymTab(struct symT **first)
{
	*first = NULL;
#ifdef SEM_DEBUG
	fprintf(stdout, "INFO initialized symbol table\n");
#endif
}

/* add a new variable at the table's 1st position */
void addSym(struct symT **first, char *name, long type)
{
	struct symT *p = (struct symT*)malloc(sizeof(struct symT));
	p->name = name;
	p->type = type;
	p->next = *first;
	*first = p;

#ifdef SEM_DEBUG
	fprintf(stdout, "INFO added variable %s with type %d to symbol table\n", name, type);
#endif
}

/* 
 * check symbol table and count occurences of name.
 * bail out if occurences > 1
 */
void checkDuplicate(struct symT **first, char *name) 
{
	long occurences = 0;
	struct symT *p = *first;
	while(p != NULL)
	{
		if(strcmp(p->name, name) == 0)
		{
			occurences++;
		}
		p = p->next;
	}
	if(occurences > 1) 
	{
		fprintf(stderr, "ERROR parameter %s has already been defined\n", name);
		/* TODO this is kind'a unsafe -> think of memory cleanup some time? */
		exit(3);
	}
}

/*
 * return type of symbol "name".
 * bail out if the symbol is not contained in the table.
 */
long getType(struct symT **first, char *name)
{
	struct symT *p = *first;
	while(p != NULL)
	{
		if(strcmp(p->name, name) == 0)
		{
			return p->type;
		}
		p = p->next;
	}
	fprintf(stderr, "ERROR use of undefined variable %s\n", name);
	/* TODO clean-up dirty exit */
	exit(3);
	return SEM_UNDEFINED;
}

/* bail out if type <> 0 */
void assertInt(long type)
{
	if(type != 0) 
	{
		fprintf(stderr, "ERROR operand is not an integer\n");
		exit(3);
	}
}

/* bail out if type < 1 */
void assertArray(long type)
{
	if(type < 1)
	{
		fprintf(stderr, "ERROR array-like access to non-array symbol detected\n");
		exit(3);
	}
}

/* bail out if type1 != type2 */
void assertEqual(long type1, long type2)
{
	if(type1 != type2)
	{
		fprintf(stderr, "ERROR variable types in assignation do not match\n");
		exit(3);
	}
}
