#include <stdio.h>

// 这是一个正常的、不应该被调用的函数
void secret_function() {
    printf("\n[!!!] 成功劫持控制流！你调用了 secret_function! \n");
    printf("这就是栈溢出攻击的威力。\n");
}

// 这是一个存在缓冲区溢出漏洞的函数
void vulnerable_function() {
    char buffer[10]; // 只有 10 个字节的缓冲区
    printf("请输入一些文本: ");

    // gets() 是极其危险的函数，它不检查输入长度，会一直读直到遇到换行
    gets(buffer);

    printf("你输入了: %s\n", buffer);
}

int main() {
    vulnerable_function();
    printf("正常返回 main 函数。\n");
    return 0;
}