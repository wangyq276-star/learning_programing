/*
使用 extern 关键字主要是为了防止编译器在生成汇编语言时把未使用函数优化掉
便于观察结果
*/

extern long mult2(long, long);

extern void multstore(long x, long y, long* dest){
    long t = mult2(x, y);
    *dest = t;
}