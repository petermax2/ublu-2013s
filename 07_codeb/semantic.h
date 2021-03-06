/*
* Attribuierte Grammatik
* -- Beispiel aus 185.A48 Uebersetzerbau
* -- Author: Peter Nirschl (#1025647)
* -- E-Mail: e1025647@student.tuwien.ac.at
*/

#ifndef _SEMANTIC_H
#define _SEMANTIC_H

#include "memtab.h"

/* SEM_DEBUG - if this symbol is defined, debug output to stdout is being enabled */
/* #define SEM_DEBUG */

enum termType {
	SEM_INT = 0,
	SEM_UNDEFINED = -1
};

enum boolVal {
	SEM_TRUE = 1,
	SEM_FALSE = 0
};

void checkDuplicates(MemTab first);
long getType(MemTab first, char *name);

/* functions for type checking */
void assertInt(long type);
void assertArray(long type);
void assertEqual(long type1, long type2);

#endif
