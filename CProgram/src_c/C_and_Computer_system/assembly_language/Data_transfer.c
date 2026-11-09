void proc(long a1, long a2, long a3, long a4,
        long* a5, long* a6, long* b1, long* b2){
            *a5 += a1;
            *a6 += a2;
            *b1 += a3;
            *b2 += a4;
}
/*
proc:
	movq	%rdi, %r10
	movq	%rsi, %rdi
	movq	%rdx, %rsi
    //可以发现当函数的参数超过 6 个时（多余寄存器的数量）就会使用栈空间来传递
    //%rsp 是栈顶指针，用于记录栈顶的语句的地址
	movq	8(%rsp), %rdx
	movq	16(%rsp), %rax
	addq	%r10, (%r8)
	addq	%rdi, (%r9)
	addq	%rsi, (%rdx)
	addq	%rcx, (%rax)
	ret
*/