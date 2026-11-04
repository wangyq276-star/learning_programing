/*
imulq 和 idivlq 是可以进行结果为 128 位的乘法和除法指令
但是结果只能保存再寄存器 %rdx（高 64 位） 和 %rax（低 64 位）中

由于本机的 Windows 的 MinGW32 可能不支持 __int128 所以生成的汇编语言是空的
尽量使用 Linux 进行编译
*/
#include<inttypes.h>

typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t* dest, uint64_t x, uint64_t y){
    *dest = x * (uint128_t) y;
    //这一步需要强制转换，不然结果就是 64 位的，而不是我们想要的 128 位
}