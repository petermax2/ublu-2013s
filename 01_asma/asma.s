	.text
.globl asma
	.type	test, @function
asma:
.LFB0:
	# Prolog der Funktion
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6

	# Register und Speicherbelegung
	# %rdi		q 64 bit	char *s - Adresse zum String
	# %eax		l 32 bit	int c - Return-Wert
	# %xmm0		dq 128 bit	enthaelt den 16-byte langen String
	# %xmm1		dq 128 bit	enthaelt Bitmakse zum Vergleich
	# -16(%rbp)	dq 128 bit	zum Aufbau der Bitmaske

	movl	$0x20202020, -16(%rbp)	# Bitmaske aufbauen und ins SSE-Register XMM1 laden
	movl	$0x20202020, -12(%rbp)
	movl	$0x20202020, -8(%rbp)
	movl	$0x20202020, -4(%rbp)
	movdqa	-16(%rbp), %xmm1

	movdqu  (%rdi), %xmm0		# String-Argument in XMM0 laden
	pcmpeqb	%xmm0, %xmm1		# Treffer ermitteln ( 00 -> miss | FF -> hit )
	pmovmskb	%xmm1, %rax
	popcnt	%rax, %eax
	
	# Epilog der Funktion
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Debian 4.4.5-8) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
