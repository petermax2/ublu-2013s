	.text
.globl asmb
	.type   test, @function
asmb:
.LFB0:
	# Prolog der Funktion
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	movq    %rsp, %rbp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6

	# Register und Speicherbelegung
	# %rdi		quad	caller-saved	Startadresse von *s 
	# %rsi		quad	caller-saved	(Teil-)Stringlaenge
	# %rax		quad	caller-saved	Rueckgabewert
	# %r8		quad	caller-saved	Zwischenspeicher
	# %xmm0 	dquad			Bitmaske '0x20...' zum Vergleichen
	# %xmm1		dquad			16B Teil-String
	# -16(%rbp)	dquad			Bitmakse (Aufbau)	

	mov		$0, %rax
	cmp 		$0, %rsi
	je		end

	movl		$0x20202020, -16(%rbp)	# Bitmaske in RAM anlegen
	movl		$0x20202020, -12(%rbp)
	movl		$0x20202020, -8(%rbp)
	movl		$0x20202020, -4(%rbp)
	movdqa  	-16(%rbp), %xmm0

cmploop:
	movdqu		(%rdi), %xmm1

	cmpq 		$16, %rsi
	jge		compare

padding:
	pslldq		$1, %xmm1
	add		$1, %rsi
	cmp 		$16, %rsi
	jl		padding

compare:
	pcmpeqb		%xmm0, %xmm1		# Treffer ermitteln ( 00 -> miss | FF -> hit )
	pmovmskb        %xmm1, %r8
	popcnt		%r8, %r8
	add		%r8, %rax

	add		$16, %rdi
	subq		$16, %rsi
	cmpq		$0, %rsi
	jg		cmploop

end:
	# Epilog der Funktion
	leave
	ret
	.cfi_endproc
.LFE0:
	.size   test, .-test
	.ident  "GCC: (Debian 4.4.5-8) 4.4.5"
	.section        .note.GNU-stack,"",@progbits

