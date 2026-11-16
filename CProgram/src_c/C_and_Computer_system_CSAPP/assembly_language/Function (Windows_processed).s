#这是基于 Windows 系统的 gcc 处理得到的一个汇编语言文本文件
#所有以 '.' 开头的行都是伪指令，用于指导编译器与链接器的工作
	.file	"Assembly_language.c"
	.text
	.globl	multstore
	.def	multstore;	.scl	2;	.type	32;	.endef
	.seh_proc	multstore
multstore:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%r8, %rbx
	call	mult2
	movl	%eax, (%rbx)
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	mult2;	.scl	2;	.type	32;	.endef
