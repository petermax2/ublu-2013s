typedef struct burm_state *STATEPTR_TYPE;

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "ast.h"
#include "memtab.h"

int bfe_nextReg = 0;
int bfe_labelNr = 1;

char *bfe_TmpReg[] = { "%rax","%rcx","%rdx","%rsi","%rdi","%r8","%r9","%r10", "%r11" };
char *bfe_ParamReg[] = { "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };

char *bfeGetVarReg(char *id, MemTab memt);
char *bfeGetNextVarReg(MemTab memt);
char *bfeSaveParamsToMem(MemTab memt);
void bfePrintStart(Tree,int,int,int);
void bfePrintEnd(Tree,int,int,int);

char *bfeGetVarReg(char *id, MemTab memt) {
        char *reg;
        short index = -1;
        short i = 0;
        MemTab p = memt;

        while(p != NULL) {
                if(strcmp(p->id, id) == 0) { index = i; }
                i++;
                p = p->next;
        }
        if(index >= 0) {
                reg = malloc(13);
                sprintf(reg, "%d(\%rbp)", ((-8)*(index + 1)));
                return reg;
        } else {
                fprintf(stderr, "FATAL ERROR in memory table: symbol not found %s\n", id);
                exit(3);
        }
        return "";
}

char *bfeGetNextVarReg(MemTab memt) {
        char *reg;
        short c = 0;
        MemTab p = memt;

        while(p != NULL) {
                c++;
                p = p->next;
        }
        reg = malloc(13);
        sprintf(reg, "%d(\%rbp)", ((-8)*(c + 1)));
        return reg;
}

char *bfeSaveParamsToMem(MemTab memt) {
        int i = 0;
        MemTab p = memt;
        while(p != NULL && i < 6) {
                printf("\tmovq %s,%d(%rbp)\n", bfe_ParamReg[i], ((-8)*(i+1)));
                i++;
                p = p->next;
        }
}

void bfePrintStart(Tree bnode, int labelnr, int ifnr, int elseav) {
        if(bnode == NULL) {
                printf(".L%dS", ifnr);
                return;
        }
        switch(OP_LABEL(bnode)) {
                case LOR:
                        bfePrintStart(PARENT(bnode), bnode->labelnr, ifnr, elseav);
                        break;

                case LNOT:
                        bfePrintEnd(PARENT(bnode), labelnr, ifnr, elseav);
                        break;

		default:
			bfePrintStart(PARENT(bnode), labelnr, ifnr, elseav);
			break;
        }
}

void bfePrintEnd(Tree bnode, int labelnr, int ifnr, int elseav) {
        if(bnode == NULL) {
                if(elseav == AST_TRUE) { printf(".L%dA", ifnr); }
                else { printf(".L%dE", ifnr);  }
                return;
        }
        switch(OP_LABEL(bnode)) {
                case LOR:
			if(PARENT(bnode) && bnode == RIGHT_CHILD(PARENT(bnode))) {
				printf("Z%d", labelnr);
				return;
			} else {
				bfePrintEnd(PARENT(bnode), bnode->labelnr, ifnr, elseav);
			}
                        break;
                case LNOT:
                        bfePrintStart(PARENT(bnode), labelnr, ifnr, elseav);
                        break;
		default:
			bfePrintEnd(PARENT(bnode), labelnr, ifnr, elseav);
			break;
        }
}

#define BFE_NEXT_REG char *r = bfe_TmpReg[bfe_nextReg++]; bnode->reg = r;
#define BFE_DEF_TMP  char *r = bfe_TmpReg[bfe_nextReg++];

#define REG_RET "%rax"

#define MULV(p,q) printf("\timul %s, %s\n", p, q);
#define MULC(p,q) printf("\timul $%d, %s\n", p, q); 
#define MULM(p,q) printf("\timul (%s), %s\n", p, q); 
#define ADDV(p,q) printf("\taddq %s, %s\n", p, q); 
#define ADDM(p,q) printf("\taddq (%s),%s\n", p, q); 
#define SUBV(p,q) printf("\tsubq %s, %s\n", p, q); 
#define SUBM(p,q) printf("\tsubq (%s), %s\n", p, q); 
#define SUBC(p,q) printf("\tsubq $%d, %s\n", p, q); 
#define MOVV(p,q) printf("\tmovq %s, %s\n", p, q); 
#define MOVAV(p,q) printf("\tmovq %s, (%s)\n", p, q); 
#define MOVC(p,q) printf("\tmovq $%d, %s\n", p, q);
#define MOVAC(p,q) printf("\tmovq $%d, (%s)\n", p, q);
#define MOVM(p,q) printf("\tmovq (%s), %s\n", p, q); 
#define MOVAM(p,q) printf("\tmovq %s, (%s)\n", p, q);
#define MOVAA(p,q) printf("\tmovq (%s), (%s)\n", p, q); 
#define PUSH(p) printf("\tpushq %s\n", p);
#define POP(p) printf("\tpopq %s\n", p); 
#define CMP(p,q) printf("\tcmpq %s, %s\n", p, q);
#define JOP(p,q) printf("\tj%s %s\n", p, q);
#define JMP(p) printf("\tjmp %s\n", p);

#define FUNC_PROLOG(f) { printf(".globl %s\n\t.type %s, @function\n%s:\n\t.cfi_startproc\n\tpushq %rbp\n\t.cfi_def_cfa_offset 16\n\tmovq %rsp, %rbp\n\t.cfi_offset 6, -16\n\t.cfi_def_cfa_register 6\n",f,f,f); }
#define FUNC_EPILOG { printf("\tleave\n\tret\n\n"); }
#define SAVE_TMP_REG { short bfe_tmp_i; for(bfe_tmp_i = 2; bfe_tmp_i <= 5; bfe_tmp_i++) { PUSH(bfe_TmpReg[bfe_tmp_i]) } }
#define RESC_TMP_REG { short bfe_tmp_i; for(bfe_tmp_i = 5; bfe_tmp_i >= 2; bfe_tmp_i--) { POP(bfe_TmpReg[bfe_tmp_i]) } }
#define NL printf("\n"); 

#ifndef ALLOC
#define ALLOC(n) malloc(n)
#endif

#ifndef burm_assert
#define burm_assert(x,y) if (!(x)) { extern void abort(void); y; abort(); }
#endif

#define burm_stat_NT 1
#define burm_retexpr_NT 2
#define burm_vdefexpr_NT 3
#define burm_retvar_NT 4
#define burm_retcon_NT 5
#define burm_retarr_NT 6
#define burm_bterm_NT 7
#define burm_bbasic_NT 8
#define burm_bexpr_NT 9
#define burm_arrv_NT 10
#define burm_arrd_NT 11
int burm_max_nt = 11;

struct burm_state {
	int op;
	STATEPTR_TYPE left, right;
	short cost[12];
	struct {
		unsigned burm_stat:4;
		unsigned burm_retexpr:2;
		unsigned burm_vdefexpr:2;
		unsigned burm_retvar:5;
		unsigned burm_retcon:3;
		unsigned burm_retarr:3;
		unsigned burm_bterm:2;
		unsigned burm_bbasic:2;
		unsigned burm_bexpr:2;
		unsigned burm_arrv:1;
		unsigned burm_arrd:3;
	} rule;
};

static short burm_nts_0[] = { 0 };
static short burm_nts_1[] = { burm_retexpr_NT, 0 };
static short burm_nts_2[] = { burm_vdefexpr_NT, 0 };
static short burm_nts_3[] = { burm_retvar_NT, burm_retcon_NT, 0 };
static short burm_nts_4[] = { burm_retvar_NT, burm_retvar_NT, 0 };
static short burm_nts_5[] = { burm_retvar_NT, burm_retarr_NT, 0 };
static short burm_nts_6[] = { burm_retarr_NT, burm_retcon_NT, 0 };
static short burm_nts_7[] = { burm_retarr_NT, burm_retvar_NT, 0 };
static short burm_nts_8[] = { burm_retarr_NT, burm_retarr_NT, 0 };
static short burm_nts_9[] = { burm_bterm_NT, 0 };
static short burm_nts_10[] = { burm_retcon_NT, 0 };
static short burm_nts_11[] = { burm_retvar_NT, 0 };
static short burm_nts_12[] = { burm_retarr_NT, 0 };
static short burm_nts_13[] = { burm_bbasic_NT, 0 };
static short burm_nts_14[] = { burm_bterm_NT, burm_bterm_NT, 0 };
static short burm_nts_15[] = { burm_bexpr_NT, burm_bexpr_NT, 0 };
static short burm_nts_16[] = { burm_arrv_NT, burm_retvar_NT, 0 };
static short burm_nts_17[] = { burm_arrv_NT, burm_retcon_NT, 0 };
static short burm_nts_18[] = { burm_arrd_NT, burm_retvar_NT, 0 };
static short burm_nts_19[] = { burm_arrd_NT, burm_retcon_NT, 0 };
static short burm_nts_20[] = { burm_retcon_NT, burm_retvar_NT, 0 };
static short burm_nts_21[] = { burm_retcon_NT, burm_retarr_NT, 0 };
static short burm_nts_22[] = { burm_retcon_NT, burm_retcon_NT, 0 };

short *burm_nts[] = {
	0,	/* 0 */
	burm_nts_0,	/* 1 */
	burm_nts_1,	/* 2 */
	burm_nts_2,	/* 3 */
	burm_nts_3,	/* 4 */
	burm_nts_4,	/* 5 */
	burm_nts_5,	/* 6 */
	burm_nts_6,	/* 7 */
	burm_nts_7,	/* 8 */
	burm_nts_8,	/* 9 */
	burm_nts_9,	/* 10 */
	burm_nts_10,	/* 11 */
	burm_nts_11,	/* 12 */
	burm_nts_12,	/* 13 */
	burm_nts_10,	/* 14 */
	burm_nts_11,	/* 15 */
	burm_nts_12,	/* 16 */
	burm_nts_13,	/* 17 */
	burm_nts_9,	/* 18 */
	burm_nts_14,	/* 19 */
	burm_nts_15,	/* 20 */
	burm_nts_15,	/* 21 */
	burm_nts_10,	/* 22 */
	burm_nts_11,	/* 23 */
	burm_nts_12,	/* 24 */
	burm_nts_16,	/* 25 */
	burm_nts_17,	/* 26 */
	burm_nts_18,	/* 27 */
	burm_nts_19,	/* 28 */
	burm_nts_18,	/* 29 */
	burm_nts_19,	/* 30 */
	burm_nts_16,	/* 31 */
	burm_nts_17,	/* 32 */
	burm_nts_0,	/* 33 */
	burm_nts_4,	/* 34 */
	burm_nts_3,	/* 35 */
	burm_nts_20,	/* 36 */
	burm_nts_7,	/* 37 */
	burm_nts_5,	/* 38 */
	burm_nts_6,	/* 39 */
	burm_nts_21,	/* 40 */
	burm_nts_8,	/* 41 */
	burm_nts_4,	/* 42 */
	burm_nts_3,	/* 43 */
	burm_nts_20,	/* 44 */
	burm_nts_7,	/* 45 */
	burm_nts_5,	/* 46 */
	burm_nts_6,	/* 47 */
	burm_nts_21,	/* 48 */
	burm_nts_8,	/* 49 */
	burm_nts_4,	/* 50 */
	burm_nts_3,	/* 51 */
	burm_nts_20,	/* 52 */
	burm_nts_7,	/* 53 */
	burm_nts_5,	/* 54 */
	burm_nts_6,	/* 55 */
	burm_nts_21,	/* 56 */
	burm_nts_8,	/* 57 */
	burm_nts_0,	/* 58 */
	burm_nts_22,	/* 59 */
	burm_nts_22,	/* 60 */
	burm_nts_22,	/* 61 */
	burm_nts_0,	/* 62 */
};

char burm_arity[] = {
	0,	/* 0 */
	0,	/* 1=FUNC */
	1,	/* 2=RET */
	0,	/* 3=CONST */
	2,	/* 4=ADD */
	2,	/* 5=SUB */
	2,	/* 6=MUL */
	0,	/* 7=VARI */
	2,	/* 8=ARR_DEREF */
	1,	/* 9=VARDEF */
	2,	/* 10=VASSIGN */
	0,	/* 11 */
	2,	/* 12=LOR */
	2,	/* 13=LNEQ */
	2,	/* 14=LLESS */
	1,	/* 15=LNOT */
};

static short burm_decode_stat[] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
};

static short burm_decode_retexpr[] = {
	0,
	14,
	15,
	16,
};

static short burm_decode_vdefexpr[] = {
	0,
	11,
	12,
	13,
};

static short burm_decode_retvar[] = {
	0,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
	51,
	52,
	53,
	54,
	55,
	56,
	57,
	58,
};

static short burm_decode_retcon[] = {
	0,
	59,
	60,
	61,
	62,
};

static short burm_decode_retarr[] = {
	0,
	25,
	26,
	27,
	28,
};

static short burm_decode_bterm[] = {
	0,
	17,
	18,
	19,
};

static short burm_decode_bbasic[] = {
	0,
	20,
	21,
};

static short burm_decode_bexpr[] = {
	0,
	22,
	23,
	24,
};

static short burm_decode_arrv[] = {
	0,
	33,
};

static short burm_decode_arrd[] = {
	0,
	29,
	30,
	31,
	32,
};

int burm_rule(STATEPTR_TYPE state, int goalnt) {
	burm_assert(goalnt >= 1 && goalnt <= 11, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	if (!state)
		return 0;
	switch (goalnt) {
	case burm_stat_NT:
		return burm_decode_stat[state->rule.burm_stat];
	case burm_retexpr_NT:
		return burm_decode_retexpr[state->rule.burm_retexpr];
	case burm_vdefexpr_NT:
		return burm_decode_vdefexpr[state->rule.burm_vdefexpr];
	case burm_retvar_NT:
		return burm_decode_retvar[state->rule.burm_retvar];
	case burm_retcon_NT:
		return burm_decode_retcon[state->rule.burm_retcon];
	case burm_retarr_NT:
		return burm_decode_retarr[state->rule.burm_retarr];
	case burm_bterm_NT:
		return burm_decode_bterm[state->rule.burm_bterm];
	case burm_bbasic_NT:
		return burm_decode_bbasic[state->rule.burm_bbasic];
	case burm_bexpr_NT:
		return burm_decode_bexpr[state->rule.burm_bexpr];
	case burm_arrv_NT:
		return burm_decode_arrv[state->rule.burm_arrv];
	case burm_arrd_NT:
		return burm_decode_arrd[state->rule.burm_arrd];
	default:
		burm_assert(0, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	}
	return 0;
}

static void burm_closure_retvar(STATEPTR_TYPE, int);
static void burm_closure_retcon(STATEPTR_TYPE, int);
static void burm_closure_retarr(STATEPTR_TYPE, int);
static void burm_closure_bterm(STATEPTR_TYPE, int);
static void burm_closure_bbasic(STATEPTR_TYPE, int);

static void burm_closure_retvar(STATEPTR_TYPE p, int c) {
	if (c + 1 < p->cost[burm_bexpr_NT]) {
		p->cost[burm_bexpr_NT] = c + 1;
		p->rule.burm_bexpr = 2;
	}
	if (c + 1 < p->cost[burm_retexpr_NT]) {
		p->cost[burm_retexpr_NT] = c + 1;
		p->rule.burm_retexpr = 2;
	}
	if (c + 2 < p->cost[burm_vdefexpr_NT]) {
		p->cost[burm_vdefexpr_NT] = c + 2;
		p->rule.burm_vdefexpr = 2;
	}
}

static void burm_closure_retcon(STATEPTR_TYPE p, int c) {
	if (c + 1 < p->cost[burm_bexpr_NT]) {
		p->cost[burm_bexpr_NT] = c + 1;
		p->rule.burm_bexpr = 1;
	}
	if (c + 1 < p->cost[burm_retexpr_NT]) {
		p->cost[burm_retexpr_NT] = c + 1;
		p->rule.burm_retexpr = 1;
	}
	if (c + 1 < p->cost[burm_vdefexpr_NT]) {
		p->cost[burm_vdefexpr_NT] = c + 1;
		p->rule.burm_vdefexpr = 1;
	}
}

static void burm_closure_retarr(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_bexpr_NT]) {
		p->cost[burm_bexpr_NT] = c + 0;
		p->rule.burm_bexpr = 3;
	}
	if (c + 1 < p->cost[burm_retexpr_NT]) {
		p->cost[burm_retexpr_NT] = c + 1;
		p->rule.burm_retexpr = 3;
	}
	if (c + 2 < p->cost[burm_vdefexpr_NT]) {
		p->cost[burm_vdefexpr_NT] = c + 2;
		p->rule.burm_vdefexpr = 3;
	}
}

static void burm_closure_bterm(STATEPTR_TYPE p, int c) {
	if (c + 1 < p->cost[burm_stat_NT]) {
		p->cost[burm_stat_NT] = c + 1;
		p->rule.burm_stat = 10;
	}
}

static void burm_closure_bbasic(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_bterm_NT]) {
		p->cost[burm_bterm_NT] = c + 0;
		p->rule.burm_bterm = 1;
		burm_closure_bterm(p, c + 0);
	}
}

STATEPTR_TYPE burm_state(int op, STATEPTR_TYPE left, STATEPTR_TYPE right) {
	int c;
	STATEPTR_TYPE p, l = left, r = right;

	if (burm_arity[op] > 0) {
		p = (STATEPTR_TYPE)ALLOC(sizeof *p);
		burm_assert(p, PANIC("ALLOC returned NULL in burm_state\n"));
		p->op = op;
		p->left = l;
		p->right = r;
		p->rule.burm_stat = 0;
		p->cost[1] =
		p->cost[2] =
		p->cost[3] =
		p->cost[4] =
		p->cost[5] =
		p->cost[6] =
		p->cost[7] =
		p->cost[8] =
		p->cost[9] =
		p->cost[10] =
		p->cost[11] =
			32767;
	}
	switch (op) {
	case 1: /* FUNC */
		{
			static struct burm_state z = { 1, 0, 0,
				{	0,
					0,	/* stat: FUNC */
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					1,	/* stat: FUNC */
					0,
					0,
					0,
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 2: /* RET */
		assert(l);
		{	/* stat: RET(retexpr) */
			c = l->cost[burm_retexpr_NT] + 1;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 2;
			}
		}
		break;
	case 3: /* CONST */
		{
			static struct burm_state z = { 3, 0, 0,
				{	0,
					32767,
					1,	/* retexpr: retcon */
					1,	/* vdefexpr: retcon */
					32767,
					0,	/* retcon: CONST */
					32767,
					32767,
					32767,
					1,	/* bexpr: retcon */
					32767,
					32767,
				},{
					0,
					1,	/* retexpr: retcon */
					1,	/* vdefexpr: retcon */
					0,
					4,	/* retcon: CONST */
					0,
					0,
					0,
					1,	/* bexpr: retcon */
					0,
					0,
				}
			};
			return &z;
		}
	case 4: /* ADD */
		assert(l && r);
		{	/* retcon: ADD(retcon,retcon) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retcon_NT] + 0;
			if (c + 0 < p->cost[burm_retcon_NT]) {
				p->cost[burm_retcon_NT] = c + 0;
				p->rule.burm_retcon = 1;
				burm_closure_retcon(p, c + 0);
			}
		}
		{	/* retvar: ADD(retarr,retarr) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 8;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retcon,retarr) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 7;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retarr,retcon) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 6;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retvar,retarr) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 5;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retarr,retvar) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 4;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retcon,retvar) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 3;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retvar,retcon) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 2;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: ADD(retvar,retvar) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 1;
				burm_closure_retvar(p, c + 0);
			}
		}
		break;
	case 5: /* SUB */
		assert(l && r);
		{	/* retcon: SUB(retcon,retcon) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retcon_NT] + 0;
			if (c + 0 < p->cost[burm_retcon_NT]) {
				p->cost[burm_retcon_NT] = c + 0;
				p->rule.burm_retcon = 2;
				burm_closure_retcon(p, c + 0);
			}
		}
		{	/* retvar: SUB(retarr,retarr) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 16;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retcon,retarr) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 15;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retarr,retcon) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 14;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retvar,retarr) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 13;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retarr,retvar) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 12;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retcon,retvar) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 11;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retvar,retcon) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 10;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: SUB(retvar,retvar) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 9;
				burm_closure_retvar(p, c + 0);
			}
		}
		break;
	case 6: /* MUL */
		assert(l && r);
		{	/* retcon: MUL(retcon,retcon) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retcon_NT] + 0;
			if (c + 0 < p->cost[burm_retcon_NT]) {
				p->cost[burm_retcon_NT] = c + 0;
				p->rule.burm_retcon = 3;
				burm_closure_retcon(p, c + 0);
			}
		}
		{	/* retvar: MUL(retarr,retarr) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 24;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retcon,retarr) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 23;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retarr,retcon) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 22;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retvar,retarr) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 21;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retarr,retvar) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 20;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retcon,retvar) */
			c = l->cost[burm_retcon_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 19;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retvar,retcon) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retcon_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 18;
				burm_closure_retvar(p, c + 0);
			}
		}
		{	/* retvar: MUL(retvar,retvar) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_retvar_NT]) {
				p->cost[burm_retvar_NT] = c + 0;
				p->rule.burm_retvar = 17;
				burm_closure_retvar(p, c + 0);
			}
		}
		break;
	case 7: /* VARI */
		{
			static struct burm_state z = { 7, 0, 0,
				{	0,
					32767,
					1,	/* retexpr: retvar */
					2,	/* vdefexpr: retvar */
					0,	/* retvar: VARI */
					32767,
					32767,
					32767,
					32767,
					1,	/* bexpr: retvar */
					0,	/* arrv: VARI */
					32767,
				},{
					0,
					2,	/* retexpr: retvar */
					2,	/* vdefexpr: retvar */
					25,	/* retvar: VARI */
					0,
					0,
					0,
					0,
					2,	/* bexpr: retvar */
					1,	/* arrv: VARI */
					0,
				}
			};
			return &z;
		}
	case 8: /* ARR_DEREF */
		assert(l && r);
		{	/* arrd: ARR_DEREF(arrv,retcon) */
			c = l->cost[burm_arrv_NT] + r->cost[burm_retcon_NT] + 3;
			if (c + 0 < p->cost[burm_arrd_NT]) {
				p->cost[burm_arrd_NT] = c + 0;
				p->rule.burm_arrd = 4;
			}
		}
		{	/* arrd: ARR_DEREF(arrv,retvar) */
			c = l->cost[burm_arrv_NT] + r->cost[burm_retvar_NT] + 3;
			if (c + 0 < p->cost[burm_arrd_NT]) {
				p->cost[burm_arrd_NT] = c + 0;
				p->rule.burm_arrd = 3;
			}
		}
		{	/* arrd: ARR_DEREF(arrd,retcon) */
			c = l->cost[burm_arrd_NT] + r->cost[burm_retcon_NT] + 3;
			if (c + 0 < p->cost[burm_arrd_NT]) {
				p->cost[burm_arrd_NT] = c + 0;
				p->rule.burm_arrd = 2;
			}
		}
		{	/* arrd: ARR_DEREF(arrd,retvar) */
			c = l->cost[burm_arrd_NT] + r->cost[burm_retvar_NT] + 3;
			if (c + 0 < p->cost[burm_arrd_NT]) {
				p->cost[burm_arrd_NT] = c + 0;
				p->rule.burm_arrd = 1;
			}
		}
		{	/* retarr: ARR_DEREF(arrd,retcon) */
			c = l->cost[burm_arrd_NT] + r->cost[burm_retcon_NT] + 3;
			if (c + 0 < p->cost[burm_retarr_NT]) {
				p->cost[burm_retarr_NT] = c + 0;
				p->rule.burm_retarr = 4;
				burm_closure_retarr(p, c + 0);
			}
		}
		{	/* retarr: ARR_DEREF(arrd,retvar) */
			c = l->cost[burm_arrd_NT] + r->cost[burm_retvar_NT] + 3;
			if (c + 0 < p->cost[burm_retarr_NT]) {
				p->cost[burm_retarr_NT] = c + 0;
				p->rule.burm_retarr = 3;
				burm_closure_retarr(p, c + 0);
			}
		}
		{	/* retarr: ARR_DEREF(arrv,retcon) */
			c = l->cost[burm_arrv_NT] + r->cost[burm_retcon_NT] + 3;
			if (c + 0 < p->cost[burm_retarr_NT]) {
				p->cost[burm_retarr_NT] = c + 0;
				p->rule.burm_retarr = 2;
				burm_closure_retarr(p, c + 0);
			}
		}
		{	/* retarr: ARR_DEREF(arrv,retvar) */
			c = l->cost[burm_arrv_NT] + r->cost[burm_retvar_NT] + 3;
			if (c + 0 < p->cost[burm_retarr_NT]) {
				p->cost[burm_retarr_NT] = c + 0;
				p->rule.burm_retarr = 1;
				burm_closure_retarr(p, c + 0);
			}
		}
		break;
	case 9: /* VARDEF */
		assert(l);
		{	/* stat: VARDEF(vdefexpr) */
			c = l->cost[burm_vdefexpr_NT] + 0;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 3;
			}
		}
		break;
	case 10: /* VASSIGN */
		assert(l && r);
		{	/* stat: VASSIGN(retarr,retarr) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retarr_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 9;
			}
		}
		{	/* stat: VASSIGN(retarr,retvar) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 8;
			}
		}
		{	/* stat: VASSIGN(retarr,retcon) */
			c = l->cost[burm_retarr_NT] + r->cost[burm_retcon_NT] + 1;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 7;
			}
		}
		{	/* stat: VASSIGN(retvar,retarr) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retarr_NT] + 1;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 6;
			}
		}
		{	/* stat: VASSIGN(retvar,retvar) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retvar_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 5;
			}
		}
		{	/* stat: VASSIGN(retvar,retcon) */
			c = l->cost[burm_retvar_NT] + r->cost[burm_retcon_NT] + 1;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 4;
			}
		}
		break;
	case 12: /* LOR */
		assert(l && r);
		{	/* bterm: LOR(bterm,bterm) */
			c = l->cost[burm_bterm_NT] + r->cost[burm_bterm_NT] + 0;
			if (c + 0 < p->cost[burm_bterm_NT]) {
				p->cost[burm_bterm_NT] = c + 0;
				p->rule.burm_bterm = 3;
				burm_closure_bterm(p, c + 0);
			}
		}
		break;
	case 13: /* LNEQ */
		assert(l && r);
		{	/* bbasic: LNEQ(bexpr,bexpr) */
			c = l->cost[burm_bexpr_NT] + r->cost[burm_bexpr_NT] + 2;
			if (c + 0 < p->cost[burm_bbasic_NT]) {
				p->cost[burm_bbasic_NT] = c + 0;
				p->rule.burm_bbasic = 2;
				burm_closure_bbasic(p, c + 0);
			}
		}
		break;
	case 14: /* LLESS */
		assert(l && r);
		{	/* bbasic: LLESS(bexpr,bexpr) */
			c = l->cost[burm_bexpr_NT] + r->cost[burm_bexpr_NT] + 2;
			if (c + 0 < p->cost[burm_bbasic_NT]) {
				p->cost[burm_bbasic_NT] = c + 0;
				p->rule.burm_bbasic = 1;
				burm_closure_bbasic(p, c + 0);
			}
		}
		break;
	case 15: /* LNOT */
		assert(l);
		{	/* bterm: LNOT(bterm) */
			c = l->cost[burm_bterm_NT] + 0;
			if (c + 0 < p->cost[burm_bterm_NT]) {
				p->cost[burm_bterm_NT] = c + 0;
				p->rule.burm_bterm = 2;
				burm_closure_bterm(p, c + 0);
			}
		}
		break;
	default:
		burm_assert(0, PANIC("Bad operator %d in burm_state\n", op));
	}
	return p;
}

#ifdef STATE_LABEL
static void burm_label1(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_label\n"));
	switch (burm_arity[OP_LABEL(p)]) {
	case 0:
		STATE_LABEL(p) = burm_state(OP_LABEL(p), 0, 0);
		break;
	case 1:
		burm_label1(LEFT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)), 0);
		break;
	case 2:
		burm_label1(LEFT_CHILD(p));
		burm_label1(RIGHT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)),
			STATE_LABEL(RIGHT_CHILD(p)));
		break;
	}
}

STATEPTR_TYPE burm_label(NODEPTR_TYPE p) {
	burm_label1(p);
	return STATE_LABEL(p)->rule.burm_stat ? STATE_LABEL(p) : 0;
}

NODEPTR_TYPE *burm_kids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	burm_assert(p, PANIC("NULL tree in burm_kids\n"));
	burm_assert(kids, PANIC("NULL kids in burm_kids\n"));
	switch (eruleno) {
	case 62: /* retcon: CONST */
	case 58: /* retvar: VARI */
	case 33: /* arrv: VARI */
	case 1: /* stat: FUNC */
		break;
	case 18: /* bterm: LNOT(bterm) */
	case 3: /* stat: VARDEF(vdefexpr) */
	case 2: /* stat: RET(retexpr) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 61: /* retcon: MUL(retcon,retcon) */
	case 60: /* retcon: SUB(retcon,retcon) */
	case 59: /* retcon: ADD(retcon,retcon) */
	case 57: /* retvar: MUL(retarr,retarr) */
	case 56: /* retvar: MUL(retcon,retarr) */
	case 55: /* retvar: MUL(retarr,retcon) */
	case 54: /* retvar: MUL(retvar,retarr) */
	case 53: /* retvar: MUL(retarr,retvar) */
	case 52: /* retvar: MUL(retcon,retvar) */
	case 51: /* retvar: MUL(retvar,retcon) */
	case 50: /* retvar: MUL(retvar,retvar) */
	case 49: /* retvar: SUB(retarr,retarr) */
	case 48: /* retvar: SUB(retcon,retarr) */
	case 47: /* retvar: SUB(retarr,retcon) */
	case 46: /* retvar: SUB(retvar,retarr) */
	case 45: /* retvar: SUB(retarr,retvar) */
	case 44: /* retvar: SUB(retcon,retvar) */
	case 43: /* retvar: SUB(retvar,retcon) */
	case 42: /* retvar: SUB(retvar,retvar) */
	case 41: /* retvar: ADD(retarr,retarr) */
	case 40: /* retvar: ADD(retcon,retarr) */
	case 39: /* retvar: ADD(retarr,retcon) */
	case 38: /* retvar: ADD(retvar,retarr) */
	case 37: /* retvar: ADD(retarr,retvar) */
	case 36: /* retvar: ADD(retcon,retvar) */
	case 35: /* retvar: ADD(retvar,retcon) */
	case 34: /* retvar: ADD(retvar,retvar) */
	case 32: /* arrd: ARR_DEREF(arrv,retcon) */
	case 31: /* arrd: ARR_DEREF(arrv,retvar) */
	case 30: /* arrd: ARR_DEREF(arrd,retcon) */
	case 29: /* arrd: ARR_DEREF(arrd,retvar) */
	case 28: /* retarr: ARR_DEREF(arrd,retcon) */
	case 27: /* retarr: ARR_DEREF(arrd,retvar) */
	case 26: /* retarr: ARR_DEREF(arrv,retcon) */
	case 25: /* retarr: ARR_DEREF(arrv,retvar) */
	case 21: /* bbasic: LNEQ(bexpr,bexpr) */
	case 20: /* bbasic: LLESS(bexpr,bexpr) */
	case 19: /* bterm: LOR(bterm,bterm) */
	case 9: /* stat: VASSIGN(retarr,retarr) */
	case 8: /* stat: VASSIGN(retarr,retvar) */
	case 7: /* stat: VASSIGN(retarr,retcon) */
	case 6: /* stat: VASSIGN(retvar,retarr) */
	case 5: /* stat: VASSIGN(retvar,retvar) */
	case 4: /* stat: VASSIGN(retvar,retcon) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 24: /* bexpr: retarr */
	case 23: /* bexpr: retvar */
	case 22: /* bexpr: retcon */
	case 17: /* bterm: bbasic */
	case 16: /* retexpr: retarr */
	case 15: /* retexpr: retvar */
	case 14: /* retexpr: retcon */
	case 13: /* vdefexpr: retarr */
	case 12: /* vdefexpr: retvar */
	case 11: /* vdefexpr: retcon */
	case 10: /* stat: bterm */
		kids[0] = p;
		break;
	default:
		burm_assert(0, PANIC("Bad external rule number %d in burm_kids\n", eruleno));
	}
	return kids;
}

int burm_op_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_op_label\n"));
	return OP_LABEL(p);
}

STATEPTR_TYPE burm_state_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_state_label\n"));
	return STATE_LABEL(p);
}

NODEPTR_TYPE burm_child(NODEPTR_TYPE p, int index) {
	burm_assert(p, PANIC("NULL tree in burm_child\n"));
	switch (index) {
	case 0:	return LEFT_CHILD(p);
	case 1:	return RIGHT_CHILD(p);
	}
	burm_assert(0, PANIC("Bad index %d in burm_child\n", index));
	return 0;
}

#endif
void burm_reduce(NODEPTR_TYPE bnode, int goalnt)
{
  int ruleNo = burm_rule (STATE_LABEL(bnode), goalnt);
  short *nts = burm_nts[ruleNo];
  NODEPTR_TYPE kids[100];
  int i;

  if (ruleNo==0) {
    fprintf(stderr, "tree cannot be derived from start symbol");
    exit(1);
  }
  burm_kids (bnode, ruleNo, kids);
  for (i = 0; nts[i]; i++)
    burm_reduce (kids[i], nts[i]);    /* reduce kids */

#if DEBUG
  printf ("%s", burm_string[ruleNo]);  /* display rule */
#endif

  switch (ruleNo) {
  case 10:
 { printf("\tjmp "); bfePrintEnd(bnode,bnode->labelnr,bnode->ifnr,bnode->belseav); NL  bfe_nextReg = 0; NL }
    break;
  case 11:
 { MOVC(bnode->number, bfeGetNextVarReg(bnode->memt)) }
    break;
  case 12:
 { BFE_DEF_TMP MOVV(bnode->reg, r) MOVV(r, bfeGetNextVarReg(bnode->memt)) }
    break;
  case 13:
 { BFE_DEF_TMP MOVV(bnode->reg, r) MOVM(r, bfeGetNextVarReg(bnode->memt)) }
    break;
  case 14:
 { MOVC(bnode->number, REG_RET) }
    break;
  case 15:
 { if(strcmp(bnode->reg, REG_RET) != 0) { MOVV(bnode->reg, REG_RET) } }
    break;
  case 16:
 { MOVM(bnode->reg, REG_RET) } 
    break;
  case 30:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULC(8,r) ADDM(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 17:
 ;
    break;
  case 31:
 { BFE_NEXT_REG MOVV(RIGHT_CHILD(bnode)->reg, r) MULC(8, r) ADDV(LEFT_CHILD(bnode)->reg, r)  }
    break;
  case 18:
 ;
    break;
  case 32:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULC(8,r) ADDV(LEFT_CHILD(bnode)->reg, r)  } 
    break;
  case 19:
 { printf("\tjmp "); bfePrintEnd(bnode,bnode->labelnr,bnode->ifnr,bnode->belseav); NL printf(".Z%d:\n", bnode->labelnr); NL } ;
    break;
  case 33:
 bnode->reg = bfeGetVarReg(bnode->id, bnode->memt);
    break;
  case 34:
 { BFE_NEXT_REG MOVV(LEFT_CHILD(bnode)->reg, r) ADDV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 35:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) ADDV(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 36:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) ADDV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 50:
 { BFE_NEXT_REG MOVV(LEFT_CHILD(bnode)->reg, r) MULV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 37:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) ADDV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 51:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULV(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 38:
 { BFE_NEXT_REG MOVM(RIGHT_CHILD(bnode)->reg, r) ADDV(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 52:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) MULV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 39:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) ADDM(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 53:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) MULV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 54:
 { BFE_NEXT_REG MOVM(RIGHT_CHILD(bnode)->reg, r) MULV(LEFT_CHILD(bnode)->reg, r) } 
    break;
  case 55:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULM(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 56:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) MULM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 1:
 FUNC_PROLOG(bnode->id) bfeSaveParamsToMem(bnode->memt); NL bfe_nextReg = 0; 
    break;
  case 57:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) MULM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 2:
 FUNC_EPILOG NL bfe_nextReg = 0;
    break;
  case 58:
 bnode->reg = bfeGetVarReg(bnode->id, bnode->memt);
    break;
  case 3:
 NL bfe_nextReg = 0;
    break;
  case 59:
 bnode->number = LEFT_CHILD(bnode)->number + RIGHT_CHILD(bnode)->number;
    break;
  case 4:
 { MOVC(RIGHT_CHILD(bnode)->number, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL }
    break;
  case 5:
 { BFE_NEXT_REG MOVV(RIGHT_CHILD(bnode)->reg, r) MOVV(r, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL }
    break;
  case 6:
 { MOVAM(RIGHT_CHILD(bnode)->reg, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL }
    break;
  case 7:
 { MOVAC(RIGHT_CHILD(bnode)->number, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL } 
    break;
  case 8:
 { BFE_DEF_TMP MOVV(RIGHT_CHILD(bnode)->reg, r) MOVAV(r, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL }
    break;
  case 9:
 { BFE_DEF_TMP MOVM(RIGHT_CHILD(bnode)->reg, r) MOVAV(r, LEFT_CHILD(bnode)->reg) bfe_nextReg = 0; NL }
    break;
  case 20:
 { CMP(RIGHT_CHILD(bnode)->reg, LEFT_CHILD(bnode)->reg) printf("\tjl "); bfePrintStart(bnode,bnode->labelnr,bnode->ifnr,bnode->belseav); NL  }
    break;
  case 21:
 { CMP(RIGHT_CHILD(bnode)->reg, LEFT_CHILD(bnode)->reg) printf("\tjne "); bfePrintStart(bnode,bnode->labelnr,bnode->ifnr,bnode->belseav); NL  }
    break;
  case 22:
 { BFE_NEXT_REG MOVC(bnode->number, r) }
    break;
  case 23:
 { BFE_DEF_TMP MOVV(bnode->reg,r) bnode->reg = r; } ;
    break;
  case 24:
 { char *r = malloc(strlen(bnode->reg)+3); sprintf(r, "(%s)", bnode->reg); bnode->reg = r; }
    break;
  case 25:
 { BFE_NEXT_REG MOVV(RIGHT_CHILD(bnode)->reg, r) MULC(8, r) ADDV(LEFT_CHILD(bnode)->reg, r)  }
    break;
  case 26:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULC(8,r) ADDV(LEFT_CHILD(bnode)->reg, r)  }
    break;
  case 40:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) ADDM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 27:
 { BFE_NEXT_REG MOVV(RIGHT_CHILD(bnode)->reg, r) MULC(8, r) ADDM(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 41:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) ADDM(RIGHT_CHILD(bnode)->reg, r) } 
    break;
  case 28:
 { BFE_NEXT_REG MOVC(RIGHT_CHILD(bnode)->number, r) MULC(8,r) ADDM(LEFT_CHILD(bnode)->reg, r)  }
    break;
  case 42:
 { BFE_NEXT_REG MOVV(LEFT_CHILD(bnode)->reg, r) SUBV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 29:
 { BFE_NEXT_REG MOVV(RIGHT_CHILD(bnode)->reg, r) MULC(8, r) ADDM(LEFT_CHILD(bnode)->reg, r) }
    break;
  case 43:
 { BFE_NEXT_REG MOVV(LEFT_CHILD(bnode)->reg, r) SUBC(RIGHT_CHILD(bnode)->number, r) }
    break;
  case 44:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) SUBV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 45:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) SUBV(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 46:
 { BFE_NEXT_REG MOVV(LEFT_CHILD(bnode)->reg, r) SUBM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 60:
 bnode->number = LEFT_CHILD(bnode)->number - RIGHT_CHILD(bnode)->number; 
    break;
  case 47:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) SUBC(RIGHT_CHILD(bnode)->number, r) }
    break;
  case 61:
 bnode->number = LEFT_CHILD(bnode)->number * RIGHT_CHILD(bnode)->number; 
    break;
  case 48:
 { BFE_NEXT_REG MOVC(LEFT_CHILD(bnode)->number, r) SUBM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  case 62:
 ; 
    break;
  case 49:
 { BFE_NEXT_REG MOVM(LEFT_CHILD(bnode)->reg, r) SUBM(RIGHT_CHILD(bnode)->reg, r) }
    break;
  default:    assert (0);
  }
}
