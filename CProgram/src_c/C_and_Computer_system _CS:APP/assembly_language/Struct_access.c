struct prob {
    int *p;
    struct {
        int x;
        int y;
    } s;
    struct prob *next;
};

void sp_init(struct prob *sp) {
    sp->s.x = sp->s.y;
    sp->p = &sp->s.x;
    sp->next = sp;
}

/*
汇编代码：

movl	12(%rdi), %eax
movl	%eax, 8(%rdi)
leaq	8(%rdi), %rax
movq	%rax, (%rdi)
movq	%rdi, 16(%rdi)
ret

这部分主要在于理解结构体相当于对不同类型元素的打包
这些元素在内存空间中是连续排列的
访问时只需要通过不同元素的对应存储字节大小指定偏移量即可
而结构体的名字对应了该结构体首元素的地址
*/