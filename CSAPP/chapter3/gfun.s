	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_gfun
	.align	4, 0x90
_gfun:                                  ## @gfun
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movslq	%edi, %rax
	movslq	%esi, %rcx
	leaq	(%rcx,%rax), %rdx
	addl	%eax, %ecx
	movslq	%ecx, %rax
	orq	%rdx, %rax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
