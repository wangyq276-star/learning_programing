long fact_do(long n){
    long res = 1;
    do{
        res *= n;
        n = n - 1;

    }while (n > 1);
    return res;
}
/*
汇编代码：

fact_do:
	movl	$1, %eax
.L2:
	imulq	%rdi, %rax
	subq	$1, %rdi
	cmpq	$1, %rdi
	jg	.L2
	ret

采用标签 L2 和 jp cmp 指令来达到循环的实现
*/