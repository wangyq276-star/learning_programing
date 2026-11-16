#define M 5
#define N 7

long P[M][N], Q[N][M];

long sum_element(long i, long j) { return P[i][j] + Q[j][i]; }

/*
汇编代码

leaq	0(,%rdi,8), %rdx
subq	%rdi, %rdx
addq	%rsi, %rdx
leaq	(%rsi,%rsi,4), %rax
addq	%rdi, %rax
movq	Q(,%rax,8), %rax
addq	P(,%rdx,8), %rax
ret

（注意：因为现代 Linux（比如 WSL Ubuntu）默认开启了一种叫
PIE（位置无关可执行文件） 的安全机制。 为了防黑客（ASLR
地址随机化），程序每次运行时，全局变量 P 和 Q 的绝对地址都是随机的。
所以编译器不能写死绝对地址，必须先通过 %rip 加上一个偏移量，动态算出 P 和 Q
在哪，然后再去访问。 这使得汇编代码不够直观，因此使用：
    gcc -O1 -S -fno-pie -no-pie 2Darray_access.c
关闭安全机制可以获得与书上相同的代码
*/