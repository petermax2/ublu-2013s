/*
 * codeb
 * -- Beispiel aus 185.A48 Uebersetzerbau
 * -- Author: Peter Nirschl (#1025647)
 * -- E-Mail: e1025647@student.tuwien.ac.at
 */

#ifndef _MEMTAB__H
#define _MEMTAB__H

enum memtype {
	MEM_PARAM = 1,
	MEM_VAR = 2
};

typedef struct memT {
	char *id;
	enum memtype type;
	long semtype;
	struct memT *next;	
} *MemTab;

MemTab allocMem(char *id, enum memtype type, long semtype);
MemTab appendMemParam(MemTab first, char *id, long semtype);
MemTab memDeepCopy(MemTab src);
MemTab memTransferStats(MemTab src, MemTab add);
void printMemTab(MemTab first);

#endif
