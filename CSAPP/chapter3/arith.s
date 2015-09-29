	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_arith
	.align	4, 0x90
_arith:                                 ## @arith
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	movzwl	%ax, %eax
	imull	16(%ebp), %eax
	imull	 $48, %eax
	popl	%ebp
	retl


.subsections_via_symbols
