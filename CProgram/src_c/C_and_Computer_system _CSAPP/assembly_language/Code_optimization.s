	.file	"Code_optimization.c"
	.text
	.globl	loop
	.type	loop, @function
loop:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %rax
	movq	%rdi, %rcx
	imulq	%rdi, %rcx
	leaq	(%rdi,%rdi), %rdx
	.p2align 4
.L2:
	leaq	1(%rcx,%rax), %rax
	subq	$1, %rdx
	testq	%rdx, %rdx
	jg	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	loop, .-loop
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
