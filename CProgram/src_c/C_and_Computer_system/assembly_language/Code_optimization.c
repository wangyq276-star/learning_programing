long loop(long x){
    long y = x * x;
    long* p = &x;
    long n = 2 * x;
    do{
        x += y;
        (*p)++;
        n--;
    }while (n > 0);
    return x;
}
/*
汇编代码：

loop:
	movq	%rdi, %rax
	movq	%rdi, %rcx
	imulq	%rdi, %rcx
	leaq	(%rdi,%rdi), %rdx
.L2:
	leaq	1(%rcx,%rax), %rax
（可以看到它直接通过把 x + y + 1 赋值给 x 来同时执行 x += y 和 (*p)++ 两条语句）
	subq	$1, %rdx
	testq	%rdx, %rdx
	jg	.L2
	ret
*/