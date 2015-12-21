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
#include "memtab.h"

/* 
 * check symbol table for duplicates
 * bail out if dupliate parameters found
 */
void checkDuplicates(MemTab first) 
{
	MemTab p = first;
	MemTab q;
	while(p != NULL)
	{
		if(p->type == MEM_VAR) { return; }
		q = p->next;
		while(q != NULL ) {
			if(q->type == MEM_VAR) { break; }
			if(strcmp(p->id, q->id) == 0) {
				fprintf(stderr, "ERROR parameter %s has already been defined\n", p->id);
				exit(3);
			}
			q = q->next;
		}
		p = p->next;
	}
}

/*
 * return type of symbol "name".
 * bail out if the symbol is not contained in the table.
 */
long getType(MemTab first, char *name)
{
	MemTab p = first;
	int hit = SEM_FALSE;
	long type = -1L;
	while(p != NULL)
	{
		if(strcmp(p->id, name) == 0)
		{
			type = p->semtype;
			hit = SEM_TRUE;
		}
		p = p->next;
	}
	if(hit == SEM_FALSE) {
		fprintf(stderr, "ERROR use of undefined variable %s\n", name);
		exit(3); 
	}
	return type;
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

