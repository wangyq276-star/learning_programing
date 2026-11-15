long absdiff(long x, long y){
    long res;
    if (x < y){
        res = y - x;
    }else{
        res = x - y;
    }
    return res;
}
/*
汇编代码：

absdiff:
	movq	%rsi, %rdx
	subq	%rdi, %rdx
	movq	%rdi, %rax
	subq	%rsi, %rax
	cmpq	%rsi, %rdi
	cmovl	%rdx, %rax
	ret

使用 cmov 指令来实现条件数据传送，在某些时候可以比条件控制传送（cmp 和 jp 指令）性能更好
*/