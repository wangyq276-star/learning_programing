	.file	"2Darray_access.c"
	.text
	.globl	sum_element
	.type	sum_element, @function
sum_element:
.LFB0:
	.cfi_startproc
	endbr64
	leaq	0(,%rdi,8), %rdx
	subq	%rdi, %rdx
	addq	%rsi, %rdx
	leaq	(%rsi,%rsi,4), %rax
	addq	%rdi, %rax
	movq	Q(,%rax,8), %rax
	addq	P(,%rdx,8), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	sum_element, .-sum_element
	.globl	Q
	.bss
	.align 32
	.type	Q, @object
	.size	Q, 280
Q:
	.zero	280
	.globl	P
	.align 32
	.type	P, @object
	.size	P, 280
P:
	.zero	280
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
