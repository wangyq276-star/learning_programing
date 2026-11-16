	.file	"Data_transfer.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	endbr64
	movq	%rdi, %r10
	movq	%rsi, %rdi
	movq	%rdx, %rsi
	movq	8(%rsp), %rdx
	movq	16(%rsp), %rax
	addq	%r10, (%r8)
	addq	%rdi, (%r9)
	addq	%rsi, (%rdx)
	addq	%rcx, (%rax)
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
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
