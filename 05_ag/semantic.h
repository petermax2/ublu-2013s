/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

#ifndef _SEMANTIC_H
#define _SEMANTIC_H

/* SEM_DEBUG - if this symbol is defined, debug output to stdout is being enabled */
#define SEM_DEBUG

enum termType {
	SEM_INT = 0,
	SEM_UNDEFINED = -1
};

struct symT {
	char *name;
	long type; /* 0 = INT, 1 = array of, 2 = array of array of... */
	struct symT *next;
};

/* functions concering the symbol table */
void initSymTab(struct symT **first);
void addSym(struct symT **first, char *name, long type);
void checkDuplicate(struct symT **first, char *name);
long getType(struct symT **first, char *name);

/* functions for type checking */
void assertInt(long type);
void assertArray(long type);
void assertEqual(long type1, long type2);

#endif
