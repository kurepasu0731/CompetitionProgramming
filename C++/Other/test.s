	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_print_oniku
	.align	4, 0x90
_print_oniku:                           ## @print_oniku
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
	subq	$48, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	cmpl	$2, -36(%rbp)
	jne	LBB0_3
## BB#1:
	cmpl	$9, -40(%rbp)
	jne	LBB0_3
## BB#2:
	leaq	L_.str(%rip), %rdi
	leaq	-31(%rbp), %rdx
	leaq	-18(%rbp), %rsi
	movq	L_print_oniku.oniku(%rip), %rax
	movq	%rax, -18(%rbp)
	movw	L_print_oniku.oniku+8(%rip), %cx
	movw	%cx, -10(%rbp)
	movq	L_print_oniku.tabetai(%rip), %rax
	movq	%rax, -31(%rbp)
	movl	L_print_oniku.tabetai+8(%rip), %r8d
	movl	%r8d, -23(%rbp)
	movb	L_print_oniku.tabetai+12(%rip), %r9b
	movb	%r9b, -19(%rbp)
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
LBB0_3:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB0_5
## BB#4:                                ## %SP_return
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_5:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str1(%rip), %rdi
	leaq	-8(%rbp), %rsi
	leaq	-12(%rbp), %rdx
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_scanf
	movl	-8(%rbp), %edi
	movl	-12(%rbp), %esi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_print_oniku
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_print_oniku.oniku:                    ## @print_oniku.oniku
	.asciz	"\343\201\212\343\201\253\343\201\217"

L_print_oniku.tabetai:                  ## @print_oniku.tabetai
	.asciz	"\343\201\237\343\201\271\343\201\237\343\201\204"

L_.str:                                 ## @.str
	.asciz	"%s%s\n"

L_.str1:                                ## @.str1
	.asciz	"%d %d"


.subsections_via_symbols
