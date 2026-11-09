	.file	"Switch.c"
	.text
	.p2align 4
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB0:
	.cfi_startproc
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L8
	jmp	*.L4(,%rsi,8)
	.section	.rodata#声明了这是一个只读数据
	.align 8
	.align 4
.L4:
	.quad	.L7
	.quad	.L8
	.quad	.L6
	.quad	.L5
	.quad	.L3
	.quad	.L8
	.quad	.L3
	.text
	.p2align 4,,10
	.p2align 3
.L3:
	imulq	%rdi, %rdi
	movq	%rdi, (%rdx)
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	addq	$10, %rdi
.L5:
	addq	$11, %rdi
	movq	%rdi, (%rdx)
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	movq	%rdi, (%rdx)
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	xorl	%edi, %edi
	movq	%rdi, (%rdx)
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
