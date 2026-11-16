void switch_eg(long x, long n, long* dest){
    long val = x;

    switch (n){
        case 100:
            val *= 13;
            break;
        
        case 102:
            val += 10;
            //注意，这里没有 break ，也就是说他会一直执行下一个 case 直到找到 break 或执行完 default 为止。
        
        case 103:
            val += 11;
            break;

        case 104:
        case 106:
            val *= val;
            break;

        default:
            val = 0;
    }
    *dest = val;
}
/*
switch_eg:
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L8
	jmp	*.L4(,%rsi,8)
//可以发现汇编器针对switch这种多分支语句生成了跳转表，根据不同的值进行跳转  
	.section	.rodata  //声明了这是一个只读数据  
.L4:
	.quad	.L7
	.quad	.L8
	.quad	.L6
	.quad	.L5
	.quad	.L3
	.quad	.L8
	.quad	.L3
.L3:
	imulq	%rdi, %rdi
	movq	%rdi, (%rdx)
	ret
.L6:
	addq	$10, %rdi
.L5:
	addq	$11, %rdi
	movq	%rdi, (%rdx)
	ret
.L7:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	movq	%rdi, (%rdx)
	ret
.L8:
	xorl	%edi, %edi
	movq	%rdi, (%rdx)
	ret
*/