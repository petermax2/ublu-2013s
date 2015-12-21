/*
 * codeb
 * -- Beispiel aus 185.A48 Uebersetzerbau 
 * -- Author: Peter Nirschl (#1025647) 
 * -- E-Mail: e1025647@student.tuwien.ac.at  
 */

#include <stdio.h>
#include <stdlib.h>
#include "memtab.h"

MemTab allocMem(char *id, enum memtype type, long semtype) {
	MemTab p = malloc(sizeof(struct memT));
	if(p) {
		p->id = id;
		p->type = type;
		p->semtype = semtype;
		p->next = NULL;
	}
	return p;
}

MemTab appendMemParam(MemTab first, char *id, long semtype) {
	MemTab p = first;
	if(p) {
		while(p->next != NULL) { p = p->next; }
		p->next = allocMem(id, MEM_PARAM, semtype);
		return first;
	} else {
		return allocMem(id, MEM_PARAM, semtype);
	}
}

MemTab memDeepCopy(MemTab src) {
	MemTab p = src;
	MemTab q; 
	MemTab nList = NULL;

	while(p != NULL) {
		if(nList) {
			q->next = allocMem(p->id, p->type, p->semtype); 
			q = q->next;
		} else {
			nList = allocMem(p->id, p->type, p->semtype);
			q = nList;
		}
		p = p->next;
	}
	return nList; 
}

/*
 * if add != NULL return deep copy of src and add 'add' to the end of the list
 * otherwise return src
*/
MemTab memTransferStats(MemTab src, MemTab add) {
	MemTab p = src;
	MemTab q; 
	MemTab nList = NULL;

	if(add) {
		// deep copy of src
		nList = memDeepCopy(src);
		// append add to end of list
		if(nList) {
			q = nList;
			while(q->next != NULL) { q = q->next; }
			q->next = add;
			q->next->next = NULL;
		} else {
			nList = add;
		}
		// return list copy with 'add' at its end
		return nList;
	} else {
		return src;
	}
}

void printMemTab(MemTab first) {
	MemTab p = first;
	printf("----- Output of Memory table -----\n");
	while(p != NULL) {
		printf("Memory symbol %s (%d)\n", p->id, p->type);
		p = p->next;
	}
	printf("----- End of Memory table -----\n");
}
