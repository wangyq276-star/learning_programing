	.file	"Leaq_command.c"
	.text
	.globl	scale2
	.def	scale2;	.scl	2;	.type	32;	.endef
	.seh_proc	scale2
scale2:
	.seh_endprologue
	leal	(%rcx,%rcx,4), %eax
	leal	(%rax,%rdx,2), %eax
	leal	(%rax,%r8,8), %eax
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
